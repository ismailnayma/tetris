#include "CustomMessageBox.h"

CustomMessageBox::CustomMessageBox(QWidget *parent) : QMessageBox(parent) {}

void CustomMessageBox::showMessage(const QString &text) {
    setText(text);
    exec();
}
