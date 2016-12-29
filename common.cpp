#include "common.h"
#include "JqServiceHttpBinding.nsmap"
#include "BaseJqServiceHttpBindingProxy.h"
#include "BaseintcommonObject.h"
#include "tinyxml/tinyxml.h"
#include <cmath>
#include <strstream>
//#include <uuid/uuid.h>
#include <curl/curl.h>
#include <pthread.h>
RequestText g_reqText;		//鉴权服务器信息
vector<VedioInfo*> g_vec_Vds;//视频信息
//CRITICAL_SECTION cs;
pthread_mutex_t   mutex_lock;
int uuid=0;
string GetUUID()
{
//	GUID guiid;
//	CoCreateGuid(&guiid);

//	//转换成string
//	char buf[64] = {0};
//	_snprintf_s(buf,sizeof(buf),
//		"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
//		guiid.Data1, guiid.Data2, guiid.Data3,
//		guiid.Data4[0], guiid.Data4[1],
//		guiid.Data4[2], guiid.Data4[3],
//		guiid.Data4[4], guiid.Data4[5],
//		guiid.Data4[6], guiid.Data4[7]);
    //uuid_t uu;
    //uuid_generate(uu);
    uuid ++;
    strstream ss;
    string s;
    ss<<uuid;
    ss>>s;
    return s;//string((char*)uu);
}

std::string MakeReqXml(RequestText * reqText)
{
	/************************************************************************/
	/* 鉴权、配置下载部分XML报文封装                                                  */
	/************************************************************************/
	TiXmlDocument doc;
	//xml文件声明部分
	TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0", "utf-8", "" );
	//把声明和元素添加到文档
	doc.LinkEndChild( decl );
	TiXmlElement * root = new TiXmlElement( "root" );

	//添加新的节点元素
	TiXmlElement * element = new TiXmlElement( "QueryCondition" );
	root->LinkEndChild(element);

	TiXmlElement * elszUser = new TiXmlElement("szUser");
	TiXmlText * xmlTextszUser = new TiXmlText(reqText->strUser.c_str());
	elszUser->LinkEndChild(xmlTextszUser);
	element->LinkEndChild(elszUser);

	TiXmlElement * elszPass = new TiXmlElement("szPass");
	TiXmlText * xmlTextszPass = new TiXmlText(reqText->strPass.c_str());
	elszPass->LinkEndChild(xmlTextszPass);
	element->LinkEndChild(elszPass);

	TiXmlElement * elszUserType = new TiXmlElement("szUserType");
	TiXmlText * xmlTextszUserType = new TiXmlText(reqText->strUserType.c_str());
	elszUserType->LinkEndChild(xmlTextszUserType);
	element->LinkEndChild(elszUserType);

	if (reqText->strActionType.length() > 0)
	{
		TiXmlElement * elucActionType = new TiXmlElement("ucActionType");
		TiXmlText * xmlTextucActiontype = new TiXmlText(reqText->strActionType.c_str());
		elucActionType->LinkEndChild(xmlTextucActiontype);
		element->LinkEndChild(elucActionType);
	}

	if (reqText->strCameraNumber.length() > 0)
	{
		TiXmlElement * elulCameraNumber = new TiXmlElement("ulCameraNumber");
		TiXmlText * xmlTextulCameraNumber = new TiXmlText(reqText->strCameraNumber.c_str());
		elulCameraNumber->LinkEndChild(xmlTextulCameraNumber);
		element->LinkEndChild(elulCameraNumber);
	}

	doc.LinkEndChild( root );
	TiXmlPrinter printer;
	doc.Accept(&printer);
	std::string strReqXml = printer.CStr();
	return strReqXml;
}

int ParseAuthRespXml(std::string &strAuthRespXml, VedioInfo &relVd)
{
	
	if (strAuthRespXml.length() == 0)
	{
		cout<<"鉴权失败：鉴权返回报文为空。"<<endl;
		return JQ_REQ_FAIL;
	}
	//服务调用结果
	std::string strInvokResult;
	TiXmlDocument resp;
	resp.Parse(strAuthRespXml.c_str()); //解析返回的应答报文

	TiXmlElement *root = resp.RootElement();   
	for(TiXmlNode *node = root->FirstChild(); node; node = node->NextSibling()) 
	{
		//获取head节点
		if ( 0 == strcmp(node->Value(), "head"))
		{
			TiXmlNode *child = node->FirstChild();
			strInvokResult = child->ToElement()->GetText() ? child->ToElement()->GetText() : ""; 
		}

		if (("success" == strInvokResult) && (0 == strcmp(node->Value(), "body")))
		{
			TiXmlNode *child = node->FirstChild(); //JianQuan 鉴权
			if (0 == strcmp(child->Value(), "JianQuan"))
			{
				TiXmlNode *element = child->FirstChild();
				while(element)   
				{
					int type = element->Type();

					if ( type == TiXmlNode::TINYXML_ELEMENT &&  (0 == strcmp(element->Value(), "szOwnerUnitIP")) )
					{

						relVd.soapURL = string("https://") + (element->ToElement()->GetText() ? element->ToElement()->GetText() : "");
						relVd.soapURL+=":";
					}
					if ( type == TiXmlNode::TINYXML_ELEMENT && (0 == strcmp(element->Value(), "ulOwnerUnitPort")) )
					{
						relVd.soapURL += element->ToElement()->GetText() ? element->ToElement()->GetText() : "";
						relVd.soapURL +="/live.fcgi";
					}
					element = child->IterateChildren(element);   
				}  
			}
		}
	}
	return 0;
}

