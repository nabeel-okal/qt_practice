#ifndef SELECTIONS_H
#define SELECTIONS_H

#include <QDialog>

class Dialog; // forward declaration

namespace Ui {
class Selections;
}

class Selections : public QDialog
{
    Q_OBJECT

public:
    explicit Selections(QWidget *parent = nullptr, Dialog *mainDialog = nullptr);
    ~Selections();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::Selections *ui;
    Dialog *m_mainDialog;
};

#endif // SELECTIONS_H
