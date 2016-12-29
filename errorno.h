#ifndef ERRORNO_H
#define ERRORNO_H

enum ERRORNO
{
	OK,				//成功
	USER_NULL=1,	//鉴权服务用户名为空
	PWD_NULL,		//鉴权服务密码为空
	IP_ERROR,		//鉴权服务的ip格式错误
	PORT_ERROR,		//健全服务器的port错误
	VD_NUM_OVER,	//视频路数超过32路
	CAMRID_NULL,	//传入的摄像机id为空
	CALL_BACK_NULL,	//回调函数未注册
	JQ_URL_ERROR,	//鉴权服务的url错误
	JQ_REQ_FAIL,	//鉴权请求失败
	SOAP_FAIL,		//调看实时视频失败
	RCV_THREAD_FAIL, //接收实时视频流线程开启失败
	HEART_THREAD_FAIL,//心跳线程启动失败
	HIS_URL_NULL,		//历史录像路径为空
	HIS_URL_PARSE_FAIL, //历史路径解析失败
};

#endif
