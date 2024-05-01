#include "startwindow.h"
#include <QPainter>


StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow),
    _scene(this)
{
    ui->setupUi(this);
}

void StartWindow::paintEvent(QPaintEvent *event) {
    QMainWindow::paintEvent(event);

    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), QPixmap("../../resources/bck.jpg"));
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
