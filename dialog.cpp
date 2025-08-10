#include "dialog.h"
#include "ui_dialog.h"
#include "selections.h"  // include here, not in dialog.h

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

void Dialog::on_selectBtn_clicked() {
    // Pass "this" so Selections knows the main dialog
    Selections *s = new Selections(nullptr, this);
    s->show();
}

void Dialog::on_buttonBox_accepted() {
    QMessageBox::information(this, "Info!", "You have selected: " + ui->lineEdit->text());
    accept();
}

void Dialog::on_buttonBox_rejected() {
    reject();
}

void Dialog::setText(const QString &text) {  // use const QString& for efficiency
    ui->lineEdit->setText(text);
}
