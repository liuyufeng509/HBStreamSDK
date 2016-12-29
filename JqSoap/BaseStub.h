/* BaseStub.h
   Generated by gSOAP 2.8.10 from BaseInterface.h

Copyright(C) 2000-2012, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef BaseStub_H
#define BaseStub_H
#include <vector>
#define SOAP_NAMESPACE_OF_ns1	"http://servlet.manage.haibo.com"
#define SOAP_NAMESPACE_OF_nsCXF	"http://servlet.webservice.skynet.botech.com/"
#include "stdsoap2.h"
#if GSOAP_VERSION != 20810
# error "GSOAP VERSION MISMATCH IN GENERATED CODE: PLEASE REINSTALL PACKAGE"
#endif


/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#if 0 /* volatile type: do not declare here, declared elsewhere */

#endif

#if 0 /* volatile type: do not declare here, declared elsewhere */

#endif

#ifndef SOAP_TYPE_ns__Response
#define SOAP_TYPE_ns__Response (9)
/* ns:Response */
struct ns__Response
{
public:
	int retcode;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:int */
	std::string strMessage;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__HBNET_VIDEO_STREAM
#define SOAP_TYPE_ns__HBNET_VIDEO_STREAM (11)
/* ns:HBNET-VIDEO-STREAM */
struct ns__HBNET_VIDEO_STREAM
{
public:
	int vsfStreamType;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:int */
	char *szDescription;	/* optional element of type xsd:string */
	char *szClientIP;	/* optional element of type xsd:string */
	int lClientPort;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns__HBNET_VIDEO_STREAM_RESP
#define SOAP_TYPE_ns__HBNET_VIDEO_STREAM_RESP (12)
/* ns:HBNET-VIDEO-STREAM-RESP */
struct ns__HBNET_VIDEO_STREAM_RESP
{
public:
	int vsfStreamType;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:int */
	char *szDescription;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__HBNET_CAMERA_PTZCTRL
#define SOAP_TYPE_ns__HBNET_CAMERA_PTZCTRL (13)
/* ns:HBNET-CAMERA-PTZCTRL */
struct ns__HBNET_CAMERA_PTZCTRL
{
public:
	unsigned long ulCamNumber;	/* required element of type xsd:unsignedLong */
	unsigned long ulVS1;	/* required element of type xsd:unsignedLong */
	unsigned long ulVS2;	/* required element of type xsd:unsignedLong */
	unsigned long ulVS3;	/* required element of type xsd:unsignedLong */
	unsigned long ulVS4;	/* required element of type xsd:unsignedLong */
};
#endif

#ifndef SOAP_TYPE_ns__HBNET_RECOED_PLAYCTRL
#define SOAP_TYPE_ns__HBNET_RECOED_PLAYCTRL (17)
/* ns:HBNET-RECOED-PLAYCTRL */
struct ns__HBNET_RECOED_PLAYCTRL
{
public:
	unsigned long ulControlCode;	/* required element of type xsd:unsignedLong */
	unsigned long ulInValue;	/* required element of type xsd:unsignedLong */
};
#endif

#ifndef SOAP_TYPE_ns__HBNET_RECOED_FILECOND
#define SOAP_TYPE_ns__HBNET_RECOED_FILECOND (18)
/* ns:HBNET-RECOED-FILECOND */
struct ns__HBNET_RECOED_FILECOND
{
public:
	unsigned long ulCamNumber;	/* required element of type xsd:unsignedLong */
	unsigned long ulStartTime;	/* required element of type xsd:unsignedLong */
	unsigned long ulStopTime;	/* required element of type xsd:unsignedLong */
};
#endif

#ifndef SOAP_TYPE_ns__HBNET_CAMREA_INFO
#define SOAP_TYPE_ns__HBNET_CAMREA_INFO (19)
/* ns:HBNET-CAMREA-INFO */
struct ns__HBNET_CAMREA_INFO
{
public:
	unsigned long ulCamNumber;	/* required element of type xsd:unsignedLong */
	unsigned long ulCamID;	/* required element of type xsd:unsignedLong */
	unsigned long ulCamDepartmentID;	/* required element of type xsd:unsignedLong */
	std::string strCamName;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__HBUSERINFO
#define SOAP_TYPE_ns__HBUSERINFO (20)
/* ns:HBUSERINFO */
struct ns__HBUSERINFO
{
public:
	std::string strUser;	/* required element of type xsd:string */
	int nPermission;	/* required element of type xsd:int */
	int nCtrlTimeOut;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns_HeartBeat
#define SOAP_TYPE_ns_HeartBeat (21)
/* ns-HeartBeat */
struct ns_HeartBeat
{
public:
	std::string strUser;	/* required element of type xsd:string */
	unsigned long ulCameraID;	/* required element of type xsd:unsignedLong */
	int nPlayType;	/* required element of type xsd:int */
	std::string strFileName;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__SwitchCameraToStream
#define SOAP_TYPE_ns__SwitchCameraToStream (24)
/* ns:SwitchCameraToStream */
struct ns__SwitchCameraToStream
{
public:
	struct ns__HBUSERINFO nsUserInfo;	/* required element of type ns:HBUSERINFO */
	long CamID;	/* required element of type xsd:long */
};
#endif

#ifndef SOAP_TYPE_ns__PTZCtrlCamera
#define SOAP_TYPE_ns__PTZCtrlCamera (28)
/* ns:PTZCtrlCamera */
struct ns__PTZCtrlCamera
{
public:
	struct ns__HBUSERINFO nsUserInfo;	/* required element of type ns:HBUSERINFO */
	long CamID;	/* required element of type xsd:long */
	struct ns__HBNET_CAMERA_PTZCTRL *Data;	/* optional element of type ns:HBNET-CAMERA-PTZCTRL */
};
#endif

#ifndef SOAP_TYPE_ns__AbandonCameraStream
#define SOAP_TYPE_ns__AbandonCameraStream (30)
/* ns:AbandonCameraStream */
struct ns__AbandonCameraStream
{
public:
	struct ns__HBUSERINFO nsUserInfo;	/* required element of type ns:HBUSERINFO */
	long CamID;	/* required element of type xsd:long */
};
#endif

#ifndef SOAP_TYPE_ns__QueryVideoRecordResponse
#define SOAP_TYPE_ns__QueryVideoRecordResponse (34)
/* ns:QueryVideoRecordResponse */
struct ns__QueryVideoRecordResponse
{
public:
	char *RecodeList;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__QueryVideoRecord
#define SOAP_TYPE_ns__QueryVideoRecord (35)
/* ns:QueryVideoRecord */
struct ns__QueryVideoRecord
{
public:
	struct ns__HBUSERINFO nsUserInfo;	/* required element of type ns:HBUSERINFO */
	long CamID;	/* required element of type xsd:long */
	struct ns__HBNET_RECOED_FILECOND *Param;	/* optional element of type ns:HBNET-RECOED-FILECOND */
};
#endif

#ifndef SOAP_TYPE_ns__QueryVideoUrlResponse
#define SOAP_TYPE_ns__QueryVideoUrlResponse (37)
/* ns:QueryVideoUrlResponse */
struct ns__QueryVideoUrlResponse
{
public:
	char *RecodeList;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__QueryVideoUrl
#define SOAP_TYPE_ns__QueryVideoUrl (38)
/* ns:QueryVideoUrl */
struct ns__QueryVideoUrl
{
public:
	struct ns__HBUSERINFO nsUserInfo;	/* required element of type ns:HBUSERINFO */
	long CamID;	/* required element of type xsd:long */
	struct ns__HBNET_RECOED_FILECOND *Param;	/* optional element of type ns:HBNET-RECOED-FILECOND */
};
#endif

#ifndef SOAP_TYPE_ns__PlayVideoRecord
#define SOAP_TYPE_ns__PlayVideoRecord (41)
/* ns:PlayVideoRecord */
struct ns__PlayVideoRecord
{
public:
	struct ns__HBUSERINFO nsUserInfo;	/* required element of type ns:HBUSERINFO */
	long CamID;	/* required element of type xsd:long */
	struct ns__HBNET_VIDEO_STREAM *Data;	/* optional element of type ns:HBNET-VIDEO-STREAM */
};
#endif

#ifndef SOAP_TYPE_ns__DownloadVideoRecordResponse
#define SOAP_TYPE_ns__DownloadVideoRecordResponse (43)
/* ns:DownloadVideoRecordResponse */
struct ns__DownloadVideoRecordResponse
{
public:
	char *OutFileName;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__DownloadVideoRecord
#define SOAP_TYPE_ns__DownloadVideoRecord (44)
/* ns:DownloadVideoRecord */
struct ns__DownloadVideoRecord
{
public:
	struct ns__HBUSERINFO nsUserInfo;	/* required element of type ns:HBUSERINFO */
	long CamID;	/* required element of type xsd:long */
	char *szFileName;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__AbandonVideoRecord
#define SOAP_TYPE_ns__AbandonVideoRecord (46)
/* ns:AbandonVideoRecord */
struct ns__AbandonVideoRecord
{
public:
	struct ns__HBUSERINFO nsUserInfo;	/* required element of type ns:HBUSERINFO */
	long CamID;	/* required element of type xsd:long */
	char *FileName;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__HeartBeat
#define SOAP_TYPE_ns__HeartBeat (48)
/* ns:HeartBeat */
struct ns__HeartBeat
{
public:
	struct ns_HeartBeat nsHeartBeat;	/* required element of type ns-HeartBeat */
};
#endif

#ifndef SOAP_TYPE_ns__AutoSysUpdate
#define SOAP_TYPE_ns__AutoSysUpdate (50)
/* ns:AutoSysUpdate */
struct ns__AutoSysUpdate
{
public:
	std::string strXmlFile;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__NetMasterResponse
#define SOAP_TYPE_ns__NetMasterResponse (53)
/* ns:NetMasterResponse */
struct ns__NetMasterResponse
{
public:
	int nResult;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns__NetMaster
#define SOAP_TYPE_ns__NetMaster (54)
/* ns:NetMaster */
struct ns__NetMaster
{
public:
	int nIsOK;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns__HBOperateResponse
#define SOAP_TYPE_ns__HBOperateResponse (56)
/* ns:HBOperateResponse */
struct ns__HBOperateResponse
{
public:
	char *szXmlRes;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__HBOperate
#define SOAP_TYPE_ns__HBOperate (57)
/* ns:HBOperate */
struct ns__HBOperate
{
public:
	char *szXml;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__PlayVideoRecordSIPResponse
#define SOAP_TYPE_ns__PlayVideoRecordSIPResponse (60)
/* ns:PlayVideoRecordSIPResponse */
struct ns__PlayVideoRecordSIPResponse
{
public:
	std::string strCallID;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__PlayVideoRecordSIP
#define SOAP_TYPE_ns__PlayVideoRecordSIP (61)
/* ns:PlayVideoRecordSIP */
struct ns__PlayVideoRecordSIP
{
public:
	struct ns__HBUSERINFO nsUserInfo;	/* required element of type ns:HBUSERINFO */
	long CamID;	/* required element of type xsd:long */
	struct ns__HBNET_RECOED_FILECOND *Param;	/* optional element of type ns:HBNET-RECOED-FILECOND */
	struct ns__HBNET_VIDEO_STREAM *Url;	/* optional element of type ns:HBNET-VIDEO-STREAM */
};
#endif

#ifndef SOAP_TYPE_ns__DownloadVideoRecordSIPResponse
#define SOAP_TYPE_ns__DownloadVideoRecordSIPResponse (63)
/* ns:DownloadVideoRecordSIPResponse */
struct ns__DownloadVideoRecordSIPResponse
{
public:
	std::string strCallID;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__DownloadVideoRecordSIP
#define SOAP_TYPE_ns__DownloadVideoRecordSIP (64)
/* ns:DownloadVideoRecordSIP */
struct ns__DownloadVideoRecordSIP
{
public:
	struct ns__HBUSERINFO nsUserInfo;	/* required element of type ns:HBUSERINFO */
	long CamID;	/* required element of type xsd:long */
	struct ns__HBNET_RECOED_FILECOND *Param;	/* optional element of type ns:HBNET-RECOED-FILECOND */
	struct ns__HBNET_VIDEO_STREAM *Url;	/* optional element of type ns:HBNET-VIDEO-STREAM */
};
#endif

#ifndef SOAP_TYPE_ns__AbandonVideoRecordSIP
#define SOAP_TYPE_ns__AbandonVideoRecordSIP (66)
/* ns:AbandonVideoRecordSIP */
struct ns__AbandonVideoRecordSIP
{
public:
	struct ns__HBUSERINFO nsUserInfo;	/* required element of type ns:HBUSERINFO */
	long CamID;	/* required element of type xsd:long */
	std::string strCallID;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__AbandonVideoDownSIP
#define SOAP_TYPE_ns__AbandonVideoDownSIP (68)
/* ns:AbandonVideoDownSIP */
struct ns__AbandonVideoDownSIP
{
public:
	struct ns__HBUSERINFO nsUserInfo;	/* required element of type ns:HBUSERINFO */
	long CamID;	/* required element of type xsd:long */
	std::string strCallID;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__CtrlVideoRecord
#define SOAP_TYPE_ns__CtrlVideoRecord (71)
/* ns:CtrlVideoRecord */
struct ns__CtrlVideoRecord
{
public:
	struct ns__HBUSERINFO nsUserInfo;	/* required element of type ns:HBUSERINFO */
	long CamID;	/* required element of type xsd:long */
	struct ns__HBNET_RECOED_PLAYCTRL *Pctrl;	/* optional element of type ns:HBNET-RECOED-PLAYCTRL */
	std::string strCallID;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE__ns1__getData
#define SOAP_TYPE__ns1__getData (72)
/* ns1:getData */
class SOAP_CMAC _ns1__getData
{
public:
	std::string *in0;	/* required element of type xsd:string */
	std::string *in1;	/* required element of type xsd:string */
	std::string *in2;	/* required element of type xsd:string */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 72; } /* = unique id SOAP_TYPE__ns1__getData */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__getData() { _ns1__getData::soap_default(NULL); }
	virtual ~_ns1__getData() { }
};
#endif

#ifndef SOAP_TYPE__ns1__getDataResponse
#define SOAP_TYPE__ns1__getDataResponse (73)
/* ns1:getDataResponse */
class SOAP_CMAC _ns1__getDataResponse
{
public:
	std::string *out;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:string */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 73; } /* = unique id SOAP_TYPE__ns1__getDataResponse */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__getDataResponse() { _ns1__getDataResponse::soap_default(NULL); }
	virtual ~_ns1__getDataResponse() { }
};
#endif

#ifndef SOAP_TYPE___ns1__getData
#define SOAP_TYPE___ns1__getData (79)
/* Operation wrapper: */
struct __ns1__getData
{
public:
	_ns1__getData *ns1__getData;	/* optional element of type ns1:getData */
};
#endif

#ifndef SOAP_TYPE_nsCXF__getDataCxf
#define SOAP_TYPE_nsCXF__getDataCxf (80)
/* nsCXF:getDataCxf */
class SOAP_CMAC nsCXF__getDataCxf
{
public:
	std::string *arg0;	/* optional element of type xsd:string */
	std::string *arg1;	/* optional element of type xsd:string */
	std::string *arg2;	/* optional element of type xsd:string */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 80; } /* = unique id SOAP_TYPE_nsCXF__getDataCxf */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         nsCXF__getDataCxf() { nsCXF__getDataCxf::soap_default(NULL); }
	virtual ~nsCXF__getDataCxf() { }
};
#endif

#ifndef SOAP_TYPE_nsCXF__getDataCxfResponse
#define SOAP_TYPE_nsCXF__getDataCxfResponse (81)
/* nsCXF:getDataCxfResponse */
class SOAP_CMAC nsCXF__getDataCxfResponse
{
public:
	std::string *return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:string */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 81; } /* = unique id SOAP_TYPE_nsCXF__getDataCxfResponse */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         nsCXF__getDataCxfResponse() { nsCXF__getDataCxfResponse::soap_default(NULL); }
	virtual ~nsCXF__getDataCxfResponse() { }
};
#endif

#ifndef SOAP_TYPE___nsCXF__getDataCxf
#define SOAP_TYPE___nsCXF__getDataCxf (85)
/* Operation wrapper: */
struct __nsCXF__getDataCxf
{
public:
	nsCXF__getDataCxf *nsCXF__getDataCxf_;	/* optional element of type nsCXF:getDataCxf */
};
#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (86)
/* SOAP Header: */
struct SOAP_ENV__Header
{
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (87)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
public:
	char *SOAP_ENV__Value;	/* optional element of type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (89)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
public:
	char *__any;
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (92)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
public:
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (93)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
public:
	char *faultcode;	/* optional element of type xsd:QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
};
#endif

#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (6)
typedef char *_XML;
#endif

#ifndef SOAP_TYPE__xsd__schema
#define SOAP_TYPE__xsd__schema (8)
typedef char *_xsd__schema;
#endif


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Server-Side Operations                                                     *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 ns__SwitchCameraToStream(struct soap*, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_VIDEO_STREAM *Url);

SOAP_FMAC5 int SOAP_FMAC6 ns__PTZCtrlCamera(struct soap*, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_CAMERA_PTZCTRL *Data, struct ns__Response *Result);

SOAP_FMAC5 int SOAP_FMAC6 ns__AbandonCameraStream(struct soap*, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__Response *Result);

SOAP_FMAC5 int SOAP_FMAC6 ns__QueryVideoRecord(struct soap*, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND *Param, char *&RecodeList);

SOAP_FMAC5 int SOAP_FMAC6 ns__QueryVideoUrl(struct soap*, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND *Param, char *&RecodeList);

SOAP_FMAC5 int SOAP_FMAC6 ns__PlayVideoRecord(struct soap*, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_VIDEO_STREAM *Data, struct ns__HBNET_VIDEO_STREAM_RESP *Out);

SOAP_FMAC5 int SOAP_FMAC6 ns__DownloadVideoRecord(struct soap*, struct ns__HBUSERINFO nsUserInfo, long CamID, char *szFileName, char *&OutFileName);

SOAP_FMAC5 int SOAP_FMAC6 ns__AbandonVideoRecord(struct soap*, struct ns__HBUSERINFO nsUserInfo, long CamID, char *FileName, struct ns__Response *Result);

SOAP_FMAC5 int SOAP_FMAC6 ns__HeartBeat(struct soap*, struct ns_HeartBeat nsHeartBeat, struct ns__Response *Result);

SOAP_FMAC5 int SOAP_FMAC6 ns__AutoSysUpdate(struct soap*, std::string strXmlFile, struct ns__Response *Result);

SOAP_FMAC5 int SOAP_FMAC6 ns__NetMaster(struct soap*, int nIsOK, int &nResult);

SOAP_FMAC5 int SOAP_FMAC6 ns__HBOperate(struct soap*, char *szXml, char *&szXmlRes);

SOAP_FMAC5 int SOAP_FMAC6 ns__PlayVideoRecordSIP(struct soap*, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND *Param, struct ns__HBNET_VIDEO_STREAM *Url, std::string &strCallID);

SOAP_FMAC5 int SOAP_FMAC6 ns__DownloadVideoRecordSIP(struct soap*, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND *Param, struct ns__HBNET_VIDEO_STREAM *Url, std::string &strCallID);

SOAP_FMAC5 int SOAP_FMAC6 ns__AbandonVideoRecordSIP(struct soap*, struct ns__HBUSERINFO nsUserInfo, long CamID, std::string strCallID, struct ns__Response *Result);

SOAP_FMAC5 int SOAP_FMAC6 ns__AbandonVideoDownSIP(struct soap*, struct ns__HBUSERINFO nsUserInfo, long CamID, std::string strCallID, struct ns__Response *Result);

SOAP_FMAC5 int SOAP_FMAC6 ns__CtrlVideoRecord(struct soap*, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_PLAYCTRL *Pctrl, std::string strCallID, struct ns__Response *Result);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__getData(struct soap*, _ns1__getData *ns1__getData, _ns1__getDataResponse *ns1__getDataResponse);

SOAP_FMAC5 int SOAP_FMAC6 __nsCXF__getDataCxf(struct soap*, nsCXF__getDataCxf *nsCXF__getDataCxf_, nsCXF__getDataCxfResponse *nsCXF__getDataCxfResponse_);

/******************************************************************************\
 *                                                                            *
 * Server-Side Skeletons to Invoke Service Operations                         *
 *                                                                            *
\******************************************************************************/

SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__SwitchCameraToStream(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__PTZCtrlCamera(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__AbandonCameraStream(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__QueryVideoRecord(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__QueryVideoUrl(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__PlayVideoRecord(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__DownloadVideoRecord(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__AbandonVideoRecord(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__HeartBeat(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__AutoSysUpdate(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__NetMaster(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__HBOperate(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__PlayVideoRecordSIP(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__DownloadVideoRecordSIP(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__AbandonVideoRecordSIP(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__AbandonVideoDownSIP(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__CtrlVideoRecord(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__getData(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___nsCXF__getDataCxf(struct soap*);

/******************************************************************************\
 *                                                                            *
 * Client-Side Call Stubs                                                     *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__SwitchCameraToStream(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_VIDEO_STREAM *Url);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__PTZCtrlCamera(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_CAMERA_PTZCTRL *Data, struct ns__Response *Result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__AbandonCameraStream(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__Response *Result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__QueryVideoRecord(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND *Param, char *&RecodeList);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__QueryVideoUrl(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND *Param, char *&RecodeList);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__PlayVideoRecord(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_VIDEO_STREAM *Data, struct ns__HBNET_VIDEO_STREAM_RESP *Out);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__DownloadVideoRecord(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, char *szFileName, char *&OutFileName);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__AbandonVideoRecord(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, char *FileName, struct ns__Response *Result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__HeartBeat(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns_HeartBeat nsHeartBeat, struct ns__Response *Result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__AutoSysUpdate(struct soap *soap, const char *soap_endpoint, const char *soap_action, std::string strXmlFile, struct ns__Response *Result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__NetMaster(struct soap *soap, const char *soap_endpoint, const char *soap_action, int nIsOK, int &nResult);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__HBOperate(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *szXml, char *&szXmlRes);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__PlayVideoRecordSIP(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND *Param, struct ns__HBNET_VIDEO_STREAM *Url, std::string &strCallID);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__DownloadVideoRecordSIP(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND *Param, struct ns__HBNET_VIDEO_STREAM *Url, std::string &strCallID);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__AbandonVideoRecordSIP(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, std::string strCallID, struct ns__Response *Result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__AbandonVideoDownSIP(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, std::string strCallID, struct ns__Response *Result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__CtrlVideoRecord(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_PLAYCTRL *Pctrl, std::string strCallID, struct ns__Response *Result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__getData(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__getData *ns1__getData, _ns1__getDataResponse *ns1__getDataResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___nsCXF__getDataCxf(struct soap *soap, const char *soap_endpoint, const char *soap_action, nsCXF__getDataCxf *nsCXF__getDataCxf_, nsCXF__getDataCxfResponse *nsCXF__getDataCxfResponse_);

#endif

/* End of BaseStub.h */
