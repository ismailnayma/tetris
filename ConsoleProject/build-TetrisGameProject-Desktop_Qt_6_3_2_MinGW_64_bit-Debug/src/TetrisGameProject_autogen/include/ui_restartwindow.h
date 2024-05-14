/********************************************************************************
** Form generated from reading UI file 'restartwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTARTWINDOW_H
#define UI_RESTARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RestartWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelState;
    QLabel *labelQuestion;
    QPushButton *replayPushButton;
    QPushButton *quitPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RestartWindow)
    {
        if (RestartWindow->objectName().isEmpty())
            RestartWindow->setObjectName(QString::fromUtf8("RestartWindow"));
        RestartWindow->resize(750, 550);
        RestartWindow->setStyleSheet(QString::fromUtf8("background:black;"));
        centralwidget = new QWidget(RestartWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        labelState = new QLabel(centralwidget);
        labelState->setObjectName(QString::fromUtf8("labelState"));
        labelState->setEnabled(true);
        labelState->setGeometry(QRect(200, 140, 341, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Showcard Gothic")});
        font.setPointSize(20);
        font.setBold(false);
        labelState->setFont(font);
        labelState->setStyleSheet(QString::fromUtf8("color:purple;"));
        labelState->setAlignment(Qt::AlignCenter);
        labelQuestion = new QLabel(centralwidget);
        labelQuestion->setObjectName(QString::fromUtf8("labelQuestion"));
        labelQuestion->setGeometry(QRect(90, 230, 551, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Showcard Gothic")});
        font1.setPointSize(16);
        font1.setBold(false);
        labelQuestion->setFont(font1);
        labelQuestion->setLayoutDirection(Qt::LeftToRight);
        labelQuestion->setStyleSheet(QString::fromUtf8("color:lightyellow;"));
        labelQuestion->setAlignment(Qt::AlignCenter);
        replayPushButton = new QPushButton(centralwidget);
        replayPushButton->setObjectName(QString::fromUtf8("replayPushButton"));
        replayPushButton->setGeometry(QRect(259, 280, 101, 24));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Showcard Gothic")});
        font2.setPointSize(13);
        font2.setBold(false);
        replayPushButton->setFont(font2);
        replayPushButton->setStyleSheet(QString::fromUtf8("background:lightgreen;color:purple;border: 1px solid purple; border-radius: 5px;"));
        quitPushButton = new QPushButton(centralwidget);
        quitPushButton->setObjectName(QString::fromUtf8("quitPushButton"));
        quitPushButton->setGeometry(QRect(370, 280, 101, 24));
        quitPushButton->setFont(font2);
        quitPushButton->setStyleSheet(QString::fromUtf8("background:lightgreen;color:purple;border: 1px solid purple; border-radius: 5px;"));
        RestartWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RestartWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 750, 17));
        RestartWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RestartWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RestartWindow->setStatusBar(statusbar);

        retranslateUi(RestartWindow);

        QMetaObject::connectSlotsByName(RestartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RestartWindow)
    {
        RestartWindow->setWindowTitle(QCoreApplication::translate("RestartWindow", "MainWindow", nullptr));
        labelState->setText(QString());
        labelQuestion->setText(QCoreApplication::translate("RestartWindow", "Do you want to replay?", nullptr));
        replayPushButton->setText(QCoreApplication::translate("RestartWindow", "Yes", nullptr));
        quitPushButton->setText(QCoreApplication::translate("RestartWindow", "No (Quit)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RestartWindow: public Ui_RestartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTARTWINDOW_H