int ClientJianQuan(RequestText *reqTex, std::string & strRespXml)
{

	JqServiceHttpBinding jqService;
	soap_set_imode(jqService.soap, SOAP_C_UTFSTRING); //设置UTF-8字符集格式
	jqService.endpoint = reqTex->strUrl.c_str(); //下载地址

	int nMinUrlLen = 8 + strlen("/JianQuan/services/JqService");
	if( reqTex->strUrl.length() <= nMinUrlLen )
	{

		cout<< "鉴权服务器地址配置不正确。"<<endl;
		return JQ_URL_ERROR;
	}

	jqService.soap->connect_timeout = 3; //设置连接超时时长
	jqService.soap->recv_timeout = 3;    //等待接收时长
	jqService.soap->send_timeout = 3;    //发送时长
	if (reqTex->strProxyHost.length() > 0) //代理服务器设置
	{
	 	jqService.soap->proxy_host = reqTex->strProxyHost.c_str();
	 	jqService.soap->proxy_port = atoi(reqTex->strProxyPort.c_str()) ? atoi(reqTex->strProxyPort.c_str()) : 80;
	}

	//调用鉴权服务
	_ns1__getData DownloadConfig;

	std::string strReqXml = MakeReqXml(reqTex);

	DownloadConfig.in0 = &reqTex->strSystemType;    //系统类别:现设为1010，调用者的标识
	DownloadConfig.in1 = &reqTex->strIdentifier;    //接口标识: 接口的唯一标识,表示调用哪个接口
	DownloadConfig.in2 = &strReqXml; //此参数为请求具体报文内容

	_ns1__getDataResponse retResponse; //返回内容

	//鉴权开始
 	cout<< "调用客户端请求鉴权开始,发送报文为："<<strReqXml<<endl;
 
 	jqService.__ns1__getData(&DownloadConfig, &retResponse); //接口调用
 	cout<<"调用客户端请求鉴权结束"<<endl;
 	if (jqService.soap->error != SOAP_OK)
 	{
		cout<<"客户端请求鉴权失败:" <<endl;
		return JQ_REQ_FAIL;
 	}
 
 	std::string outXml = (*(retResponse.out)); //获取返回的内容报文

 	cout<< "客户端请求鉴权结束:"<<outXml<<endl;
 	strRespXml = outXml;

	return OK;
}

int InitSoap(struct soap * soap, const char * szProxyHost, const char * szProxyPort)
{
	soap_init(soap);

	soap->send_timeout = 3; // 超时时间
	soap->recv_timeout = 3; // 接收超时
	soap->connect_timeout = 3; //连接超时

	//如果存在代理服务器
	if ( strlen(szProxyHost) > 0)
	{
		soap->proxy_host = szProxyHost;
		soap->proxy_port = atoi(szProxyPort) ? atoi(szProxyPort) : 80;
	}
	soap->userid = "roy"; 
	soap->passwd = "liang";
#if defined(WITH_OPENSSL)
	soap_ssl_init();
	if ( soap_ssl_client_context(soap, SOAP_SSL_NO_AUTHENTICATION, NULL, NULL, NULL, NULL, NULL) )
	{
		//soap_print_fault(soap, stderr);
		cout<<"加载客户端证书失败。"<<endl;
		return 110;
	}
#endif
	return 0;
}

