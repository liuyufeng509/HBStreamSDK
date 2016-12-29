#include <iostream>
#include "testdll_global.h"
#include "errorno.h"
#include<string>
#include<time.h>
using namespace std;

int fun(string id, string cameraID,char *pdata,int dataLen)
{
    cout<<"id="<<id<<" cameraID="<<cameraID<<" datalen="<<dataLen<<endl;
}

int main(int argc, char *argv[])
{
    string id="";
    string cameraID="201201";

    int ret = Init("192.168.3.192","8080","admin", "Haibo2013");
    if (ret != OK)
    {
       cout<<"init failed"<<endl;
    }

    int Ret = RegisterRealVedioReq(&fun, id, cameraID);
    if (Ret!=0)
    {
        cout<<"Reg real failed"<<endl;
    }
    sleep(20);
    ret = UnRegisterRealVedioReq(id);
    cout<<"real unreg"<<endl;
    sleep(3);
    time_t beg = 1482891846;
    time_t end = 1482892400;
    Ret = RegisterHisVedioReq(&fun, id, cameraID,beg, end);
    if (Ret!=0)
    {
        cout<<"Reg his failed"<<endl;
    }
    sleep(20);

    return 0;
}
