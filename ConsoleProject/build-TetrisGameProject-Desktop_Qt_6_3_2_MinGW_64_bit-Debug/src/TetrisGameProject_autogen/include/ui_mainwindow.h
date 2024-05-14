/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *myGraphicsView;
    QLabel *label_level;
    QLCDNumber *lcdLevel;
    QLabel *label_score;
    QLCDNumber *lcdScore;
    QLabel *label_lines;
    QLCDNumber *lcdLines;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(750, 550);
        QFont font;
        font.setKerning(true);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: black;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        myGraphicsView = new QGraphicsView(centralwidget);
        myGraphicsView->setObjectName(QString::fromUtf8("myGraphicsView"));
        myGraphicsView->setGeometry(QRect(250, 20, 511, 601));
        QFont font1;
        font1.setKerning(false);
        myGraphicsView->setFont(font1);
        myGraphicsView->setStyleSheet(QString::fromUtf8("border: none; "));
        myGraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        myGraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        myGraphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        myGraphicsView->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        myGraphicsView->setResizeAnchor(QGraphicsView::NoAnchor);
        label_level = new QLabel(centralwidget);
        label_level->setObjectName(QString::fromUtf8("label_level"));
        label_level->setGeometry(QRect(80, 30, 91, 25));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Showcard Gothic")});
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setKerning(true);
        label_level->setFont(font2);
        label_level->setStyleSheet(QString::fromUtf8("color: white;"));
        label_level->setLineWidth(1);
        lcdLevel = new QLCDNumber(centralwidget);
        lcdLevel->setObjectName(QString::fromUtf8("lcdLevel"));
        lcdLevel->setGeometry(QRect(80, 60, 121, 31));
        lcdLevel->setStyleSheet(QString::fromUtf8("border: 2px solid purple; border-radius: 5px;"));
        label_score = new QLabel(centralwidget);
        label_score->setObjectName(QString::fromUtf8("label_score"));
        label_score->setGeometry(QRect(80, 120, 101, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Showcard Gothic")});
        font3.setPointSize(20);
        font3.setKerning(true);
        label_score->setFont(font3);
        label_score->setStyleSheet(QString::fromUtf8("color: white;"));
        lcdScore = new QLCDNumber(centralwidget);
        lcdScore->setObjectName(QString::fromUtf8("lcdScore"));
        lcdScore->setGeometry(QRect(80, 150, 121, 31));
        lcdScore->setStyleSheet(QString::fromUtf8("border: 2px solid purple; border-radius: 5px;"));
        label_lines = new QLabel(centralwidget);
        label_lines->setObjectName(QString::fromUtf8("label_lines"));
        label_lines->setGeometry(QRect(80, 210, 91, 21));
        label_lines->setFont(font3);
        label_lines->setStyleSheet(QString::fromUtf8("color: white;"));
        lcdLines = new QLCDNumber(centralwidget);
        lcdLines->setObjectName(QString::fromUtf8("lcdLines"));
        lcdLines->setGeometry(QRect(80, 240, 121, 31));
        lcdLines->setStyleSheet(QString::fromUtf8("border: 2px solid purple; border-radius: 5px;"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(60, 330, 161, 151));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: lightgreen; border-radius: 5px;"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 121, 16));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Showcard Gothic")});
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setKerning(true);
        label->setFont(font4);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("color: purple;"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 131, 16));
        label_2->setFont(font4);
        label_2->setStyleSheet(QString::fromUtf8("color: purple;"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 50, 131, 16));
        label_3->setFont(font4);
        label_3->setStyleSheet(QString::fromUtf8("color: purple;"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 70, 49, 16));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Stencil")});
        font5.setPointSize(12);
        font5.setKerning(true);
        label_4->setFont(font5);
        label_4->setStyleSheet(QString::fromUtf8("color: white;"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 70, 131, 16));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Showcard Gothic")});
        font6.setPointSize(12);
        font6.setKerning(true);
        label_5->setFont(font6);
        label_5->setStyleSheet(QString::fromUtf8("color: purple;"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 90, 141, 16));
        label_6->setFont(font6);
        label_6->setStyleSheet(QString::fromUtf8("color: purple;"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 110, 121, 16));
        label_7->setFont(font6);
        label_7->setStyleSheet(QString::fromUtf8("color: purple;"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 130, 131, 16));
        label_8->setFont(font6);
        label_8->setStyleSheet(QString::fromUtf8("color: purple;"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 750, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        myGraphicsView->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">LEVEL</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        label_level->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"justify\"><span style=\" font-size:18pt;\">LEVEL</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_level->setText(QCoreApplication::translate("MainWindow", "LEVEL", nullptr));
        label_score->setText(QCoreApplication::translate("MainWindow", "SCORE", nullptr));
        label_lines->setText(QCoreApplication::translate("MainWindow", "LINES", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Q -  MOVE LEFT", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "D -  MOVE RIGHT", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "S -  MOVE DOWN", nullptr));
        label_4->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "A -  ROTATE LEFT", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Z -  ROTATE RIGHT", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "E -  DROP", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "L  - LEAVE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