int GetRelVdWithGsoap(VedioInfo &relVd)
{
	struct soap rsoap;
	int retcode = InitSoap(&rsoap, "", "");
	if ( retcode )
	{
		//初始化失败
		cout<<"初始化失败"<<endl;
		return retcode;
	}
	//调用视频切换接口
	struct ns__HBNET_VIDEO_STREAM VideoStream;
	VideoStream.szDescription = (char*)soap_malloc(&rsoap, 256);

	ns__HBUSERINFO nsUserInfo;
	nsUserInfo.strUser = g_reqText.strUser;
	nsUserInfo.nPermission = 1;
	nsUserInfo.nCtrlTimeOut = 30;

    retcode = soap_call_ns__SwitchCameraToStream(&rsoap, relVd.soapURL.c_str(), "", nsUserInfo, atoi(relVd.cameraid.c_str()), &VideoStream);
	cout<<"retcode = "<<retcode<<endl;
	if(retcode==SOAP_OK)
	{
		cout<<"摄像机"<<relVd.cameraid<<"实时视频调看成功,释放请求";
		relVd.udpURL=string(VideoStream.szDescription);
		soap_destroy(&rsoap);
		soap_end(&rsoap);
		soap_done(&rsoap);
	}else
	{
		cout<<"摄像机"<<relVd.cameraid<<"实时视频调看失败,释放请求";
		soap_destroy(&rsoap);
		soap_end(&rsoap);
		soap_done(&rsoap);
		return SOAP_FAIL;
	}
	return retcode;
}

int GetHisVdWithGsoap(VedioInfo &hisVd)
{
	struct soap rsoap;
	int retcode = InitSoap(&rsoap, "", "");
	if ( retcode )
	{
		//初始化失败
		cout<<"初始化失败"<<endl;
		return retcode;
	}
	//调用历史视频查询
	struct ns__HBNET_RECOED_FILECOND  fileCond;
	fileCond.ulCamNumber = atoi(hisVd.cameraid.c_str());
	fileCond.ulStartTime = hisVd.beg;
	fileCond.ulStopTime = hisVd.end;

	//std::string strRecodeList;
	char *RecodeList;
	ns__HBUSERINFO nsUserInfo;
	nsUserInfo.strUser = g_reqText.strUser;
	nsUserInfo.nPermission = 1;
	nsUserInfo.nCtrlTimeOut = 6;

	retcode = soap_call_ns__QueryVideoUrl(&rsoap, hisVd.soapURL.c_str(), "", nsUserInfo, atoi(hisVd.cameraid.c_str()), &fileCond, RecodeList);
	cout<<"retcode = "<<retcode<<endl;
	if(retcode==SOAP_OK)
	{
		if (NULL == RecodeList||0==strlen(RecodeList))
		{
			cout<<"调用查询历史录像接口失败，返回报文内容为空。"<<endl;
			DestorySoap(&rsoap);
			return HIS_URL_NULL;
		}
		//解析XML报文
		TiXmlDocument resp;
		if (NULL == resp.Parse(RecodeList)) //解析返回的应答报文
		{
			cout<<"调用查询历史录像接口失败，解析XML报文失败。"<<endl;
			return HIS_URL_PARSE_FAIL;
		}
		char szBuffer[512] = {0};
		TiXmlElement *root = resp.RootElement();
		if ( NULL != root )
		{
			for(TiXmlNode *node = root->FirstChild(); node; node = node->NextSibling()) //NET_RECOED_FILE
			{
				//获取NET_RECOED_FILE内容节点
				TiXmlNode * recordElement = node->FirstChild();
				NET_RECOED_FILE NetRecodeFile; //结构体
				
				while(recordElement)
				{
					int type = recordElement->Type();
					memset(szBuffer, 0, sizeof(szBuffer));

					if ( type == TiXmlNode::TINYXML_ELEMENT &&  (0 == strcmp(recordElement->Value(), "StartTime")) )
					{
						NetRecodeFile.ulStartTime = atol(recordElement->ToElement()->GetText() ? recordElement->ToElement()->GetText() : "");
					}

					if ( type == TiXmlNode::TINYXML_ELEMENT &&  (0 == strcmp(recordElement->Value(), "StopTime")) )
					{
						NetRecodeFile.ulStopTime = atol(recordElement->ToElement()->GetText() ? recordElement->ToElement()->GetText() : "");
					}

					if ( type == TiXmlNode::TINYXML_ELEMENT &&  (0 == strcmp(recordElement->Value(), "FileSize")) )
					{
						NetRecodeFile.ulFileSize = atol(recordElement->ToElement()->GetText() ? recordElement->ToElement()->GetText() : "");
					}

// 					if ( type == TiXmlNode::TINYXML_ELEMENT &&  (0 == strcmp(recordElement->Value(), "CamNumber")) )
// 					{
// 						NetRecodeFile.ulCamNumber = atol(recordElement->ToElement()->GetText() ? recordElement->ToElement()->GetText() : "");
// 					}

					if ( type == TiXmlNode::TINYXML_ELEMENT &&  (0 == strcmp(recordElement->Value(), "StreamType")) )
					{
						NetRecodeFile.vsfStreamType = atoi(recordElement->ToElement()->GetText() ? recordElement->ToElement()->GetText() : "");
					}

					if ( type == TiXmlNode::TINYXML_ELEMENT &&  (0 == strcmp(recordElement->Value(), "FileName")) )
					{
						//strncpy(NetRecodeFile.szFileName, (recordElement->ToElement()->GetText() ? recordElement->ToElement()->GetText() : ""), 255);
						NetRecodeFile.url = recordElement->ToElement()->GetText() ? recordElement->ToElement()->GetText() : "";
					}
					//循环下一记录
					recordElement = node->IterateChildren(recordElement);
				}
				//追加到list
				if(NetRecodeFile.url.length()>=0)
				{
					hisVd.hisInfos.push_back(NetRecodeFile);
				}
			} //循环表结束
		}

		cout<<"摄像机"<<hisVd.cameraid<<"历史录像查询成功，释放请求";
		DestorySoap(&rsoap);
	}else
	{
		cout<<"摄像机"<<hisVd.cameraid<<"历史录像查询失败,释放请求";
		DestorySoap(&rsoap);
		return SOAP_FAIL;
	}
	return retcode;
	return OK;
}


