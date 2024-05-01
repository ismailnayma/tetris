#include "startwindow.h"



StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow),
    _scene(this)
{
    ui->setupUi(this);
}

int StartWindow::getWidthSpinBox() const{
    return ui->groupBox->findChild<QSpinBox *>("widthSpinBox") -> value();
}

int StartWindow::getHeightSpinBox() const{
    return ui->groupBox->findChild<QSpinBox *>("heightSpinBox")  -> value();
}

bool StartWindow::getPrefilledChoice() const {
    return ui->groupBox->findChild<QCheckBox *>("checkBoxPrefilled")->isChecked();
}

Ui::StartWindow& StartWindow::getUi() const {
    return *ui;
}

StartWindow::~StartWindow()
{
    delete ui;
}
