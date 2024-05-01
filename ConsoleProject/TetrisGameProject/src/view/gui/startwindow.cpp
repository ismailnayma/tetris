#include "startwindow.h"
#include <QPainter>


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

void StartWindow::cleanRestart(){
    ui->groupBox->findChild<QSpinBox *>("widthSpinBox")->setValue(10);
    ui->groupBox->findChild<QSpinBox *>("heightSpinBox")->setValue(20);
    ui->groupBox->findChild<QCheckBox *>("checkBoxPrefilled")->setCheckState(Qt::Unchecked);
}
StartWindow::~StartWindow()
{
    delete ui;
}
