#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::newFile);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFile);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveFile);
    connect(ui->actionSave_As, &QAction::triggered, this, &MainWindow::saveFileAs);
    connect(ui->actionExit, &QAction::triggered, ui->plainTextEdit, &QPlainTextEdit::copy);
    connect(ui->actionCopy, &QAction::triggered, this, &MainWindow::newFile);
    connect(ui->actionCut, &QAction::triggered, ui->plainTextEdit, &QPlainTextEdit::cut);
    connect(ui->actionPaste, &QAction::triggered, ui->plainTextEdit, &QPlainTextEdit::paste);
    connect(ui->actionSelect_All, &QAction::triggered, ui->plainTextEdit, &QPlainTextEdit::selectAll);
    connect(ui->actionSelect_None, &QAction::triggered, this, &MainWindow::selectNone);

    this->setCentralWidget(ui->plainTextEdit);

    newFile();
    m_saved = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile() {
    ui->plainTextEdit->clear();
    m_filename.clear();
    m_saved = false;
    ui->statusbar->showMessage("New File");
}

void MainWindow::openFile() {
    QString tmp = QFileDialog::getOpenFileName(this, "Open File", QString(), "Text Files (*txt);;All Files(*,*)");

    if(tmp.isEmpty()) return;

    m_filename = tmp;

    QFile file(m_filename);
    if(!file.open(QIODevice::ReadOnly)){
        newFile();
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    ui->plainTextEdit->setPlainText(stream.readAll());
    file.close();

    m_saved = true;
    ui->statusbar->showMessage(m_filename);
}

void MainWindow::saveFile() {
    if(m_filename.isEmpty()){
        saveFileAs();
        return;
    }

    QFile file(m_filename);
    if(!file.open(QIODevice::WriteOnly)){
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    stream << ui->plainTextEdit->toPlainText();
    file.close();

    m_saved = true;
    ui->statusbar->showMessage(m_filename);
}

void MainWindow::saveFileAs() {
    QString tmp = QFileDialog::getSaveFileName(this, "Save File", QString(), "Text Files (*txt);;All Files(*,*)");

    if(tmp.isEmpty()) return;

    m_filename = tmp;

    saveFile();
}

void MainWindow::selectNone() {
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    cursor.clearSelection();
    cursor.setPosition(cursor.position(), QTextCursor::MoveMode::KeepAnchor);
    ui->plainTextEdit->setTextCursor(cursor);
}

void MainWindow::on_actionToolbar_Top_triggered() {
    addToolBar(Qt::ToolBarArea::TopToolBarArea, ui->toolBar);
}


void MainWindow::on_actionToolbar_Bottom_triggered() {
    addToolBar(Qt::ToolBarArea::BottomToolBarArea, ui->toolBar);
}


void MainWindow::on_actionToolbar_Left_triggered() {
    addToolBar(Qt::ToolBarArea::LeftToolBarArea, ui->toolBar);
}


void MainWindow::on_actionToolbar_Right_triggered() {
    addToolBar(Qt::ToolBarArea::RightToolBarArea, ui->toolBar);
}


void MainWindow::on_actionToolbar_Floatable_toggled(bool arg1) {
    ui->toolBar->setFloatable(arg1);
}


void MainWindow::on_actionToolbar_Movable_toggled(bool arg1) {
    ui->toolBar->setMovable(arg1);
}

