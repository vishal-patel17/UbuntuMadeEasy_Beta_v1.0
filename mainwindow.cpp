#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QProcess>
#include<QByteArray>
#include<QHostAddress>
#include<QNetworkInterface>
#include<QTextStream>
#include<QMessageBox>
#include<QDir>
#include<QFile>
#include<QIODevice>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(displayLocation()));
    connect(ui->comboBox,SIGNAL(currentTextChanged(QString)),this,SLOT(changeBrightness()));
    connect(ui->cb_wifi,SIGNAL(currentTextChanged(QString)),this,SLOT(changewifi()));
    connect(ui->cb_bluetooth,SIGNAL(currentTextChanged(QString)),this,SLOT(changeBluetooth()));
    connect(ui->le_comm_info,SIGNAL(textChanged(QString)),this,SLOT(commandInfo()));



    QProcess process1;
                process1.setReadChannel(QProcess::StandardOutput);
                process1.setReadChannelMode(QProcess::MergedChannels);


                process1.start("sh");
                process1.write("uname -s -n -m -o");
                process1.closeWriteChannel();


                          process1.waitForFinished(-1);
                          QByteArray result = process1.readAll();

                          ui->lbl_info->setText(result);





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

//    QProcess process1;
//                    process1.setReadChannel(QProcess::StandardOutput);
//                    process1.setReadChannelMode(QProcess::MergedChannels);

//                    process1.start("sh");
//                    process1.write("passwd vishal dmy170992");

//                    process1.closeWriteChannel();

//                     process1.waitForFinished(-1);

//                    QByteArray list1 = process1.readAll();
//                    ui->textBrowser->setText(list1);




    QProcess process1;

                process1.setReadChannel(QProcess::StandardOutput);
                process1.setReadChannelMode(QProcess::MergedChannels);

                process1.start("sh");
//process1.start("gnome-terminal -e 'apt-get install kmplayer'");
                QString s = "apt-get --assume-yes install "+ui->lineEdit_2->text();
                process1.write(s.toLocal8Bit());

//                process1.write("ps aux | sort -nrk 4 | head");

process1.closeWriteChannel();



//                 process1.write("y\n");

//process1.waitForFinished(-1);
QByteArray result ;
short count =0;
//ui->textBrowser->setText(list1);
while(process1.state()!=QProcess::NotRunning){

    //            cmd2->waitForFinished(-1);
                process1.waitForReadyRead();

                result = process1.readAll();
                QString s(result);
                ui->textBrowser->append(s);

                ui->progressBar->setValue(count++);
             }
QMessageBox msg;
msg.setText(ui->lineEdit_2->text()+" Installed\n Successfully");
msg.setWindowTitle("Message");
msg.exec();
ui->progressBar->reset();



}

void MainWindow::on_pushButton_2_clicked()
{


    QString ipAddress;
        QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
        for (int i = 0; i < ipAddressesList.size(); ++i)
        {
          if (ipAddressesList.at(i) != QHostAddress::LocalHost && ipAddressesList.at(i).toIPv4Address())
           {
                 ipAddress = ipAddressesList.at(i).toString();
                 ui->textBrowser->setText(ipAddress);
                 break;
            }
        }
}
void MainWindow::displayLocation()
{
    QProcess process1;
//                process1.setReadChannel(QProcess::StandardOutput);
//                process1.setReadChannelMode(QProcess::MergedChannels);

                process1.start("sh");
                QString s = "whereis "+ui->lineEdit->text();
                process1.write(s.toLocal8Bit());
                process1.closeWriteChannel();

                 process1.waitForFinished(-1);

                QByteArray list1 = process1.readAll();
                ui->textBrowser->setText(list1);

}

