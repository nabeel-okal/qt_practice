#include "selections.h"
#include "ui_selections.h"
#include "dialog.h"

Selections::Selections(QWidget *parent, Dialog *mainDialog)
    : QDialog(parent), m_mainDialog(mainDialog), ui(new Ui::Selections)
{
    ui->setupUi(this);

    ui->selectionsList->addItem("Green");
    ui->selectionsList->addItem("Yellow");
    ui->selectionsList->addItem("Blue");
    ui->selectionsList->addItem("Red");
    ui->selectionsList->addItem("Orange");
}

Selections::~Selections()
{
    delete ui;
}

void Selections::on_buttonBox_accepted() {
    QString choice = ui->selectionsList->currentItem()->text();
    if (m_mainDialog) {
        m_mainDialog->setText(choice);
    }

    accept();
}

void Selections::on_buttonBox_rejected() {
    reject();
}
