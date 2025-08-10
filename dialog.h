#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>

class Selections; // forward declaration

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void setText(const QString &text);

private slots:
    void on_selectBtn_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
