#ifndef TESTDLL_GLOBAL_H
#define TESTDLL_GLOBAL_H
#include <string>
using namespace std;

#ifdef WIN32
    #ifdef DLL_API
    #else
    #define DLL_API _declspec(dllexport)
    #endif
#else
    #define DLL_API
#endif

typedef int (*CallBackFun)(string id, string cameraID,char *pdata,int dataLen);

string  getVersion();

DLL_API int Init(string ip, string port, string user, string pwd);

DLL_API int RegisterRealVedioReq(CallBackFun fun, string& id, string cameraid);

DLL_API int UnRegisterRealVedioReq(string id);

DLL_API int RegisterHisVedioReq(CallBackFun fun, string& id, string cameraid, time_t begt, time_t endt);

DLL_API int UnRegisterHisVedioReq(string id);
#endif // TESTDLL_GLOBAL_H
