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
 * ǰ������                                                                   *
\******************************************************************************/

//Ĭ�Ϸ��ؽ��
struct ns__Response
{
    int retcode;                ///< ������,0:�ɹ�������ʧ�ܣ�ʧ��ԭ����ο�strMessage;
    std::string strMessage;     ///< ������Ϣ�������쳣ʱ����
};

///< ʵʱ��Ƶ������
struct ns__HBNET_VIDEO_STREAM
{
	int              vsfStreamType;			    ///< ��Ƶ������
	char		*	 szDescription;             ///< ��Ƶ��ַ����
	char		*	 szClientIP;				///< �ͻ���IP
	int              lClientPort;			    ///< �ͻ��˶˿�
};

///< ʵʱ��Ƶ������
struct ns__HBNET_VIDEO_STREAM_RESP
{
	int              vsfStreamType;		  ///< ��Ƶ������
	char		*    szDescription;       ///< ��Ƶ��ַ����
};

///< PTZ���Ʋ���
struct ns__HBNET_CAMERA_PTZCTRL
{
	unsigned long	 ulCamNumber;			///< ��������
	unsigned long    ulVS1;
	unsigned long    ulVS2;					///< ��������
	unsigned long    ulVS3;					///< �ٶ�
	unsigned long    ulVS4;					///< �ٶ�
};

///< ¼����Ʋ���
struct ns__HBNET_RECOED_PLAYCTRL
{
	unsigned long    ulControlCode;
	unsigned long    ulInValue;
};

///< ¼���ѯ����
struct ns__HBNET_RECOED_FILECOND
{
	unsigned long    ulCamNumber;		///< ��������
	unsigned long    ulStartTime;		///< ��ʼʱ��
	unsigned long    ulStopTime;		///< ����ʱ��
};

///< �������Ϣ
struct ns__HBNET_CAMREA_INFO
{
	unsigned long	 ulCamNumber;		///< ��������
	unsigned long    ulCamID;			///< �����ID
	unsigned long    ulCamDepartmentID;	///< �������������ID
	std::string      strCamName;	    ///< ���������
};

///< �û���Ϣ
struct ns__HBUSERINFO
{
    std::string strUser;            ///< �û�
    int nPermission;                ///< Ȩ�޴�С
    int nCtrlTimeOut;               ///< Ȩ��ʱ��
};

struct ns_HeartBeat
{
    std::string     strUser;        ///< ��Ԫ�û�
    unsigned long   ulCameraID;     ///< ��������
    int             nPlayType;      ///< �������ͣ�0��ʵʱ��1����ʷ
    std::string     strFileName;    ///< ��ʷ�ļ��������ڲ���Ϊ1����Ч
};

///< ��������л�����ƵԴ
int ns__SwitchCameraToStream(struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_VIDEO_STREAM *Url);										

///< ʵʱ��Ƶ��̨����
int ns__PTZCtrlCamera(struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_CAMERA_PTZCTRL* Data, struct ns__Response *Result);											

///< ����ʵʱ��Ƶ��Դ
int ns__AbandonCameraStream(struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__Response *Result);																

///< ��ѯ��ʷ¼��
int ns__QueryVideoRecord(struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND* Param, char *&RecodeList);

///< ��ѯ��ʷ¼��URL
int ns__QueryVideoUrl(struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND* Param, char *&RecodeList);

///< ������ʷ¼��
int ns__PlayVideoRecord(struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_VIDEO_STREAM * Data, struct ns__HBNET_VIDEO_STREAM_RESP * Out );

///< ����¼��
int ns__DownloadVideoRecord(struct ns__HBUSERINFO nsUserInfo, long CamID, char * szFileName, char *&OutFileName);												

///< ����������ʷ¼��
int ns__AbandonVideoRecord(struct ns__HBUSERINFO nsUserInfo, long CamID, char* FileName, struct ns__Response *Result);

///< ��Ƶ�����������
int ns__HeartBeat(struct ns_HeartBeat nsHeartBeat, struct ns__Response *Result);

///< ϵͳ�Զ������ӿڣ�Ԥ��
int ns__AutoSysUpdate(std::string strXmlFile, struct ns__Response *Result);
   
///< ���ܲ��Խӿ� 
int ns__NetMaster(int nIsOK, int &nResult);

///< �����ϴ���
int ns__HBOperate(char * szXml, char *&szXmlRes);

///< sip����
int ns__PlayVideoRecordSIP(struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND* Param,struct ns__HBNET_VIDEO_STREAM *Url,std::string &strCallID);

///< sip����
int ns__DownloadVideoRecordSIP(struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND* Param,struct ns__HBNET_VIDEO_STREAM *Url,std::string &strCallID);

///< sipֹͣ����
int ns__AbandonVideoRecordSIP(struct ns__HBUSERINFO nsUserInfo, long CamID, std::string strCallID,struct ns__Response *Result);

///< sipֹͣ����
int ns__AbandonVideoDownSIP(struct ns__HBUSERINFO nsUserInfo, long CamID, std::string strCallID,struct ns__Response *Result);

///< sip����
int ns__CtrlVideoRecord(struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_PLAYCTRL *Pctrl,std::string strCallID,struct ns__Response *Result);

/******************************************************************************\
 *                                                                            *
 * �������ء���Ȩ����                                                         *
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
 * For CXF���                                                         *
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
