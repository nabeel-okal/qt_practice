#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::clicked, this, &Dialog::on_buttonBox_clicked);

    // Creating 5 more push buttons

    QPushButton *btnCopy = new QPushButton("Copy", this);
    QPushButton *btnCut = new QPushButton("Cut", this);
    QPushButton *btnPaste = new QPushButton("Paste", this);
    QPushButton *btnUndo = new QPushButton("Undo", this);
    QPushButton *btnRedo = new QPushButton("Redo", this);

    // Adding them to the buttonBox on the  ui file

    ui->buttonBox->addButton(btnCopy, QDialogButtonBox::ActionRole);
    ui->buttonBox->addButton(btnCut, QDialogButtonBox::ActionRole);
    ui->buttonBox->addButton(btnPaste, QDialogButtonBox::ActionRole);
    ui->buttonBox->addButton(btnUndo, QDialogButtonBox::ActionRole);
    ui->buttonBox->addButton(btnRedo, QDialogButtonBox::ActionRole);

    // Creating their functionalities

    connect(btnCopy, &QPushButton::clicked, ui->plainTextEdit, &QPlainTextEdit::copy);
    connect(btnCut, &QPushButton::clicked, ui->plainTextEdit, &QPlainTextEdit::cut);
    connect(btnPaste, &QPushButton::clicked, ui->plainTextEdit, &QPlainTextEdit::paste);
    connect(btnUndo, &QPushButton::clicked, ui->plainTextEdit, &QPlainTextEdit::undo);
    connect(btnRedo, &QPushButton::clicked, ui->plainTextEdit, &QPlainTextEdit::redo);

    load();
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::on_plainTextEdit_textChanged() {
    m_saved = false;
}


void Dialog::on_buttonBox_clicked(QAbstractButton *button) {
    QDialogButtonBox::StandardButton stdBtn = ui->buttonBox->standardButton(button);

    if(stdBtn == QDialogButtonBox::Open){
        load();
        return;

    }

    if(stdBtn == QDialogButtonBox::Save){
        save();
        return;
    }
}

void Dialog::load() {
    ui->plainTextEdit->clear();
    QFile file("test_file.txt");

    if(!file.exists()) return;

    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    ui->plainTextEdit->setPlainText(stream.readAll());

    file.close();
    m_saved = true;
}

void Dialog::save() {
    QFile file("test_file.txt");

    if(!file.open(QIODevice::WriteOnly)){
        QMessageBox::critical(this, "ERROR!", file.errorString());
        return;
    }

    QTextStream stream(&file);
    stream << ui->plainTextEdit->toPlainText();

    file.close();
    m_saved = true;

    QMessageBox::information(this, "Saved!", "the file has been saved successfully!");
}

void Dialog::closeEvent(QCloseEvent *event) {
    event->accept();
}

