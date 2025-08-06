#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::on_timeEdit_userTimeChanged(const QTime &time) {
    ui->timeEdit->setTime(time);
    ui->dateTimeEdit->setTime(time);
}


void Dialog::on_dateEdit_userDateChanged(const QDate &date) {
    ui->dateEdit->setDate(date);
    ui->dateTimeEdit->setDate(date);
}


void Dialog::on_buttonBox_accepted() {
    QMessageBox::information(this, "Result", "You selected: " + QLocale().toString(ui->dateTimeEdit->dateTime(), QLocale::ShortFormat));

    accept();
}


void Dialog::on_buttonBox_rejected() {
    reject();
}

