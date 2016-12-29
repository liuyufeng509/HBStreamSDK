#include "testdll_global.h"
#include "common.h"
#include <iostream>

int Init(string ip, string port, string user, string pwd)
{
	if (ip.length()<7)
	{
		return IP_ERROR;
	}
	if (port.length()<=0 || atoi(port.c_str())<=0)
	{
		return PORT_ERROR;
	}
	if (user.length()<=0)
	{
		return USER_NULL;
	}
	if (pwd.length()<=0)
	{
		return PWD_NULL;
	}
	//鉴权服务初始化
	g_reqText.strUserType = "0";	//单元类型
	g_reqText.strActionType= "switch";	//操作类型
	g_reqText.strBackUrl = "";
	g_reqText.strSystemType = "1010";		//系统类别
	g_reqText.strIdentifier="0001";	//接口标识
	g_reqText.strProxyHost = "";
	g_reqText.strProxyPort = "";	
	//int ret = ReadConfig();
	g_reqText.strUser = user;
	g_reqText.strPass = pwd;
	g_reqText.strUrl = string("http://")+ip+":"+ port + "/JianQuan/services/JqService";
	
	g_vec_Vds.clear();

	//启动心跳线程
    //InitializeCriticalSection(&cs);//初始化临界区
    pthread_mutex_init(&mutex_lock, NULL);
    pthread_t th;
    int handl = pthread_create(&th, NULL, HeartBeat, NULL);
    if (handl != 0)
	{
        cout<<"开启心跳线程失败"<<endl;
		return HEART_THREAD_FAIL;
	}
	return OK;
}

int RegisterRealVedioReq(CallBackFun fun, string& id, string cameraid)
{
	//参数判断
	if(g_vec_Vds.size()>=MAX_VDS)
	{
		return VD_NUM_OVER;
	}
	if (cameraid.length()<=0)
	{
		return CAMRID_NULL;
	}
	if (fun == NULL)
	{
		return CALL_BACK_NULL;
	}

	VedioInfo *pVdInfo = new VedioInfo;
	pVdInfo->isHis = false;
	pVdInfo->id = GetUUID();
	id = pVdInfo->id;
	pVdInfo->cameraid = cameraid;
	pVdInfo->isStop = false;	//注册后就收流
	pVdInfo->callbackFun = fun;	//注册回调函数
    pVdInfo->thId = 0;
	//获取高清服务器的路径
	RequestText reqText = g_reqText;
	reqText.strCameraNumber = pVdInfo->cameraid;
	string strRespXml="";
	int ret = ClientJianQuan(&reqText, strRespXml);
	if (ret != OK)
	{
		return ret;
	}

	//解析获取组播地址
	ret = ParseAuthRespXml(strRespXml, *pVdInfo);
	if (ret !=OK)
	{
		return ret;
	}

	ret = GetRelVdWithGsoap(*pVdInfo);
	cout<<"udp地址："<<pVdInfo->udpURL<<endl;
	if (ret == OK)	//实时视频调看成功
	{
        //EnterCriticalSection(&cs);
        pthread_mutex_lock(&mutex_lock);
		g_vec_Vds.push_back(pVdInfo);	//注册成功，将该路视频假如vector
        //LeaveCriticalSection(&cs);
        pthread_mutex_unlock(&mutex_lock);
		//获取视频流
        int handl = pthread_create(&pVdInfo->thId, NULL, ClientListenThread, (void*)pVdInfo);
        if (handl != 0)
		{
			cout<<"开启接收视频流线程失败,摄像机编号："<<pVdInfo->cameraid<<" id编号："<<pVdInfo->id<<endl;
			return RCV_THREAD_FAIL;
        }
	}

	return ret;
}

int UnRegisterRealVedioReq(string id)
{
    //EnterCriticalSection(&cs);
    pthread_mutex_lock(&mutex_lock);
	for (vector<VedioInfo*>::iterator iter= g_vec_Vds.begin(); iter!=g_vec_Vds.end(); iter++)
	{
		if ((*iter)->id == id)
		{
			(*iter)->isStop = true;
			//Sleep(500);			//确保线程退出
            //WaitForSingleObject((*iter)->g_event, 10000);
            int *thread_ret = NULL;
            pthread_join(((*iter)->thId), (void**)&thread_ret);
			cout<<"注销摄像机:"<<(*iter)->cameraid<<"的视频请求"<<endl;
			delete (*iter);
			g_vec_Vds.erase(iter);
            break;
		}
	}
    //LeaveCriticalSection(&cs);
    pthread_mutex_unlock(&mutex_lock);
	return OK;
}

int RegisterHisVedioReq(CallBackFun fun, string& id, string cameraid, time_t begt, time_t endt)
{
	//参数判断
	if(g_vec_Vds.size()>=MAX_VDS)
	{
		return VD_NUM_OVER;
	}
	if (cameraid.length()<=0)
	{
		return CAMRID_NULL;
	}
	if (fun == NULL)
	{
		return CALL_BACK_NULL;
	}

	VedioInfo *pVdInfo = new VedioInfo;
	pVdInfo->isHis = true;
	pVdInfo->id = GetUUID();
	id = pVdInfo->id;
	pVdInfo->cameraid = cameraid;
	pVdInfo->isStop = false;	//注册后就收流
	pVdInfo->callbackFun = fun;	//注册回调函数
	pVdInfo->beg = begt;
	pVdInfo->end = endt;
	pVdInfo->hisInfos.clear();
    pVdInfo->thId=0;

	//获取高清服务器的组播地址
	RequestText reqText = g_reqText;
	reqText.strCameraNumber = pVdInfo->cameraid;
	reqText.strUserType = "0";	//单元类型
	reqText.strActionType= "view";	//操作类型
	reqText.strBackUrl = "";
	reqText.strSystemType = "1010";		//系统类别
	reqText.strIdentifier="0001";	//接口标识
	reqText.strProxyHost = "";
	reqText.strProxyPort = "";	
	string strRespXml="";
	int ret = ClientJianQuan(&reqText, strRespXml);
	if (ret != OK)
	{
		return ret;
	}

	ret = ParseAuthRespXml(strRespXml, *pVdInfo);
	if (ret !=OK)
	{
		return ret;
	}
	ret = GetHisVdWithGsoap(*pVdInfo);
	if(ret == OK)
	{
        //EnterCriticalSection(&cs);
        pthread_mutex_lock(&mutex_lock);
		g_vec_Vds.push_back(pVdInfo);	//注册成功，将该路视频加入vector
        //LeaveCriticalSection(&cs);
        pthread_mutex_unlock(&mutex_lock);

		//获取视频流
        int handl = pthread_create(&pVdInfo->thId, NULL, HisClientListenThread, (void*)pVdInfo);
        if (handl != 0)
		{
			cout<<"开启接收历史视频流线程失败,摄像机编号："<<pVdInfo->cameraid<<" id编号："<<pVdInfo->id<<endl;
			return RCV_THREAD_FAIL;
		}

	//	DownloadSaveFiles(*pVdInfo);
	}

	return ret;
}

int UnRegisterHisVedioReq(string id)
{
	return UnRegisterRealVedioReq(id);
}
