//gsoap ns service name:	intcommon service
//gsoap ns service style:	rpc
//gsoap ns service encoding:	encoded
//gsoap ns service namespace:	http://127.0.0.1:8086/live.wsdl
//gsoap ns service location:	http://127.0.0.1:8086/live.fcgi
//gsoap ns schema namespace:	http://haibogroup.com.cn

// STL vector containers (use option -s to remove STL dependency)
#import "stlvector.h"

typedef _XML _xsd__schema;

/******************************************************************************\
 * 前导声明                                                                   *
\******************************************************************************/

//默认返回结果
struct ns__Response
{
    int retcode;                ///< 返因码,0:成功，其他失败，失败原因请参考strMessage;
    std::string strMessage;     ///< 错误信息，仅在异常时存在
};

///< 实时视频流参数
struct ns__HBNET_VIDEO_STREAM
{
	int              vsfStreamType;			    ///< 视频流类型
	char		*	 szDescription;             ///< 视频地址描述
	char		*	 szClientIP;				///< 客户端IP
	int              lClientPort;			    ///< 客户端端口
};

///< 实时视频流参数
struct ns__HBNET_VIDEO_STREAM_RESP
{
	int              vsfStreamType;		  ///< 视频流类型
	char		*    szDescription;       ///< 视频地址描述
};

///< PTZ控制参数
struct ns__HBNET_CAMERA_PTZCTRL
{
	unsigned long	 ulCamNumber;			///< 摄像机编号
	unsigned long    ulVS1;
	unsigned long    ulVS2;					///< 控制类型
	unsigned long    ulVS3;					///< 速度
	unsigned long    ulVS4;					///< 速度
};

///< 录像控制参数
struct ns__HBNET_RECOED_PLAYCTRL
{
	unsigned long    ulControlCode;
	unsigned long    ulInValue;
};

///< 录像查询条件
struct ns__HBNET_RECOED_FILECOND
{
	unsigned long    ulCamNumber;		///< 摄像机编号
	unsigned long    ulStartTime;		///< 开始时间
	unsigned long    ulStopTime;		///< 结束时间
};

///< 摄像机信息
struct ns__HBNET_CAMREA_INFO
{
	unsigned long	 ulCamNumber;		///< 摄像机编号
	unsigned long    ulCamID;			///< 摄像机ID
	unsigned long    ulCamDepartmentID;	///< 摄像机所属部门ID
	std::string      strCamName;	    ///< 摄像机名称
};

///< 用户信息
struct ns__HBUSERINFO
{
    std::string strUser;            ///< 用户
    int nPermission;                ///< 权限大小
    int nCtrlTimeOut;               ///< 权限时长
};

struct ns_HeartBeat
{
    std::string     strUser;        ///< 单元用户
    unsigned long   ulCameraID;     ///< 摄像机编号
    int             nPlayType;      ///< 播放类型，0：实时，1：历史
    std::string     strFileName;    ///< 历史文件名，仅在播放为1是有效
};

///< 将摄像机切换到视频源
int ns__SwitchCameraToStream(struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_VIDEO_STREAM *Url);										

///< 实时视频云台控制
int ns__PTZCtrlCamera(struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_CAMERA_PTZCTRL* Data, struct ns__Response *Result);											

///< 放弃实时视频资源
int ns__AbandonCameraStream(struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__Response *Result);																

///< 查询历史录像
int ns__QueryVideoRecord(struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND* Param, char *&RecodeList);

///< 查询历史录像URL
int ns__QueryVideoUrl(struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND* Param, char *&RecodeList);

///< 播放历史录像
int ns__PlayVideoRecord(struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_VIDEO_STREAM * Data, struct ns__HBNET_VIDEO_STREAM_RESP * Out );

///< 下载录像
int ns__DownloadVideoRecord(struct ns__HBUSERINFO nsUserInfo, long CamID, char * szFileName, char *&OutFileName);												

///< 放弃播放历史录像
int ns__AbandonVideoRecord(struct ns__HBUSERINFO nsUserInfo, long CamID, char* FileName, struct ns__Response *Result);

///< 视频监控心跳处理
int ns__HeartBeat(struct ns_HeartBeat nsHeartBeat, struct ns__Response *Result);

///< 系统自动升级接口，预留
int ns__AutoSysUpdate(std::string strXmlFile, struct ns__Response *Result);
   
///< 网管测试接口 
int ns__NetMaster(int nIsOK, int &nResult);

///< 海信上大屏
int ns__HBOperate(char * szXml, char *&szXmlRes);

///< sip播放
int ns__PlayVideoRecordSIP(struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND* Param,struct ns__HBNET_VIDEO_STREAM *Url,std::string &strCallID);

///< sip下载
int ns__DownloadVideoRecordSIP(struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND* Param,struct ns__HBNET_VIDEO_STREAM *Url,std::string &strCallID);

///< sip停止播放
int ns__AbandonVideoRecordSIP(struct ns__HBUSERINFO nsUserInfo, long CamID, std::string strCallID,struct ns__Response *Result);