int ReadConfig()
{
//	char buff[MAX_PATH]={0};
//	GetPrivateProfileStringA("JianQuan", "user", "admin", buff, MAX_PATH, CONFIG_FILE);
//	if (strlen(buff)<=0)
//	{
//		return USER_NULL;
//	}
//	g_reqText.strUser = buff;
//	ZeroMemory(buff, sizeof(buff));
//	GetPrivateProfileStringA("JianQuan", "pwd", "Haibo2013", buff, MAX_PATH, CONFIG_FILE);
//	if (strlen(buff)<=0)
//	{
//		return PWD_NULL;
//	}
//	g_reqText.strPass = buff;
//	ZeroMemory(buff, sizeof(buff));
//	GetPrivateProfileStringA("JianQuan", "ip", "127.0.0.1", buff, MAX_PATH, CONFIG_FILE);
//	if (strlen(buff)<7)
//	{
//		return IP_ERROR;
//	}
//	g_reqText.strUrl = string("http://")+string(buff)+":";
//	ZeroMemory(buff, sizeof(buff));

//	GetPrivateProfileStringA("JianQuan", "port", "127.0.0.1", buff, MAX_PATH, CONFIG_FILE);
//	if (strlen(buff)<=0 || atoi(buff)<=0)
//	{
//		return PORT_ERROR;
//	}
//	g_reqText.strUrl += string(buff);
//	g_reqText.strUrl += "/JianQuan/services/JqService";

	return OK;
}

void *ClientListenThread(void *pParam)
{
	std::cout<<"thread begin"<<std::endl;
	VedioInfo * pvd = (VedioInfo*)pParam;
	if (pvd->udpURL.length()<=0)
	{
		cout<<"udp 地址错误"<<endl;
		return 0;
	}
	int index = pvd->udpURL.rfind(":");
	int port = atoi(pvd->udpURL.substr(index+1, pvd->udpURL.length()-index-1).c_str());
	if (port==0)
	{
		cout<<"udp port 错误"<<endl;
	}
	index = pvd->udpURL.rfind("//");
	string udpAdd = pvd->udpURL.substr(index+2, pvd->udpURL.rfind(":")-index-2);
	if (udpAdd.length()<=0)
	{
		cout<<"udp addr 错误"<<endl;
	}

	int nRet=0;
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if( sock == -1 )
	{
		cout<<"NET_HB_NOSOCK"<<endl;
		return 0;
	}

    //设置缓冲区
    int optVal;
    optVal = 2*1024*1024;
    if(setsockopt (sock, SOL_SOCKET, SO_RCVBUF, (char*)&optVal, sizeof(optVal))<0)
    {
        cout<<"设置缓冲区失败"<<endl;
        return NULL;
    }


    //设置端口复用
    int yes = 1;
    if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char*)&yes, sizeof(yes))<0)
    {
        cout<<"yes failed"<<endl;
        return NULL;
    }

	//绑定本地地址和端口
	struct sockaddr_in ad; 
	memset(&ad,0,sizeof(ad));
	ad.sin_family      = AF_INET;
    ad.sin_addr.s_addr = htonl(INADDR_ANY);
	ad.sin_port = htons(/*40008*/port);


	//设置接收超时
	int time = (5*100);
	setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char*)&time, sizeof(time));

	//socket绑定
	nRet = bind(sock, (struct sockaddr *)&ad, sizeof(struct sockaddr));
    if( nRet < 0 )
	{
        close(sock);
		cout<<"NET_HB_NOBIND"<<endl;
		return 0;
	}

	//加入组播地址
	struct ip_mreq mreq;  
	mreq.imr_multiaddr.s_addr = inet_addr (/*"239.10.10.201"*/udpAdd.c_str());
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);
    cout<<"ip="<<udpAdd<<" port="<<port<<endl;
    if (setsockopt (sock,IPPROTO_IP, IP_ADD_MEMBERSHIP,&mreq,sizeof(mreq)) == -1)
	{
        cout<<"NET_HB_NOMODICAST:"<<endl;
        close (sock);
		return 0;
	}


	//开始接收
    sockaddr_in  from;
    int recvlen;
	char buf[2000]={0};
    socklen_t fromlen = sizeof(from);

