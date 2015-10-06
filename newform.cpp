#include "newform.h"
#include "ui_newform.h"
#include<QProcess>

NewForm::NewForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewForm)
{
    ui->setupUi(this);

    QProcess process1;
    process1.setReadChannel(QProcess::StandardOutput);
    process1.setReadChannelMode(QProcess::MergedChannels);

    process1.start("users");
    QByteArray result ;


    while(process1.state()!=QProcess::NotRunning){

                    process1.waitForReadyRead();

                    result = process1.readAll();
                    QString s(result);
                    ui->textBrowser->append(s   );

                 }

}

NewForm::~NewForm()
{
    delete ui;
}

void NewForm::on_pushButton_clicked()
{
    QProcess process1;
                process1.setReadChannel(QProcess::StandardOutput);
                process1.setReadChannelMode(QProcess::MergedChannels);
                process1.startDetached("xfce4-settings-manager");
//                process1.startDetached("unity-control-center");




                 process1.waitForFinished(-1);


                 process1.close();
}

void NewForm::on_pushButton_2_clicked()
{
    QProcess process1;
                process1.setReadChannel(QProcess::StandardOutput);
                process1.setReadChannelMode(QProcess::MergedChannels);
                process1.startDetached("unity-control-center user-accounts");




                 process1.waitForFinished(-1);


                 process1.close();

}

void NewForm::on_pushButton_3_clicked()
{
    QProcess process1;
                process1.setReadChannel(QProcess::StandardOutput);
                process1.setReadChannelMode(QProcess::MergedChannels);
                process1.startDetached("hardinfo");




                 process1.waitForFinished(-1);


                 process1.close();


}
