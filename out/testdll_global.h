#ifndef TESTDLL_GLOBAL_H
#define TESTDLL_GLOBAL_H
#include <string>
using namespace std;

typedef int (*CallBackFun)(string id, string cameraID,char *pdata,int dataLen);

int Init(string ip, string port, string user, string pwd);

int RegisterRealVedioReq(CallBackFun fun, string& id, string cameraid);

int UnRegisterRealVedioReq(string id);

int RegisterHisVedioReq(CallBackFun fun, string& id, string cameraid, time_t begt, time_t endt);

int UnRegisterHisVedioReq(string id);
#endif // TESTDLL_GLOBAL_H
