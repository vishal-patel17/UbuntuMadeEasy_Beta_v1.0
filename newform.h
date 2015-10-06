#ifndef NEWFORM_H
#define NEWFORM_H

#include <QWidget>

namespace Ui {
class NewForm;
}

class NewForm : public QWidget
{
    Q_OBJECT

public:
    explicit NewForm(QWidget *parent = 0);
    ~NewForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::NewForm *ui;
};

#endif // NEWFORM_H
