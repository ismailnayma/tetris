#ifndef CUSTOMMESSAGEBOX_H
#define CUSTOMMESSAGEBOX_H

#include <QMessageBox>

class CustomMessageBox : public QMessageBox
{
    Q_OBJECT
public:
    explicit CustomMessageBox(QWidget *parent = nullptr);

    void showMessage(const QString &text);
};

#endif // CUSTOMMESSAGEBOX_H
