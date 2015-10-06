#include "form.h"
#include "ui_form.h"
#include<QProcess>
#include<QByteArray>
#include<QTextStream>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);


    connect(ui->le_port_no,SIGNAL(returnPressed()),this,SLOT(portinfo()));

//    ui->listWidget->clear();
//    QProcess process1;
//                process1.setReadChannel(QProcess::StandardOutput);
//                process1.setReadChannelMode(QProcess::MergedChannels);
//                process1.start("sh");
//QString s ="iwlist wlan0 scanning|grep -i 'essid'";
//                process1.write(s.toLocal8Bit());
//                process1.closeWriteChannel();

//                 process1.waitForFinished(-1);
//                 QByteArray list = process1.readAll();
//                             QTextStream in(&list);
////                             QString line = in.readLine();
////                             ui->textBrowser->setText(list);

//                             foreach (QString drive, QString(list)) {

//                                 drive = in.readLine();
//                                 drive.remove(0,26);

//                                      ui->listWidget->addItem(drive);

//                             }


//                 process1.close();
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
//    ui->listWidget->clear();
//    QProcess process1;
//                process1.setReadChannel(QProcess::StandardOutput);
//                process1.setReadChannelMode(QProcess::MergedChannels);
//                process1.start("sh");
//QString s ="iwlist wlan0 scanning|grep -i 'essid'";
//                process1.write(s.toLocal8Bit());
//                process1.closeWriteChannel();

//                 process1.waitForFinished(-1);
//                 QByteArray list = process1.readAll();
//                             QTextStream in(&list);
////                             QString line = in.readLine();
////                             ui->textBrowser->setText(list);

//                             foreach (QString drive, QString(list)) {

//                                 drive = in.readLine();
//                                 drive.remove(0,26);

//                                      ui->listWidget->addItem(drive);

//                             }



//                 process1.close();
}

void Form::on_pushButton_2_clicked()
{
//    QString n = ui->listWidget->currentItem()->text();

//   QTextStream in2(&n);
//    QString line1 = in2.readLine();

//line1.remove(0,26);
//ui->textBrowser->setText(line1);

//    QProcess process1;
//                process1.setReadChannel(QProcess::StandardOutput);
//                process1.setReadChannelMode(QProcess::MergedChannels);
//                process1.start("sh");
//QString s ="nmcli d wifi connect "+ui->listWidget->currentItem()->text();
//                process1.write(s.toLocal8Bit());
//                process1.closeWriteChannel();

//                 process1.waitForFinished(-1);


//                 process1.close();

}

void Form::on_pushButton_3_clicked()
{
//    QProcess process1;
//                process1.setReadChannel(QProcess::StandardOutput);
//                process1.setReadChannelMode(QProcess::MergedChannels);
//                process1.start("sh");
//QString s ="nmcli d disconnect iface wlan0";
//                process1.write(s.toLocal8Bit());
//                process1.closeWriteChannel();

//                 process1.waitForFinished(-1);


//                 process1.close();

}

void Form::on_pushButton_4_clicked()
{


    QProcess process1;
                process1.setReadChannel(QProcess::StandardOutput);
                process1.setReadChannelMode(QProcess::MergedChannels);
                process1.start("sh");
                QString s = "arp-scan -I wlan0 -l | awk '{print $1}'";

                process1.write(s.toLocal8Bit());
                process1.closeWriteChannel();

                 process1.waitForFinished(-1);
                 QByteArray list = process1.readAll();
                 QTextStream in(&list);

                 foreach (QString st, QString(list)) {
                     st = in.readLine();
                     ui->listWidget->addItem(st);
                 }

//                 ui->textBrowser->setText(list);



                 process1.close();

}

void Form::on_pushButton_5_clicked()
{
    QProcess process1;
    process1.setReadChannel(QProcess::StandardOutput);
    process1.setReadChannelMode(QProcess::MergedChannels);

    QString s = "nmap -A "+ui->listWidget->currentItem()->text();

    process1.start(s.toLocal8Bit());
    QByteArray result ;
    short count =0;

    while(process1.state()!=QProcess::NotRunning){

ui->progressBar->setValue(count++);
ui->progressBar->setValue(count++);
                    process1.waitForReadyRead();
ui->progressBar->setValue(count++);
                    result = process1.readAll();
ui->progressBar->setValue(count++);
                    QString s(result);
ui->progressBar->setValue(count++);
                    ui->tb_host_info->append(s);


                 }

ui->progressBar->reset();
}

void Form::portinfo(){
    QProcess process1;
    process1.setReadChannel(QProcess::StandardOutput);
    process1.setReadChannelMode(QProcess::MergedChannels);

    QString s = "lsof -i:"+ui->le_port_no->text();

    QByteArray result;
    process1.start(s.toLocal8Bit());

    while(process1.state()!=QProcess::NotRunning){
        process1.waitForReadyRead();
        result = process1.readAll();
        QString s(result);
        ui->textBrowser->append(s);
    }
}
