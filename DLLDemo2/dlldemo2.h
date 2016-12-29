#ifndef DLLDEMO2_H
#define DLLDEMO2_H
#include<arpa/inet.h>
#include <QMainWindow>
#include <vector>
#include <QTimer>
#include "testdll_global.h"
#include "errorno.h"
#include <stdlib.h>
struct VdInfo
{
    string id;	//视频id
    string  cmid;	//摄像机id
    time_t beg;
    time_t end;
    qint64    datalen;		//收到的数据长度
    FILE *fp;

};

namespace Ui {
class DllDemo2Class;
}

class DllDemo2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit DllDemo2(QWidget *parent = 0);
    ~DllDemo2();

    Ui::DllDemo2Class *ui;
    vector<VdInfo> m_vdsVec;
    sockaddr_in sendaddress;
    int sock;
private slots:
    void relRegButtonSlot();
    void relUnRegButtonSlot();
    void hisRegButtonSlot();
    void hisUnRegButtonSlot();
    void printInfo();
    void initgButtonSlot();
private:
    QTimer *timer;

};

#endif // DLLDEMO2_H
