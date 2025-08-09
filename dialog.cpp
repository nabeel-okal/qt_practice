#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted() {
    QString name = ui->txtName->text();
    QString title = ui->txtTitle->text();

    QDate selectedDate = ui->HireD->date();
    QDateTime dateTimeWithCurrentTime(selectedDate, QTime::currentTime());
    QString hireDate = dateTimeWithCurrentTime.toString();


    QMessageBox::information(this, "Info", "Name: " + name + "\nTitle: " + title + "\nHire date: " + hireDate);
}

