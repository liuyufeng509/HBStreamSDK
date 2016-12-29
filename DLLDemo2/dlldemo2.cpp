#include "dlldemo2.h"
#include "ui_dlldemo2.h"
#include <QMessageBox>
#include<time.h>
#include<arpa/inet.h>
#include <iostream>
using namespace std;

DllDemo2 * pThis = NULL;

int relfun(string id, string cameraID,char *pdata,int dataLen)
{
    for (int i=0; i<pThis->m_vdsVec.size(); i++)
    {
        if (id == pThis->m_vdsVec[i].id)
        {
            pThis->m_vdsVec[i].datalen += dataLen;
//            unsigned char sps=false;
//            int outSize=0 ;
//            BYTE *pFrame =NULL;
//            pFrame=pThis->m_vdsVec[i].punpack->Parse_RTP_Packet((BYTE*)pdata, dataLen, &outSize,sps) ;

//            if(pFrame!=NULL)
//                fwrite(pFrame, outSize, 1,pThis->m_vdsVec[i].fp);
            fwrite(pdata, dataLen, 1,pThis->m_vdsVec[i].fp);
            sendto(pThis->sock, pdata, dataLen, 0, (sockaddr*)&(pThis->sendaddress), sizeof((pThis->sendaddress)));
        }
    }
    return 0;
}

int hisfun(string id, string cameraID,char *pdata,int dataLen)
{
    for (int i=0; i<pThis->m_vdsVec.size(); i++)
    {
        if (id == pThis->m_vdsVec[i].id)
        {
            pThis->m_vdsVec[i].datalen += dataLen;
            //unsigned char sps=false;
            //int outSize=0 ;
            //BYTE *pFrame =NULL;
            //cout<<"*****"<<endl;
           // pFrame=pThis->m_vdsVec[i].punpack->Parse_RTP_Packet((BYTE*)pdata, dataLen, &outSize,sps) ;
           //cout<<"outsize="<<outSize<<endl;
           // if(pFrame!=NULL)
            fwrite(pdata, dataLen, 1,pThis->m_vdsVec[i].fp);
            sendto(pThis->sock, pdata, dataLen, 0, (sockaddr*)&(pThis->sendaddress), sizeof((pThis->sendaddress)));

        }
    }
    return 0;
}

DllDemo2::DllDemo2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DllDemo2Class)
{
    ui->setupUi(this);
    connect(ui->regRelButton, SIGNAL(clicked()),this, SLOT(relRegButtonSlot()));
    connect(ui->unRegRelButton, SIGNAL(clicked()),this, SLOT(relUnRegButtonSlot()));
    connect(ui->regHisButton, SIGNAL(clicked()),this, SLOT(hisRegButtonSlot()));
    connect(ui->unRegHisButton, SIGNAL(clicked()),this, SLOT(hisUnRegButtonSlot()));
    connect(ui->initButton, SIGNAL(clicked()),this, SLOT(initgButtonSlot()));
    pThis = this;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(printInfo()));
    timer->start(1000);

    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    sendaddress.sin_family = AF_INET;
    sendaddress.sin_addr.s_addr = inet_addr("192.168.10.36");
    sendaddress.sin_port = htons(9000);
    int sendbuf = 1024*1024*2;
    setsockopt(sock, SOL_SOCKET, SO_SNDBUF, (char*)&sendbuf, sizeof(sendbuf));
}

void DllDemo2::initgButtonSlot()
{
    int ret = Init(ui->ipEdit->text().toStdString(),ui->portEdit->text().toStdString(),ui->userEdit->text().toStdString(), ui->pwdEdit->text().toStdString());
    if (ret != OK)
    {
        QMessageBox::information(this, "Warning", QString::fromLocal8Bit("初始化，错误码：")+QString::number(ret));
    }else
    {
        QMessageBox::information(this, "Warning","Init Success");
    }
}

void DllDemo2::printInfo()
{
    for (int i=0; i<m_vdsVec.size(); i++)
    {
        if (ui->relListWidget->currentItem()!=NULL && ui->relListWidget->currentItem()->text()==QString(m_vdsVec[i].id.c_str()))
        {
            ui->relInfoLabel->setText("id:"+QString(m_vdsVec[i].id.c_str()) + QString::fromLocal8Bit("长度：")+QString::number(m_vdsVec[i].datalen));
        }

        if (ui->hisListWidget->currentItem()!=NULL && ui->hisListWidget->currentItem()->text()==QString(m_vdsVec[i].id.c_str()))
        {
            ui->hisInfoLabel->setText("id:"+QString(m_vdsVec[i].id.c_str()) + QString::fromLocal8Bit("长度：")+QString::number(m_vdsVec[i].datalen));
        }
    }
}

