/* BaseClient.cpp
   Generated by gSOAP 2.8.10 from BaseInterface.h

Copyright(C) 2000-2012, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "BaseH.h"

SOAP_SOURCE_STAMP("@(#) BaseClient.cpp ver 2.8.10 2016-11-25 01:29:21 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__SwitchCameraToStream(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_VIDEO_STREAM *Url)
{	struct ns__SwitchCameraToStream soap_tmp_ns__SwitchCameraToStream;
	if (!soap_endpoint)
		soap_endpoint = "http://127.0.0.1:8086/live.fcgi";
	soap->encodingStyle = "";
	soap_tmp_ns__SwitchCameraToStream.nsUserInfo = nsUserInfo;
	soap_tmp_ns__SwitchCameraToStream.CamID = CamID;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__SwitchCameraToStream(soap, &soap_tmp_ns__SwitchCameraToStream);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__SwitchCameraToStream(soap, &soap_tmp_ns__SwitchCameraToStream, "ns:SwitchCameraToStream", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__SwitchCameraToStream(soap, &soap_tmp_ns__SwitchCameraToStream, "ns:SwitchCameraToStream", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!Url)
		return soap_closesock(soap);
	soap_default_ns__HBNET_VIDEO_STREAM(soap, Url);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns__HBNET_VIDEO_STREAM(soap, Url, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__PTZCtrlCamera(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_CAMERA_PTZCTRL *Data, struct ns__Response *Result)
{	struct ns__PTZCtrlCamera soap_tmp_ns__PTZCtrlCamera;
	if (!soap_endpoint)
		soap_endpoint = "http://127.0.0.1:8086/live.fcgi";
	soap->encodingStyle = "";
	soap_tmp_ns__PTZCtrlCamera.nsUserInfo = nsUserInfo;
	soap_tmp_ns__PTZCtrlCamera.CamID = CamID;
	soap_tmp_ns__PTZCtrlCamera.Data = Data;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__PTZCtrlCamera(soap, &soap_tmp_ns__PTZCtrlCamera);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__PTZCtrlCamera(soap, &soap_tmp_ns__PTZCtrlCamera, "ns:PTZCtrlCamera", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__PTZCtrlCamera(soap, &soap_tmp_ns__PTZCtrlCamera, "ns:PTZCtrlCamera", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!Result)
		return soap_closesock(soap);
	soap_default_ns__Response(soap, Result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns__Response(soap, Result, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__AbandonCameraStream(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__Response *Result)
{	struct ns__AbandonCameraStream soap_tmp_ns__AbandonCameraStream;
	if (!soap_endpoint)
		soap_endpoint = "http://127.0.0.1:8086/live.fcgi";
	soap->encodingStyle = "";
	soap_tmp_ns__AbandonCameraStream.nsUserInfo = nsUserInfo;
	soap_tmp_ns__AbandonCameraStream.CamID = CamID;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__AbandonCameraStream(soap, &soap_tmp_ns__AbandonCameraStream);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__AbandonCameraStream(soap, &soap_tmp_ns__AbandonCameraStream, "ns:AbandonCameraStream", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__AbandonCameraStream(soap, &soap_tmp_ns__AbandonCameraStream, "ns:AbandonCameraStream", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!Result)
		return soap_closesock(soap);
	soap_default_ns__Response(soap, Result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns__Response(soap, Result, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__QueryVideoRecord(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND *Param, char *&RecodeList)
{	struct ns__QueryVideoRecord soap_tmp_ns__QueryVideoRecord;
	struct ns__QueryVideoRecordResponse *soap_tmp_ns__QueryVideoRecordResponse;
	if (!soap_endpoint)
		soap_endpoint = "http://127.0.0.1:8086/live.fcgi";
	soap->encodingStyle = "";
	soap_tmp_ns__QueryVideoRecord.nsUserInfo = nsUserInfo;
	soap_tmp_ns__QueryVideoRecord.CamID = CamID;
	soap_tmp_ns__QueryVideoRecord.Param = Param;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__QueryVideoRecord(soap, &soap_tmp_ns__QueryVideoRecord);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__QueryVideoRecord(soap, &soap_tmp_ns__QueryVideoRecord, "ns:QueryVideoRecord", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__QueryVideoRecord(soap, &soap_tmp_ns__QueryVideoRecord, "ns:QueryVideoRecord", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	RecodeList = NULL;
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__QueryVideoRecordResponse = soap_get_ns__QueryVideoRecordResponse(soap, NULL, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	RecodeList = soap_tmp_ns__QueryVideoRecordResponse->RecodeList;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__QueryVideoUrl(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND *Param, char *&RecodeList)
{	struct ns__QueryVideoUrl soap_tmp_ns__QueryVideoUrl;
	struct ns__QueryVideoUrlResponse *soap_tmp_ns__QueryVideoUrlResponse;
	if (!soap_endpoint)
		soap_endpoint = "http://127.0.0.1:8086/live.fcgi";
	soap->encodingStyle = "";
	soap_tmp_ns__QueryVideoUrl.nsUserInfo = nsUserInfo;
	soap_tmp_ns__QueryVideoUrl.CamID = CamID;
	soap_tmp_ns__QueryVideoUrl.Param = Param;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__QueryVideoUrl(soap, &soap_tmp_ns__QueryVideoUrl);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__QueryVideoUrl(soap, &soap_tmp_ns__QueryVideoUrl, "ns:QueryVideoUrl", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__QueryVideoUrl(soap, &soap_tmp_ns__QueryVideoUrl, "ns:QueryVideoUrl", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	RecodeList = NULL;
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__QueryVideoUrlResponse = soap_get_ns__QueryVideoUrlResponse(soap, NULL, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	RecodeList = soap_tmp_ns__QueryVideoUrlResponse->RecodeList;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__PlayVideoRecord(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_VIDEO_STREAM *Data, struct ns__HBNET_VIDEO_STREAM_RESP *Out)
{	struct ns__PlayVideoRecord soap_tmp_ns__PlayVideoRecord;
	if (!soap_endpoint)
		soap_endpoint = "http://127.0.0.1:8086/live.fcgi";
	soap->encodingStyle = "";
	soap_tmp_ns__PlayVideoRecord.nsUserInfo = nsUserInfo;
	soap_tmp_ns__PlayVideoRecord.CamID = CamID;
	soap_tmp_ns__PlayVideoRecord.Data = Data;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__PlayVideoRecord(soap, &soap_tmp_ns__PlayVideoRecord);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__PlayVideoRecord(soap, &soap_tmp_ns__PlayVideoRecord, "ns:PlayVideoRecord", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__PlayVideoRecord(soap, &soap_tmp_ns__PlayVideoRecord, "ns:PlayVideoRecord", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!Out)
		return soap_closesock(soap);
	soap_default_ns__HBNET_VIDEO_STREAM_RESP(soap, Out);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns__HBNET_VIDEO_STREAM_RESP(soap, Out, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__DownloadVideoRecord(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, char *szFileName, char *&OutFileName)
{	struct ns__DownloadVideoRecord soap_tmp_ns__DownloadVideoRecord;
	struct ns__DownloadVideoRecordResponse *soap_tmp_ns__DownloadVideoRecordResponse;
	if (!soap_endpoint)
		soap_endpoint = "http://127.0.0.1:8086/live.fcgi";
	soap->encodingStyle = "";
	soap_tmp_ns__DownloadVideoRecord.nsUserInfo = nsUserInfo;
	soap_tmp_ns__DownloadVideoRecord.CamID = CamID;
	soap_tmp_ns__DownloadVideoRecord.szFileName = szFileName;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__DownloadVideoRecord(soap, &soap_tmp_ns__DownloadVideoRecord);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__DownloadVideoRecord(soap, &soap_tmp_ns__DownloadVideoRecord, "ns:DownloadVideoRecord", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__DownloadVideoRecord(soap, &soap_tmp_ns__DownloadVideoRecord, "ns:DownloadVideoRecord", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	OutFileName = NULL;
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__DownloadVideoRecordResponse = soap_get_ns__DownloadVideoRecordResponse(soap, NULL, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	OutFileName = soap_tmp_ns__DownloadVideoRecordResponse->OutFileName;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__AbandonVideoRecord(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, char *FileName, struct ns__Response *Result)
{	struct ns__AbandonVideoRecord soap_tmp_ns__AbandonVideoRecord;
	if (!soap_endpoint)
		soap_endpoint = "http://127.0.0.1:8086/live.fcgi";
	soap->encodingStyle = "";
	soap_tmp_ns__AbandonVideoRecord.nsUserInfo = nsUserInfo;
	soap_tmp_ns__AbandonVideoRecord.CamID = CamID;
	soap_tmp_ns__AbandonVideoRecord.FileName = FileName;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__AbandonVideoRecord(soap, &soap_tmp_ns__AbandonVideoRecord);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__AbandonVideoRecord(soap, &soap_tmp_ns__AbandonVideoRecord, "ns:AbandonVideoRecord", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__AbandonVideoRecord(soap, &soap_tmp_ns__AbandonVideoRecord, "ns:AbandonVideoRecord", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!Result)
		return soap_closesock(soap);
	soap_default_ns__Response(soap, Result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns__Response(soap, Result, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__HeartBeat(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns_HeartBeat nsHeartBeat, struct ns__Response *Result)
{	struct ns__HeartBeat soap_tmp_ns__HeartBeat;
	if (!soap_endpoint)
		soap_endpoint = "http://127.0.0.1:8086/live.fcgi";
	soap->encodingStyle = "";
	soap_tmp_ns__HeartBeat.nsHeartBeat = nsHeartBeat;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__HeartBeat(soap, &soap_tmp_ns__HeartBeat);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__HeartBeat(soap, &soap_tmp_ns__HeartBeat, "ns:HeartBeat", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__HeartBeat(soap, &soap_tmp_ns__HeartBeat, "ns:HeartBeat", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!Result)
		return soap_closesock(soap);
	soap_default_ns__Response(soap, Result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns__Response(soap, Result, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__AutoSysUpdate(struct soap *soap, const char *soap_endpoint, const char *soap_action, std::string strXmlFile, struct ns__Response *Result)
{	struct ns__AutoSysUpdate soap_tmp_ns__AutoSysUpdate;
	if (!soap_endpoint)
		soap_endpoint = "http://127.0.0.1:8086/live.fcgi";
	soap->encodingStyle = "";
	soap_tmp_ns__AutoSysUpdate.strXmlFile = strXmlFile;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__AutoSysUpdate(soap, &soap_tmp_ns__AutoSysUpdate);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__AutoSysUpdate(soap, &soap_tmp_ns__AutoSysUpdate, "ns:AutoSysUpdate", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__AutoSysUpdate(soap, &soap_tmp_ns__AutoSysUpdate, "ns:AutoSysUpdate", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!Result)
		return soap_closesock(soap);
	soap_default_ns__Response(soap, Result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns__Response(soap, Result, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__NetMaster(struct soap *soap, const char *soap_endpoint, const char *soap_action, int nIsOK, int &nResult)
{	struct ns__NetMaster soap_tmp_ns__NetMaster;
	struct ns__NetMasterResponse *soap_tmp_ns__NetMasterResponse;
	if (!soap_endpoint)
		soap_endpoint = "http://127.0.0.1:8086/live.fcgi";
	soap->encodingStyle = "";
	soap_tmp_ns__NetMaster.nIsOK = nIsOK;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__NetMaster(soap, &soap_tmp_ns__NetMaster);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__NetMaster(soap, &soap_tmp_ns__NetMaster, "ns:NetMaster", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__NetMaster(soap, &soap_tmp_ns__NetMaster, "ns:NetMaster", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&nResult)
		return soap_closesock(soap);
	soap_default_int(soap, &nResult);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__NetMasterResponse = soap_get_ns__NetMasterResponse(soap, NULL, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	nResult = soap_tmp_ns__NetMasterResponse->nResult;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__HBOperate(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *szXml, char *&szXmlRes)
{	struct ns__HBOperate soap_tmp_ns__HBOperate;
	struct ns__HBOperateResponse *soap_tmp_ns__HBOperateResponse;
	if (!soap_endpoint)
		soap_endpoint = "http://127.0.0.1:8086/live.fcgi";
	soap->encodingStyle = "";
	soap_tmp_ns__HBOperate.szXml = szXml;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__HBOperate(soap, &soap_tmp_ns__HBOperate);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__HBOperate(soap, &soap_tmp_ns__HBOperate, "ns:HBOperate", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__HBOperate(soap, &soap_tmp_ns__HBOperate, "ns:HBOperate", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	szXmlRes = NULL;
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__HBOperateResponse = soap_get_ns__HBOperateResponse(soap, NULL, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	szXmlRes = soap_tmp_ns__HBOperateResponse->szXmlRes;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__PlayVideoRecordSIP(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND *Param, struct ns__HBNET_VIDEO_STREAM *Url, std::string &strCallID)
{	struct ns__PlayVideoRecordSIP soap_tmp_ns__PlayVideoRecordSIP;
	struct ns__PlayVideoRecordSIPResponse *soap_tmp_ns__PlayVideoRecordSIPResponse;
	if (!soap_endpoint)
		soap_endpoint = "http://127.0.0.1:8086/live.fcgi";
	soap->encodingStyle = "";
	soap_tmp_ns__PlayVideoRecordSIP.nsUserInfo = nsUserInfo;
	soap_tmp_ns__PlayVideoRecordSIP.CamID = CamID;
	soap_tmp_ns__PlayVideoRecordSIP.Param = Param;
	soap_tmp_ns__PlayVideoRecordSIP.Url = Url;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__PlayVideoRecordSIP(soap, &soap_tmp_ns__PlayVideoRecordSIP);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__PlayVideoRecordSIP(soap, &soap_tmp_ns__PlayVideoRecordSIP, "ns:PlayVideoRecordSIP", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__PlayVideoRecordSIP(soap, &soap_tmp_ns__PlayVideoRecordSIP, "ns:PlayVideoRecordSIP", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&strCallID)
		return soap_closesock(soap);
	soap_default_std__string(soap, &strCallID);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__PlayVideoRecordSIPResponse = soap_get_ns__PlayVideoRecordSIPResponse(soap, NULL, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	strCallID = soap_tmp_ns__PlayVideoRecordSIPResponse->strCallID;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__DownloadVideoRecordSIP(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_FILECOND *Param, struct ns__HBNET_VIDEO_STREAM *Url, std::string &strCallID)
{	struct ns__DownloadVideoRecordSIP soap_tmp_ns__DownloadVideoRecordSIP;
	struct ns__DownloadVideoRecordSIPResponse *soap_tmp_ns__DownloadVideoRecordSIPResponse;
	if (!soap_endpoint)
		soap_endpoint = "http://127.0.0.1:8086/live.fcgi";
	soap->encodingStyle = "";
	soap_tmp_ns__DownloadVideoRecordSIP.nsUserInfo = nsUserInfo;
	soap_tmp_ns__DownloadVideoRecordSIP.CamID = CamID;
	soap_tmp_ns__DownloadVideoRecordSIP.Param = Param;
	soap_tmp_ns__DownloadVideoRecordSIP.Url = Url;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__DownloadVideoRecordSIP(soap, &soap_tmp_ns__DownloadVideoRecordSIP);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__DownloadVideoRecordSIP(soap, &soap_tmp_ns__DownloadVideoRecordSIP, "ns:DownloadVideoRecordSIP", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__DownloadVideoRecordSIP(soap, &soap_tmp_ns__DownloadVideoRecordSIP, "ns:DownloadVideoRecordSIP", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&strCallID)
		return soap_closesock(soap);
	soap_default_std__string(soap, &strCallID);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__DownloadVideoRecordSIPResponse = soap_get_ns__DownloadVideoRecordSIPResponse(soap, NULL, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	strCallID = soap_tmp_ns__DownloadVideoRecordSIPResponse->strCallID;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__AbandonVideoRecordSIP(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, std::string strCallID, struct ns__Response *Result)
{	struct ns__AbandonVideoRecordSIP soap_tmp_ns__AbandonVideoRecordSIP;
	if (!soap_endpoint)
		soap_endpoint = "http://127.0.0.1:8086/live.fcgi";
	soap->encodingStyle = "";
	soap_tmp_ns__AbandonVideoRecordSIP.nsUserInfo = nsUserInfo;
	soap_tmp_ns__AbandonVideoRecordSIP.CamID = CamID;
	soap_tmp_ns__AbandonVideoRecordSIP.strCallID = strCallID;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__AbandonVideoRecordSIP(soap, &soap_tmp_ns__AbandonVideoRecordSIP);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__AbandonVideoRecordSIP(soap, &soap_tmp_ns__AbandonVideoRecordSIP, "ns:AbandonVideoRecordSIP", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__AbandonVideoRecordSIP(soap, &soap_tmp_ns__AbandonVideoRecordSIP, "ns:AbandonVideoRecordSIP", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!Result)
		return soap_closesock(soap);
	soap_default_ns__Response(soap, Result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns__Response(soap, Result, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__AbandonVideoDownSIP(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, std::string strCallID, struct ns__Response *Result)
{	struct ns__AbandonVideoDownSIP soap_tmp_ns__AbandonVideoDownSIP;
	if (!soap_endpoint)
		soap_endpoint = "http://127.0.0.1:8086/live.fcgi";
	soap->encodingStyle = "";
	soap_tmp_ns__AbandonVideoDownSIP.nsUserInfo = nsUserInfo;
	soap_tmp_ns__AbandonVideoDownSIP.CamID = CamID;
	soap_tmp_ns__AbandonVideoDownSIP.strCallID = strCallID;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__AbandonVideoDownSIP(soap, &soap_tmp_ns__AbandonVideoDownSIP);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__AbandonVideoDownSIP(soap, &soap_tmp_ns__AbandonVideoDownSIP, "ns:AbandonVideoDownSIP", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__AbandonVideoDownSIP(soap, &soap_tmp_ns__AbandonVideoDownSIP, "ns:AbandonVideoDownSIP", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!Result)
		return soap_closesock(soap);
	soap_default_ns__Response(soap, Result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns__Response(soap, Result, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__CtrlVideoRecord(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns__HBUSERINFO nsUserInfo, long CamID, struct ns__HBNET_RECOED_PLAYCTRL *Pctrl, std::string strCallID, struct ns__Response *Result)
{	struct ns__CtrlVideoRecord soap_tmp_ns__CtrlVideoRecord;
	if (!soap_endpoint)
		soap_endpoint = "http://127.0.0.1:8086/live.fcgi";
	soap->encodingStyle = "";
	soap_tmp_ns__CtrlVideoRecord.nsUserInfo = nsUserInfo;
	soap_tmp_ns__CtrlVideoRecord.CamID = CamID;
	soap_tmp_ns__CtrlVideoRecord.Pctrl = Pctrl;
	soap_tmp_ns__CtrlVideoRecord.strCallID = strCallID;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__CtrlVideoRecord(soap, &soap_tmp_ns__CtrlVideoRecord);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__CtrlVideoRecord(soap, &soap_tmp_ns__CtrlVideoRecord, "ns:CtrlVideoRecord", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__CtrlVideoRecord(soap, &soap_tmp_ns__CtrlVideoRecord, "ns:CtrlVideoRecord", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!Result)
		return soap_closesock(soap);
	soap_default_ns__Response(soap, Result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns__Response(soap, Result, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__getData(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__getData *ns1__getData, _ns1__getDataResponse *ns1__getDataResponse)
{	struct __ns1__getData soap_tmp___ns1__getData;
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__getData.ns1__getData = ns1__getData;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__getData(soap, &soap_tmp___ns1__getData);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__getData(soap, &soap_tmp___ns1__getData, "-ns1:getData", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__getData(soap, &soap_tmp___ns1__getData, "-ns1:getData", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__getDataResponse)
		return soap_closesock(soap);
	ns1__getDataResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__getDataResponse->soap_get(soap, "ns1:getDataResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___nsCXF__getDataCxf(struct soap *soap, const char *soap_endpoint, const char *soap_action, nsCXF__getDataCxf *nsCXF__getDataCxf_, nsCXF__getDataCxfResponse *nsCXF__getDataCxfResponse_)
{	struct __nsCXF__getDataCxf soap_tmp___nsCXF__getDataCxf;
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_tmp___nsCXF__getDataCxf.nsCXF__getDataCxf_ = nsCXF__getDataCxf_;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___nsCXF__getDataCxf(soap, &soap_tmp___nsCXF__getDataCxf);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___nsCXF__getDataCxf(soap, &soap_tmp___nsCXF__getDataCxf, "-nsCXF:getDataCxf", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___nsCXF__getDataCxf(soap, &soap_tmp___nsCXF__getDataCxf, "-nsCXF:getDataCxf", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!nsCXF__getDataCxfResponse_)
		return soap_closesock(soap);
	nsCXF__getDataCxfResponse_->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	nsCXF__getDataCxfResponse_->soap_get(soap, "nsCXF:getDataCxfResponse", "nsCXF:getDataCxfResponse");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of BaseClient.cpp */
