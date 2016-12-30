#ifndef COMMON_H
#define COMMON_H
#include "errorno.h"
#include <vector>
#include "testdll_global.h"

#ifdef WIN32
#include "afxmt.h"
#include <afxinet.h>
#include <WinSock2.h>
#else
#include<arpa/inet.h>
#include <semaphore.h>
#include <pthread.h>
#endif
#include<string.h>
#include <stdlib.h>
 #include <stdio.h>
#include<iostream>
using namespace std;

//#define RealSend 
//#define HisSend

#define  BUFF_LEN	1024*1024*2
#define  CONFIG_FILE  "./config.ini"
#define  MAX_VDS	   32
#define MAX_READ_BUF 1*1024*1024
#define MAX_FRAME_SIZE 2*1024*1024
#define MAX_MTU_LEN 1400

#ifdef WIN32
#else
#define MAX_PATH          260
#endif
#define PS_NA 96

const unsigned int timestamp_increse=3600;
#ifdef WIN32
const unsigned long csrc=htonl(10);
#else
const unsigned int csrc=htonl(10);
#endif

//全局结构体
typedef struct _RequestText
{
	std::string strUser;            //用户名
	std::string strPass;            //密码
	std::string strUserType;        //单元类型
	std::string strActionType;      //操作类型
	std::string strCameraNumber;    //摄像机编号
	std::string strUrl;             //请求地址
	std::string strBackUrl;         //备用鉴权URL
	std::string strSystemType;      //系统类别
	std::string strIdentifier;      //接口标识
	std::string strProxyHost;       //代码服务器地址
	std::string strProxyPort;       //代理服务器端口
}RequestText;

struct NET_RECOED_FILE
{
	unsigned long ulStartTime;
	unsigned long ulStopTime;
	unsigned long ulFileSize;
	int		 vsfStreamType;
	string	url;
};

struct VedioInfo
{
	VedioInfo():id(""),cameraid(""),isHis(false),isStop(true)
	{
	}

	string id;			//唯一编号
	string cameraid;
	string soapURL;
	string udpURL;		//组播地址
	CallBackFun callbackFun;
	bool	isHis;
	bool	isStop;		//是否停止接收流
	//unsigned     threadID;
#ifdef WIN32
    CEvent g_event;			//用于等待线程结束
#else
    pthread_t   thId;			//用于等待线程结束
#endif

	time_t  beg;
	time_t  end;		//历史录像的起止时间
	vector<NET_RECOED_FILE> hisInfos;		//历史录像的url
};
//解码参数
#ifndef WIN32
struct DecParam
{
    DecParam()
    {
        //Temp = new unsigned char[MAX_READ_BUF];
        Number = 1;
        NeedHalf = false;
        nextpos = 0;
        halflen=0;
        OneFrameBuf = new char[MAX_FRAME_SIZE];
        buffer = new char[MAX_READ_BUF+1024*1024];
        memset(buffer, 0, MAX_READ_BUF+1024*1024);
        pbuffer = buffer;
        curlen = 0;
        ts_current = 0;
        seq_num = 0;
        memset(sendbuf, 0, sizeof(sendbuf));
    }
    bool append(void *p , int len)
    {
       // cout<<"curlen="<<curlen<<endl;
        memcpy(pbuffer, p, len);
        pbuffer = pbuffer+len;
        curlen += len;
        if(curlen>=MAX_READ_BUF)
        {
            pbuffer = buffer;
           // cout<<"append false"<<curlen<<endl;
            return false;
        }
        //cout<<"append true"<<curlen<<endl;
        return true;
    }

    ~DecParam()
    {
       // delete Temp;
        delete OneFrameBuf;
        delete buffer;
    }

    //unsigned char *Temp;
    unsigned long Number;
    bool NeedHalf;
    int nextpos;
    int halflen;
    char *OneFrameBuf;
    char *buffer;
    char *pbuffer;
    int  curlen;
    unsigned int ts_current;
    unsigned short seq_num;
    unsigned char sendbuf[1500];
    VedioInfo *pvdInfo;
   // FILE *fd;
};
#endif

//解码用的结构体
typedef struct 
{
	/**//* byte 0 */
	unsigned char csrc_len:4;		/**//* expect 0 */
	unsigned char extension:1;		/**//* expect 1, see RTP_OP below */
	unsigned char padding:1;		/**//* expect 0 */
	unsigned char version:2;		/**//* expect 2 */
	/**//* byte 1 */
	unsigned char payload:7;		/**//* RTP_PAYLOAD_RTSP */
	unsigned char marker:1;			/**//* expect 1 */
	/**//* bytes 2, 3 */
	unsigned short seq_no;

#ifdef WIN32
    /**//* bytes 4-7 */
    unsigned long timestamp;
    /**//* bytes 8-11 */
    unsigned long ssrc;            /**//* stream number is used here. */
#else
    /**//* bytes 4-7 */
    unsigned int timestamp;
    /**//* bytes 8-11 */
    unsigned int ssrc;            /**//* stream number is used here. */
#endif

} RTP_FIXED_HEADER;



extern vector<VedioInfo*> g_vec_Vds;
extern RequestText g_reqText;		//鉴权服务器信息
#ifdef WIN32
extern CRITICAL_SECTION cs;
#else
extern pthread_mutex_t   mutex_lock;
extern int uuid;
#endif

int ReadConfig();	//读取鉴权服务器等信息
string GetUUID();	//获取uuid,标识唯一一路摄像机

std::string MakeReqXml(RequestText * reqText);
int ParseAuthRespXml(std::string &strAuthRespXml,  VedioInfo &relVd);

int ClientJianQuan(RequestText *reqTex, std::string & strRespXml);

int InitSoap(struct soap * soap, const char * szProxyHost, const char * szProxyPort);
int GetRelVdWithGsoap(VedioInfo &relVd);
int GetHisVdWithGsoap(VedioInfo &hisVd);
void *MulTranUni(void *arg); 

int DestorySoap(struct soap * soap);

bool DownloadSaveFiles(VedioInfo &hisVd);
#ifdef WIN32
unsigned __stdcall ClientListenThread(void *pParam);
unsigned __stdcall HisClientListenThread(void *pParam);
unsigned __stdcall HeartBeat(void *pParam);
#else
void * ClientListenThread(void *pParam);
void * HisClientListenThread(void *pParam);
void * HeartBeat(void *pParam);
#endif

int NalFrame(unsigned int& ts_current, unsigned short& seq_num, unsigned char* src, int len, bool isFramem, int& halflen, char* OneFrameBuf, unsigned char* sendbuf, VedioInfo &vdInfo);
int GetRtp(int srclen,char* OneFrameBuf, unsigned short& seq_num, unsigned int& ts_current, unsigned char* sendbuf, VedioInfo &vdInfo);
void incCpu();

#endif 