void DllDemo2::relRegButtonSlot()
{
    VdInfo vdinfo;
    vdinfo.cmid = ui->relcmidEdit->text().toStdString();
    vdinfo.datalen = 0;
    char buff[256];
    bzero(buff, 256);
    sprintf(buff, "/home/liuyufeng/%d.h264", time(NULL));
    vdinfo.fp = fopen(buff,"w");
    int ret = RegisterRealVedioReq(relfun,vdinfo.id,vdinfo.cmid);
    if (ret == OK && m_vdsVec.size()<32)
    {
        m_vdsVec.push_back(vdinfo);
        QString info = QString(vdinfo.id.c_str());
        ui->relListWidget->addItem(new  QListWidgetItem(info));
    }else
    {
        QString str = "注册失败，错误码："+QString::number(ret);
        QMessageBox::information(this, "Warning", QString::fromLocal8Bit("注册失败，错误码：")+QString::number(ret));
    }
}

void DllDemo2::relUnRegButtonSlot()
{
    //QString id = ui->relidEdit->text();
    if(ui->relListWidget->currentItem()==NULL)
    {
        QMessageBox::information(this, "Warning", QString::fromLocal8Bit("请在列表中选择要注销的对象"));
        return;
    }
    QString id = ui->relListWidget->currentItem()->text();
    int ret = UnRegisterRealVedioReq(id.toStdString());
    if (ret == OK)
    {
        for (vector<VdInfo>::iterator it = m_vdsVec.begin(); it!=m_vdsVec.end(); it++)
        {
            if (id == QString(it->id.c_str()))
            {
               // fclose(it->fp);
                m_vdsVec.erase(it);
                break;
            }
        }

        for (int i=0; i<ui->relListWidget->count(); i++)
        {
            if(id == ui->relListWidget->item(i)->text())
            {
                ui->relListWidget->takeItem(i);
            }
        }
        ui->relInfoLabel->setText(id + QString::fromLocal8Bit("已被注销"));
    }else
    {
        ui->relInfoLabel->setText(id +QString::fromLocal8Bit("注销失败") );
    }

}

void DllDemo2::hisRegButtonSlot()
{
    VdInfo vdinfo;
    vdinfo.cmid = ui->hiscmidEdit->text().toStdString();
    vdinfo.beg = ui->begtimeEdit->text().toLong();
    vdinfo.end = ui->endtimeEdit->text().toLong();
    vdinfo.datalen = 0;
    char buff[256];
    bzero(buff, 256);
    sprintf(buff, "/home/liuyufeng/%d.h264", time(NULL));
    vdinfo.fp = fopen(buff,"w");
    int ret = RegisterHisVedioReq(hisfun,vdinfo.id,vdinfo.cmid,vdinfo.beg, vdinfo.end);
    if (ret == OK && m_vdsVec.size()<32)
    {
        m_vdsVec.push_back(vdinfo);
        QString info = QString(vdinfo.id.c_str());
        ui->hisListWidget->addItem(new  QListWidgetItem(info));
    }else
    {
        QString str = "注册失败，错误码："+QString::number(ret);
        QMessageBox::information(this, "Warning", QString::fromLocal8Bit("注册失败，错误码：")+QString::number(ret));
    }
}

void DllDemo2::hisUnRegButtonSlot()
{
    //QString id = ui->hisidEdit->text();
    if(ui->hisListWidget->currentItem()==NULL)
    {
        QMessageBox::information(this, "Warning", QString::fromLocal8Bit("请在列表中选择要注销的对象"));
        return;
    }
    QString id = ui->hisListWidget->currentItem()->text();
    int ret = UnRegisterHisVedioReq(id.toStdString());
    cout<<"ret="<<ret<<endl;
    if (ret == OK)
    {
        for (vector<VdInfo>::iterator it = m_vdsVec.begin(); it!=m_vdsVec.end(); it++)
        {
            if (id == QString(it->id.c_str()))
            {
                //fclose(it->fp);
                m_vdsVec.erase(it);
                break;
            }
        }

        for (int i=0; i<ui->hisListWidget->count(); i++)
        {
            if(id == ui->hisListWidget->item(i)->text())
            {
                ui->hisListWidget->takeItem(i);
            }
        }
        ui->hisInfoLabel->setText(id + QString::fromLocal8Bit("已被注销"));
    }else
    {
        ui->hisInfoLabel->setText(id + QString::fromLocal8Bit("注销失败"));
    }
}

DllDemo2::~DllDemo2()
{
    delete timer;
    delete ui;
}
