#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"
#include "newform.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void displayLocation();
    void changeBrightness();
    void changewifi();
    void changeBluetooth();



    void on_pushButton_3_clicked();

    void on_btn_clean_clicked();

    void on_pushButton_4_clicked();



    void on_pushButton_5_clicked();



    void on_btn_unstall_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_btn_suspend_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_btn_kill_clicked();

    void on_pushButton_13_clicked();

    void commandInfo();



private:
    Ui::MainWindow *ui;
    Form *net;
    NewForm *newform;
};

#endif // MAINWINDOW_H