#ifdef RealSend
	SOCKET s_send;
	s_send = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	SOCKADDR_IN sendaddress;
	sendaddress.sin_family = AF_INET;
	sendaddress.sin_addr.S_un.S_addr = inet_addr("192.168.10.170");
	sendaddress.sin_port = htons(6000);
	int sendbuf = 1024*1024*2;
	setsockopt(s_send, SOL_SOCKET, SO_SNDBUF, (char*)&sendbuf, sizeof(sendbuf));
#endif // RealSend
    cout<<"开始接收视频流....."<<!pvd->isStop<<endl;
	while (!pvd->isStop)
	{
        recvlen = recvfrom( sock ,buf,sizeof(buf),0,(struct sockaddr *)&from,(socklen_t *)&fromlen);
        //cout<<"recvlen="<<recvlen<<endl;
        if( recvlen > 0)
		{
			pvd->callbackFun(pvd->id, pvd->cameraid, buf, recvlen);
			incCpu();

#ifdef RealSend
			sendto(s_send, buf, recvlen, 0, (sockaddr*)&sendaddress, sizeof(sendaddress));
#endif // RealSend
		
		}
	}
    close(sock);

#ifdef RealSend
	closesocket(s_send);
#endif // RealSend
    //SetEvent(pvd->thId);
	return 0;
}
//SOCKET s_send;
//SOCKADDR_IN msin;
void *HisClientListenThread(void *pParam)
{
	VedioInfo * pvd = (VedioInfo*)pParam;

// 	s_send = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
// 	msin.sin_family = AF_INET;
// 	msin.sin_addr.S_un.S_addr = inet_addr("192.168.10.52");
// 	msin.sin_port = htons(1234);
// 	int sendbuf = 1500;
// 	int ret = setsockopt(s_send, SOL_SOCKET, SO_SNDBUF, (char*)&sendbuf, sizeof(sendbuf));

	DownloadSaveFiles(*pvd);
	return 0;
}

void *HeartBeat(void *pParam)
{
	while (true)
	{
		struct soap rsoap;
        //EnterCriticalSection(&cs);
        pthread_mutex_lock(&mutex_lock);
		for (int i=0;i<g_vec_Vds.size();i++)
		{
			if (g_vec_Vds[i]->isHis)
			{
				continue;
			}
			int retcode = InitSoap(&rsoap, "", "");
			if (retcode)
			{
				cout<<"HeartBeate  InitSoap Failed:"<<g_vec_Vds[i]->cameraid<<endl;
				continue;
			}
			struct ns_HeartBeat nsHeartBeat;
			nsHeartBeat.ulCameraID = atol(g_vec_Vds[i]->cameraid.c_str());
			nsHeartBeat.strUser = g_reqText.strUser;
			nsHeartBeat.nPlayType = 0;
			ns__Response Response;

			retcode = soap_call_ns__HeartBeat(&rsoap, g_vec_Vds[i]->soapURL.c_str(), "", nsHeartBeat, &Response);
			switch (retcode)
			{
			case 0:
				cout<<"摄像机：" << g_vec_Vds[i]->cameraid << "发心跳请求成功。"<<endl;
				break;
			case 401:
				cout<<"摄像机：" << g_vec_Vds[i]->cameraid << "发心跳请求相应失败。"<<endl;
				break;
			default:
				break;
			}

			soap_destroy(&rsoap);
			soap_end(&rsoap);
			soap_done(&rsoap);
		}
        //LeaveCriticalSection(&cs);
        pthread_mutex_unlock(&mutex_lock);
        sleep(300);	//五分钟一次
	}
	
	return 0;
}

int DestorySoap(struct soap * soap)
{
	soap_destroy(soap);
	soap_end(soap);
	soap_done(soap);
	return 0;
}