void MainWindow::on_pushButton_3_clicked()
{
    QProcess process1;
    process1.setReadChannel(QProcess::StandardOutput);
    process1.setReadChannelMode(QProcess::MergedChannels);

    process1.start("free");
    QByteArray result ;
    short count =0;

    while(process1.state()!=QProcess::NotRunning){

                    process1.waitForReadyRead();

                    result = process1.readAll();
                    QString s(result);
                    ui->textBrowser->append(s);

                    ui->progressBar->setValue(count++);
                 }


//    QProcess process1;
//                process1.setReadChannel(QProcess::StandardOutput);
//                process1.setReadChannelMode(QProcess::MergedChannels);

//                process1.start("sh");

//                process1.write("free");
//                process1.closeWriteChannel();

//                 process1.waitForFinished(-1);

//                QByteArray list1 = process1.readAll();
//                ui->textBrowser->setText(list1);

}

void MainWindow::on_btn_clean_clicked()
{

    if(ui->cb_start->isChecked()){
    QProcess process1;
                process1.setReadChannel(QProcess::StandardOutput);
                process1.setReadChannelMode(QProcess::MergedChannels);

                process1.start("sh");

                process1.write("rm /var/crash/*");
                process1.closeWriteChannel();

                 process1.waitForFinished(-1);
                 process1.close();
    }

    if(ui->cb_trash->isChecked()){
    QProcess process1;
                process1.setReadChannel(QProcess::StandardOutput);
                process1.setReadChannelMode(QProcess::MergedChannels);

                process1.start("sh");

                process1.write("rm -rf /home/*/.local/share/Trash/*/**");
                process1.closeWriteChannel();

                 process1.waitForFinished(-1);
                 process1.close();


    }
    if(ui->cb_temp->isChecked()){
        QProcess process1;
                    process1.setReadChannel(QProcess::StandardOutput);
                    process1.setReadChannelMode(QProcess::MergedChannels);

                    process1.start("sh");

                    process1.write("apt-get autoclean");
                    process1.closeWriteChannel();

                     process1.waitForFinished(-1);
                     process1.close();

                     QProcess process2;
                                 process2.setReadChannel(QProcess::StandardOutput);
                                 process2.setReadChannelMode(QProcess::MergedChannels);

                                 process2.start("sh");

                                 process2.write("rm -rf /tmp/*");
                                 process2.closeWriteChannel();

                                  process2.waitForFinished(-1);
                                  process2.close();

                          QProcess process3;
                                process3.setReadChannel(QProcess::StandardOutput);
                                  process3.setReadChannelMode(QProcess::MergedChannels);
                                    process3.start("sh");

                                 process3.write("apt-get autoremove");
                                             process3.closeWriteChannel();

                                               process3.waitForFinished(-1);
                                               process3.close();



    }

    if(ui->cb_history->isChecked()){

        QString filepath = "/home/vishal/.mozilla/firefox/profiles.ini";

                    QFile file(filepath);

                   file.open(QIODevice::ReadOnly);
                   QTextStream in2(&file);
                    QString line1 = in2.readLine();
                    QString line2 = in2.readLine();
                    QString line3 = in2.readLine();
                    QString line4 = in2.readLine();
                    QString line5 = in2.readLine();
                    QString line6 = in2.readLine();
                    QString line7 = in2.readLine();
            line7.remove(0,5);
            QString s = line7;
            ui->textBrowser->setText(s);

            QString path = "/home/vishal/.mozilla/firefox/"+s;
                        QDir dir(path);
                        dir.remove("places.sqlite");


    }

    QMessageBox msg;
    msg.setText("Cleanup Completed Successfully");
    msg.setWindowTitle("Message");
    msg.exec();
    ui->progressBar->reset();

}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox msg;
           msg.setWindowTitle("Message");
           msg.setText("This will shutdown your system,\nDo you wish to continue?");
           msg.setStandardButtons(QMessageBox::Yes| QMessageBox::No);
           msg.setDefaultButton(QMessageBox::Yes);
           if(msg.exec() == QMessageBox::Yes){
    QProcess process1;
                process1.setReadChannel(QProcess::StandardOutput);
                process1.setReadChannelMode(QProcess::MergedChannels);

                process1.start("sh");

                process1.write("poweroff");
                process1.closeWriteChannel();

                 process1.waitForFinished(-1);
           }
           else{}
}



