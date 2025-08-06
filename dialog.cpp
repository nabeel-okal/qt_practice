#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    load();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted() {
    save();
    accept();
}


void Dialog::on_buttonBox_rejected() {
    reject();
}

void Dialog::load() {
    ui->txtName->setText("");
    ui->sbxAge->setValue(0);
    ui->sbxQty->setValue(0);

    QFile file("example_file.dat");

    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this, "ERROR!", file.errorString());
        return;
    }

    QDataStream ds(&file);

    QString name;
    int age;
    double qty;


    ds << name;
    ds << age;
    ds << qty;

    // Setting the values into the widgets

    ui->txtName->setText(name);
    ui->sbxAge->setValue(age);
    ui->sbxQty->setValue(qty);
    file.close();
}

void Dialog::save() {
    QFile file("example_file.dat");

    if(!file.open(QIODevice::WriteOnly)){
        QMessageBox::critical(this, "ERROR!", file.errorString());
        return;
    }

    QDataStream ds(&file);

    ds << ui->txtName->text();
    ds << ui->sbxAge->value();
    ds << ui->sbxQty->value();

    file.close();
    QMessageBox::information(this, "Saved!", "the file has been saved successfully!");
}