int GetRtp(int srclen,char* OneFrameBuf, unsigned short& seq_num, unsigned int& ts_current, unsigned char* sendbuf, VedioInfo &vdInfo)
{
	RTP_FIXED_HEADER *rtp_hdr;
	if (srclen <= MAX_MTU_LEN && !vdInfo.isStop)//一个包
	{
		memset(sendbuf, 0, 1500);
		rtp_hdr = (RTP_FIXED_HEADER *)&sendbuf[0];
		rtp_hdr->version = 2;
		rtp_hdr->payload = PS_NA;
		rtp_hdr->marker = 1;
		rtp_hdr->seq_no = htons(seq_num++);
		int key = OneFrameBuf[4] & 0x1f;
		if (key == 7)
            ts_current += timestamp_increse;
        rtp_hdr->timestamp = htonl(ts_current);
        //cout<<"625: timestamp="<<rtp_hdr->timestamp<<" key="<<key<<endl;

		rtp_hdr->ssrc = csrc;

        memmove(sendbuf+sizeof(RTP_FIXED_HEADER), OneFrameBuf+4, srclen);//一包rtp数据

		//sendto(s_send, (char*)sendbuf, srclen+12-4, 0, (sockaddr *)&msin, sizeof(msin));
        vdInfo.callbackFun(vdInfo.id, vdInfo.cameraid, (char*)sendbuf, srclen+sizeof(RTP_FIXED_HEADER)-4);
		//incCpu();
		
	}else if (srclen > MAX_MTU_LEN && !vdInfo.isStop)
	{
		//计算这一帧需要多少个rtp包
		int k = 0;
		int l = 0;
		k = srclen/MAX_MTU_LEN;
		l = srclen%MAX_MTU_LEN;

		int t = 0;//当前第几个分片
		int key = OneFrameBuf[4] & 0x1f;
		if (key == 1)
			ts_current += timestamp_increse;
		char Fu_Header[2] = {0x7C, 0x85};
		while(t <= k)
		{
			if (vdInfo.isStop)
			{
				break;
			}
			if (!t )//第一个rtp包
			{
				memset(sendbuf, 0, 1500);
				rtp_hdr = (RTP_FIXED_HEADER *)&sendbuf[0];

				rtp_hdr->version = 2;
				rtp_hdr->marker = 0;
				rtp_hdr->payload = PS_NA;

				rtp_hdr->seq_no = htons(seq_num++);
				rtp_hdr->timestamp = htonl(ts_current);
				rtp_hdr->ssrc = csrc;
				if (key == 1)
					Fu_Header[1] = 0x81;
                memmove(sendbuf+sizeof(RTP_FIXED_HEADER), Fu_Header, 2);
                memmove(sendbuf+sizeof(RTP_FIXED_HEADER)+2, OneFrameBuf+5, MAX_MTU_LEN);
				//sendto(s_send, (char*)sendbuf, MAX_MTU_LEN+14, 0, (sockaddr *)&msin, sizeof(msin));
                vdInfo.callbackFun(vdInfo.id, vdInfo.cameraid, (char*)sendbuf, MAX_MTU_LEN+sizeof(RTP_FIXED_HEADER)+2);
				//incCpu();
			}else if (k == t)//最后一个包
			{
				memset(sendbuf, 0, 1500);
				rtp_hdr = (RTP_FIXED_HEADER *)&sendbuf[0];
				rtp_hdr->version = 2;
				rtp_hdr->marker = 1;
				rtp_hdr->payload = PS_NA;

				rtp_hdr->seq_no = htons(seq_num++);
				rtp_hdr->timestamp = htonl(ts_current);
				rtp_hdr->ssrc = csrc;

				if (l > 0)
				{
					if (key == 1)
						Fu_Header[1] = 0x41;
					else
						Fu_Header[1] = 0x45;
                    memmove(sendbuf+sizeof(RTP_FIXED_HEADER), Fu_Header, 2);
                    memmove(sendbuf+sizeof(RTP_FIXED_HEADER)+2, OneFrameBuf+5+MAX_MTU_LEN*k, srclen-MAX_MTU_LEN*k);
					//sendto(s_send, (char*)sendbuf, srclen-MAX_MTU_LEN*k+14-5, 0, (sockaddr *)&msin, sizeof(msin));
                    vdInfo.callbackFun(vdInfo.id, vdInfo.cameraid, (char*)sendbuf, srclen-MAX_MTU_LEN*k+sizeof(RTP_FIXED_HEADER)+2-5);
					//incCpu();
				}
			}else if (t<k&&0!=t)
			{
				memset(sendbuf, 0, 1500);
				rtp_hdr = (RTP_FIXED_HEADER *)&sendbuf[0];
				rtp_hdr->version = 2;
				if (l>0)
					rtp_hdr->marker = 0;
				else if(t == k-1)
					rtp_hdr->marker = 1;
				rtp_hdr->payload = PS_NA;

				rtp_hdr->seq_no = htons(seq_num++);
				rtp_hdr->timestamp = htonl(ts_current);
				rtp_hdr->ssrc = csrc;
				if (key == 1)
					Fu_Header[1] = 0x01;
				else
					Fu_Header[1] = 0x05;
                memmove(sendbuf+sizeof(RTP_FIXED_HEADER), Fu_Header, 2);
                memmove(sendbuf+sizeof(RTP_FIXED_HEADER)+2, OneFrameBuf+5+MAX_MTU_LEN*t, MAX_MTU_LEN);
				//sendto(s_send, (char*)sendbuf, MAX_MTU_LEN+14, 0, (sockaddr *)&msin, sizeof(msin));

                vdInfo.callbackFun(vdInfo.id, vdInfo.cameraid, (char*)sendbuf, MAX_MTU_LEN+sizeof(RTP_FIXED_HEADER)+2);
				//incCpu();
			}
			t++;
		}
	}

	return 0;
}