void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox msg;
           msg.setWindowTitle("Message");
           msg.setText("This will restart your system,\nDo you wish to continue?");
           msg.setStandardButtons(QMessageBox::Yes| QMessageBox::No);
           msg.setDefaultButton(QMessageBox::Yes);
           if(msg.exec() == QMessageBox::Yes){
    QProcess process1;
                process1.setReadChannel(QProcess::StandardOutput);
                process1.setReadChannelMode(QProcess::MergedChannels);

                process1.start("sh");

                process1.write("reboot");
                process1.closeWriteChannel();

                 process1.waitForFinished(-1);
           }
           else{}

}

void MainWindow::changeBrightness()
{

    QProcess process1;
                process1.setReadChannel(QProcess::StandardOutput);
                process1.setReadChannelMode(QProcess::MergedChannels);
                process1.start("sh");
QString s ="echo "+ui->comboBox->currentText()+" > /sys/class/backlight/nv_backlight/brightness";
                process1.write(s.toLocal8Bit());
                process1.closeWriteChannel();

                 process1.waitForFinished(-1);

                 process1.close();


}
void MainWindow::changewifi()
{
    QProcess process1;
                process1.setReadChannel(QProcess::StandardOutput);
                process1.setReadChannelMode(QProcess::MergedChannels);
                process1.start("sh");
QString s ="nmcli nm wifi "+ui->cb_wifi->currentText();
                process1.write(s.toLocal8Bit());
                process1.closeWriteChannel();

                 process1.waitForFinished(-1);

                 process1.close();

}
void MainWindow::changeBluetooth()
{
    QProcess process1;
                process1.setReadChannel(QProcess::StandardOutput);
                process1.setReadChannelMode(QProcess::MergedChannels);
                process1.start("sh");
QString s ="rfkill "+ui->cb_bluetooth->currentText()+" bluetooth";
                process1.write(s.toLocal8Bit());
                process1.closeWriteChannel();

                 process1.waitForFinished(-1);

                 process1.close();

}




void MainWindow::on_btn_unstall_clicked()
{

    QProcess process1;

                process1.setReadChannel(QProcess::StandardOutput);
                process1.setReadChannelMode(QProcess::MergedChannels);

                process1.start("sh");
//process1.start("gnome-terminal -e 'apt-get install kmplayer'");
                QString s = "apt-get --assume-yes remove "+ui->le_uninstall->text();
                process1.write(s.toLocal8Bit());

//                process1.write("ps aux | sort -nrk 4 | head");

process1.closeWriteChannel();



//                 process1.write("y\n");

//process1.waitForFinished(-1);
QByteArray result ;
short count =0;
//ui->textBrowser->setText(list1);
while(process1.state()!=QProcess::NotRunning){

    //            cmd2->waitForFinished(-1);
                process1.waitForReadyRead();

                result = process1.readAll();
                QString s(result);
                ui->textBrowser->append(s);

                ui->progressBar->setValue(count++);
             }
QMessageBox msg;
msg.setText(ui->lineEdit_2->text()+" Uninstalled\n Successfully");
msg.setWindowTitle("Message");
msg.exec();
ui->progressBar->reset();

}

void MainWindow::on_pushButton_6_clicked()
{
    net=new Form();
    net->show();
//    ui->retranslateUi(this);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->listWidget->clear();

    QProcess process1;
                process1.setReadChannel(QProcess::StandardOutput);
                process1.setReadChannelMode(QProcess::MergedChannels);
                process1.start("sh");
//QString s ="ps aux | sort -nrk 4 | head |awk '{print $11}'";
//  QString s="pgrep -l -u vishal |sort -nrk 1| awk '{print $2}'";
//             QString s = "ps -ef | awk '{print $8}'";
                QString s = "ps -A | awk '{print $4}'";
//                wmctrl -l|awk '{$3="";$2="";$1=""; print $0}'
//                QString s="wmctrl -l|awk '{$3="";print $0}'";
                process1.write(s.toLocal8Bit());
                process1.closeWriteChannel();

                 process1.waitForFinished(-1);

QByteArray result = process1.readAll();
QTextStream in(&result);
foreach (QString s, QString(result)) {
    s = in.readLine();
    ui->listWidget->addItem(s);

}
//ui->textBrowser->setText(result);
                 process1.close();
}

