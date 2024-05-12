#include "restartwindow.h"
#include "ui_restartwindow.h"

RestartWindow::RestartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RestartWindow),
    _scene(this)
{
    ui->setupUi(this);
}

void RestartWindow::showMessage(const QString &text){
    ui->labelState->clear();
    ui->labelState->setText(text);
}

Ui::RestartWindow& RestartWindow::getUi() const {
    return *ui;
}

RestartWindow::~RestartWindow()
{
    delete ui;
}