///< sip停止下载
int ns__AbandonVideoDownSIP(struct ns__HBUSERINFO nsUserInfo, long CamID, std::string strCallID,struct ns__Response *Result);

///< sip控制
int ns__CtrlVideoRecord(struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_PLAYCTRL *Pctrl,std::string strCallID,struct ns__Response *Result);

/******************************************************************************\
 *                                                                            *
 * 配置下载、鉴权服务                                                         *
 *                                                                            *
\******************************************************************************/

#define SOAP_NAMESPACE_OF_ns1	"http://servlet.manage.haibo.com"
//gsoap ns1   schema namespace:	http://servlet.manage.haibo.com
//gsoap ns1   schema form:	qualified

//  Forward declaration of class _ns1__getData.
class _ns1__getData;

//  Forward declaration of class _ns1__getDataResponse.
class _ns1__getDataResponse;

/// Top-level root element "http://servlet.manage.haibo.com":getData

/// "http://servlet.manage.haibo.com":getData is a complexType.
class _ns1__getData
{ public:
/// Element in0 of type xs:string.
    std::string*                         in0                            1;	///< Nullable pointer.
/// Element in1 of type xs:string.
    std::string*                         in1                            1;	///< Nullable pointer.
/// Element in2 of type xs:string.
    std::string*                         in2                            1;	///< Nullable pointer.
/// A handle to the soap struct that manages this instance (automatically set)
    struct soap                         *soap                          ;
};

/// Top-level root element "http://servlet.manage.haibo.com":getDataResponse

/// "http://servlet.manage.haibo.com":getDataResponse is a complexType.
class _ns1__getDataResponse
{ public:
/// Element out of type xs:string.
    std::string*                         out                            1;	///< Nullable pointer.
/// A handle to the soap struct that manages this instance (automatically set)
    struct soap                         *soap                          ;
};

//gsoap ns1  service name:	JqServiceHttpBinding 
//gsoap ns1  service type:	JqServicePortType 
//gsoap ns1  service namespace:	http://servlet.manage.haibo.com 
//gsoap ns1  service transport:	http://schemas.xmlsoap.org/soap/http 

//gsoap ns1  service method-style:	getData document
//gsoap ns1  service method-encoding:	getData literal
//gsoap ns1  service method-action:	getData ""
//gsoap ns1  service method-output-action:	getData http://servlet.manage.haibo.com/JqServicePortType/getDataResponse
int __ns1__getData(
    _ns1__getData*                      ns1__getData,	///< Request parameter
    _ns1__getDataResponse*              ns1__getDataResponse	///< Response parameter
);

/******************************************************************************\
 *                                                                            *
 * For CXF框架                                                         *
 *                                                                            *
\******************************************************************************/

//gsoapopt w

#define SOAP_NAMESPACE_OF_nsCXF	"http://servlet.webservice.skynet.botech.com/"
//gsoap nsCXF   schema namespace:	http://servlet.webservice.skynet.botech.com/
//gsoap nsCXF   schema form:	unqualified

//  Forward declaration of class nsCXF__getDataCxf.
class nsCXF__getDataCxf;

//  Forward declaration of class nsCXF__getDataCxfResponse.
class nsCXF__getDataCxfResponse;

/// "http://servlet.webservice.skynet.botech.com/":getDataCxf is a complexType.
class nsCXF__getDataCxf
{ public:
/// Element arg0 of type xs:string.
std::string*                         arg0                           0;	///< Optional element.
/// Element arg1 of type xs:string.
std::string*                         arg1                           0;	///< Optional element.
/// Element arg2 of type xs:string.
std::string*                         arg2                           0;	///< Optional element.
/// A handle to the soap struct that manages this instance (automatically set)
struct soap                         *soap                          ;
};

/// "http://servlet.webservice.skynet.botech.com/":getDataCxfResponse is a complexType.
class nsCXF__getDataCxfResponse
{ public:
/// Element return of type xs:string.
std::string*                         return_                        0;	///< Optional element.
/// A handle to the soap struct that manages this instance (automatically set)
struct soap                         *soap                          ;
};

//gsoap nsCXF  service name:	PzServiceImplServiceSoapBinding 
//gsoap nsCXF  service type:	IPzService 
//gsoap nsCXF  service namespace:	http://servlet.webservice.skynet.botech.com/ 
//gsoap nsCXF  service transport:	http://schemas.xmlsoap.org/soap/http 

//gsoap nsCXF  service method-style:	getDataCxf document
//gsoap nsCXF  service method-encoding:	getDataCxf literal
//gsoap nsCXF  service method-action:	getDataCxf ""
//gsoap nsCXF  service method-output-action:	getDataCxf http://servlet.webservice.skynet.botech.com//IPzService/getDataCxfResponse
int __nsCXF__getDataCxf(
	nsCXF__getDataCxf*                    nsCXF__getDataCxf_,	///< Request parameter
	nsCXF__getDataCxfResponse*            nsCXF__getDataCxfResponse_	///< Response parameter
);