void MainWindow::on_btn_suspend_clicked()
{

    QProcess process1;
                process1.setReadChannel(QProcess::StandardOutput);
                process1.setReadChannelMode(QProcess::MergedChannels);

                process1.start("sh");

                process1.write("pm-suspend");
                process1.closeWriteChannel();

                 process1.waitForFinished(-1);


}

void MainWindow::on_pushButton_8_clicked()
{

    QProcess process1;
    process1.setReadChannel(QProcess::StandardOutput);
    process1.setReadChannelMode(QProcess::MergedChannels);

    process1.startDetached("fc -l 10");
    QByteArray result ;
    short count =0;

    while(process1.state()!=QProcess::NotRunning){

                    process1.waitForReadyRead();

                    result = process1.readAll();
                    QString s(result);
                    ui->textBrowser->append(s);

                    ui->progressBar->setValue(count++);
                 }



//    QProcess process1;
//                process1.setReadChannel(QProcess::StandardOutput);
//                process1.setReadChannelMode(QProcess::MergedChannels);



//                process1.start("history 20");


//                         process1.waitForFinished(-1);
//                          QByteArray result = process1.readAll();

//                          ui->textBrowser->append(result);



}

void MainWindow::on_pushButton_10_clicked()
{
    QProcess process1;
                process1.setReadChannel(QProcess::StandardOutput);
                process1.setReadChannelMode(QProcess::MergedChannels);

                process1.startDetached("gnome-terminal");

                 process1.waitForFinished(-1);

}

void MainWindow::on_pushButton_11_clicked()
{
    newform = new NewForm();
    newform->show();
}

void MainWindow::on_pushButton_9_clicked()
{



    ui->textBrowser->setText(NULL);
}

void MainWindow::on_pushButton_12_clicked()
{
    QProcess process1;
                process1.setReadChannel(QProcess::StandardOutput);
                process1.setReadChannelMode(QProcess::MergedChannels);



                process1.start("env");





                          process1.waitForFinished(-1);
                          QByteArray result = process1.readAll();

                          ui->textBrowser->setText(result);

}

void MainWindow::on_btn_kill_clicked()
{
    QProcess process1;
                process1.setReadChannel(QProcess::StandardOutput);
                process1.setReadChannelMode(QProcess::MergedChannels);



                process1.start("sh");
                QString s ="killall -v "+ui->listWidget->currentItem()->text();
                process1.write(s.toLocal8Bit());

                process1.closeWriteChannel();

                          process1.waitForFinished(-1);



}

void MainWindow::on_pushButton_13_clicked()
{
    QProcess process1;
    process1.setReadChannel(QProcess::StandardOutput);
    process1.setReadChannelMode(QProcess::MergedChannels);

    process1.start("apt-get update");
//    process1.write("");

//    process1.closeWriteChannel();
//    process1.waitForFinished(-1);
    QByteArray result ;
    short count =0;
    //ui->textBrowser->setText(list1);
    while(process1.state()!=QProcess::NotRunning){

                    process1.waitForReadyRead();

                    result = process1.readAll();
                    QString s(result);
                    ui->textBrowser->append(s);

                    ui->progressBar->setValue(count++);
                 }

}

void MainWindow::commandInfo()
{
    QProcess process1;
    process1.setReadChannel(QProcess::StandardOutput);
    process1.setReadChannelMode(QProcess::MergedChannels);

    process1.start("sh");
    QString s = "man "+ui->le_comm_info->text();
    process1.write(s.toLocal8Bit());

    process1.closeWriteChannel();
//    process1.waitForFinished(-1);
    QByteArray result ;
//    short count =0;
    //ui->textBrowser->setText(list1);
    while(process1.state()!=QProcess::NotRunning){

                    process1.waitForReadyRead();

                    result = process1.readAll();
                    QString s(result);
                    ui->textBrowser->append(s);

//                    ui->progressBar->setValue(count++);
                 }

}