int NalFrame(unsigned int& ts_current, unsigned short& seq_num, unsigned char* src, int len, bool isFrame, int& halflen, char* OneFrameBuf, unsigned char* sendbuf, VedioInfo &vdInfo)
{
	if(vdInfo.isStop)
	{
		return 0;
	}
	//先判断这一帧是否需要拼接
	if (!isFrame && src[0] == 0x00 && src[1] == 0x00 && src[2] == 0x00 && src[3] == 0x01)
	{
		memset(OneFrameBuf, 0, MAX_FRAME_SIZE);
		memmove(OneFrameBuf, src, len);
		halflen = len;
		return 0;
	}else if (!isFrame && !vdInfo.isStop)//需要与上一部分数据拼接
	{
		memmove(OneFrameBuf+halflen, src, len);
		len += halflen;
		halflen = 0;
		//rtp打包
		GetRtp(len, OneFrameBuf, seq_num, ts_current, sendbuf,vdInfo);
		int key = OneFrameBuf[4] & 0x1f;
		if (key == 5 || key == 1)
            usleep(30*1000);

		return 0;
	}

	memset(OneFrameBuf, 0, MAX_FRAME_SIZE);
	memmove(OneFrameBuf, src, len);
	//rtp打包
	GetRtp(len, OneFrameBuf, seq_num, ts_current, sendbuf, vdInfo);
	int key = OneFrameBuf[4] & 0x1f;
	if (key == 5 || key == 1)
        usleep(30*1000);
	return 0;
}

//下载文件并保存为新文件名
//bool DownloadSaveFiles(VedioInfo &hisVd)
//{
//	for (int i=0; i<hisVd.hisInfos.size();i++)
//	{
//		if (hisVd.isStop)
//		{
//			break;
//		}
//		HINTERNET hSession = InternetOpenA("RookIE/1.0", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
//		if (hSession != NULL)
//		{
//			HINTERNET handle2 = InternetOpenUrlA(hSession, hisVd.hisInfos[i].url.c_str(), NULL, 0, INTERNET_FLAG_DONT_CACHE, 0);
//			if (handle2 != NULL)
//			{
//				byte *Temp = new byte[MAX_READ_BUF];
//				ULONG Number = 1;
//				bool NeedHalf = FALSE;
//				int nextpos = 0;
//				int halflen = 0;
//				char *OneFrameBuf = new char[MAX_FRAME_SIZE];
//				unsigned int ts_current=0;
//				unsigned short seq_num=0;
//				unsigned char sendbuf[1500];

//				while (Number > 0 && !hisVd.isStop)
//				{
//					InternetReadFile(handle2, Temp, MAX_READ_BUF - 1, &Number);
//					if (Number<4)
//					{
//						cout<<"收到历史视频数据小于4"<<endl;
//						break;
//					}
//					incCpu();
//					for (int i=0; i<Number; i++)
//					{
//						if (hisVd.isStop)
//						{
//							cout<<"历史视频已注销，摄像机id:"<<hisVd.cameraid<<" id="<<hisVd.id<<endl;
//							break;
//						}
//						if (Temp[i] == 0x00 && Temp[i+1] == 0x00 && Temp[i+2] == 0x00 && Temp[i+3] == 0x01)//找到ps包头
//						{
//							//前面的部分为上一帧数据
//							if (i != 0 && NeedHalf)
//							{
//								NeedHalf = FALSE;
//								NalFrame(ts_current, seq_num, Temp, i, FALSE, halflen,OneFrameBuf, sendbuf, hisVd);
//								//Sleep(30);
//							}

//							//查找下一个包头
//							for (nextpos = i+5; nextpos <	Number; nextpos++)
//							{
//								if (Temp[nextpos] == 0x00 && Temp[nextpos+1] == 0x00 && Temp[nextpos+2] == 0x00 && Temp[nextpos+3] == 0x01 )//找到了
//								{
//									NalFrame(ts_current, seq_num, Temp+i, nextpos-i, TRUE, halflen,OneFrameBuf, sendbuf, hisVd);
//								//Sleep(30);
//								break;
//								}
//								else if (nextpos == Number-4 )//没找到，剩下的全为一个ps包
//								{
//									NeedHalf = TRUE;
//									NalFrame(ts_current, seq_num, Temp+i, Number-i, FALSE, halflen,OneFrameBuf, sendbuf, hisVd);
//									break;
//								}
//							}
//						}
//					}
//					//hisVd.callbackFun(hisVd.id, hisVd.cameraid, (char*)Temp, Number);
//				}
//				delete Temp;
//				delete OneFrameBuf;
//				InternetCloseHandle(handle2);
//				handle2 = NULL;
//			}
//			InternetCloseHandle(hSession);
//			hSession = NULL;
//		}
//	}
//	hisVd.isStop = true;	//播放完毕
//	cout<<"历史视频播放结束，摄像机id:"<<hisVd.cameraid<<" id="<<hisVd.id<<endl;
//	SetEvent(hisVd.thId);
//	return true;
//}
size_t write_data(void *ptr, size_t nmemb, size_t Number, void *stream)
{

   // cout<<"Number="<<Number<<" nmemb="<<nmemb<<endl;
    int tmp = Number;
    //unsigned char * Temp = (unsigned char*)ptr;
    DecParam *decParam = (DecParam*) stream;
    if(decParam->append(ptr, nmemb*Number))
    {
        return nmemb*Number;
    }
    //cout<<"861"<<endl;
    Number = decParam->curlen;
    decParam->curlen = 0;
    unsigned char * Temp = new unsigned char [MAX_READ_BUF+1024*1024];
    memcpy(Temp, decParam->buffer, MAX_READ_BUF+1024*1024);
    memset(decParam->buffer, 0, MAX_READ_BUF+1024*1024);
    //fwrite(ptr, Number,nmemb,decParam->fd);
    //for(int j=0; j<nmemb;j++)
   // {
        if(decParam->pvdInfo->isStop)
        {
            delete Temp;
            return 0;
        }
        if (Number<4)
        {
            cout<<"收到历史视频数据小于4"<<endl;
            delete Temp;
            return 0;
        }
        incCpu();
        for(int i=0; i<Number; i++)
        {
            if (decParam->pvdInfo->isStop)
            {
                cout<<"历史视频已注销，摄像机id:"<<decParam->pvdInfo->cameraid<<" id="<<decParam->pvdInfo->id<<endl;
                break;
            }
            if (Temp[i] == 0x00 && Temp[i+1] == 0x00 && Temp[i+2] == 0x00 && Temp[i+3] == 0x01)//找到ps包头
            {
                //前面的部分为上一帧数据
                if (i != 0 && decParam->NeedHalf)
                {
                    decParam->NeedHalf = false;
                    NalFrame(decParam->ts_current, decParam->seq_num, Temp, i, false, decParam->halflen,decParam->OneFrameBuf, decParam->sendbuf, *(decParam->pvdInfo));
                }

                //查找下一个包头
                for (decParam->nextpos = i+5; decParam->nextpos <	Number; decParam->nextpos++)
                {
                    if (Temp[decParam->nextpos] == 0x00 && Temp[decParam->nextpos+1] == 0x00 && Temp[decParam->nextpos+2] == 0x00 && Temp[decParam->nextpos+3] == 0x01 )//找到了
                    {
                        NalFrame(decParam->ts_current, decParam->seq_num, Temp+i, decParam->nextpos-i, true, decParam->halflen,decParam->OneFrameBuf, decParam->sendbuf, *(decParam->pvdInfo));
                        break;
                    }else if(decParam->nextpos == Number-4 )//没找到，剩下的全为一个ps包
                    {
                        decParam->NeedHalf = true;
                        NalFrame(decParam->ts_current, decParam->seq_num, Temp+i, Number-i, false, decParam->halflen,decParam->OneFrameBuf, decParam->sendbuf, *(decParam->pvdInfo));
                        break;
                    }
                }
            }
        }
    //}
    delete Temp;
    return tmp*nmemb;
}
bool DownloadSaveFiles(VedioInfo &hisVd)
{
    for (int i=0; i<hisVd.hisInfos.size();i++)
    {
        if (hisVd.isStop)
        {
            break;
        }
        DecParam *decParam = new DecParam;
        decParam->pvdInfo = & hisVd;
        //decParam->fd = fopen("/home/liuyufeng/1.h264", "w");
        CURL *curl;
        curl_global_init(CURL_GLOBAL_ALL);
        curl=curl_easy_init();
        curl_easy_setopt(curl,CURLOPT_URL,hisVd.hisInfos[i].url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, decParam);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    hisVd.isStop = true;	//播放完毕
}

void incCpu()
{
	double value = 120.0000001;
	for (int i=0; i<30000; i++)
	{
		value += i;
		sqrt(value);
	}
}
