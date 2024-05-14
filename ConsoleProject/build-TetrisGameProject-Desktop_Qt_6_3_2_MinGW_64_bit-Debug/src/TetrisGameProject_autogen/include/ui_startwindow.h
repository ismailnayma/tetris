/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QSpinBox *widthSpinBox;
    QSpinBox *heightSpinBox;
    QLabel *label_2;
    QCheckBox *checkBoxPrefilled;
    QPushButton *playButton;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QString::fromUtf8("StartWindow"));
        StartWindow->resize(750, 550);
        StartWindow->setStyleSheet(QString::fromUtf8("background:black;"));
        StartWindow->setUnifiedTitleAndToolBarOnMac(false);
        centralwidget = new QWidget(StartWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(180, 110, 361, 341));
        groupBox->setStyleSheet(QString::fromUtf8("background:black; border-radius: 5px; border: 1px solid black; "));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 160, 141, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Showcard Gothic")});
        font.setPointSize(14);
        font.setBold(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: lightyellow"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        widthSpinBox = new QSpinBox(groupBox);
        widthSpinBox->setObjectName(QString::fromUtf8("widthSpinBox"));
        widthSpinBox->setGeometry(QRect(190, 130, 51, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Showcard Gothic")});
        font1.setPointSize(12);
        font1.setBold(false);
        widthSpinBox->setFont(font1);
        widthSpinBox->setMouseTracking(false);
        widthSpinBox->setLayoutDirection(Qt::LeftToRight);
        widthSpinBox->setStyleSheet(QString::fromUtf8("color: black; background:lightgreen"));
        widthSpinBox->setWrapping(false);
        widthSpinBox->setFrame(true);
        widthSpinBox->setAlignment(Qt::AlignCenter);
        widthSpinBox->setMinimum(10);
        widthSpinBox->setMaximum(20);
        heightSpinBox = new QSpinBox(groupBox);
        heightSpinBox->setObjectName(QString::fromUtf8("heightSpinBox"));
        heightSpinBox->setGeometry(QRect(190, 160, 51, 21));
        heightSpinBox->setFont(font1);
        heightSpinBox->setMouseTracking(false);
        heightSpinBox->setStyleSheet(QString::fromUtf8("color: black; background:lightgreen"));
        heightSpinBox->setFrame(true);
        heightSpinBox->setAlignment(Qt::AlignCenter);
        heightSpinBox->setMinimum(10);
        heightSpinBox->setMaximum(25);
        heightSpinBox->setValue(20);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 130, 111, 21));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: lightyellow"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBoxPrefilled = new QCheckBox(groupBox);
        checkBoxPrefilled->setObjectName(QString::fromUtf8("checkBoxPrefilled"));
        checkBoxPrefilled->setEnabled(true);
        checkBoxPrefilled->setGeometry(QRect(70, 230, 211, 21));
        checkBoxPrefilled->setFont(font);
        checkBoxPrefilled->setLayoutDirection(Qt::RightToLeft);
        checkBoxPrefilled->setAutoFillBackground(false);
        checkBoxPrefilled->setStyleSheet(QString::fromUtf8("color: lightyellow"));
        checkBoxPrefilled->setCheckable(true);
        playButton = new QPushButton(groupBox);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(120, 270, 131, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Showcard Gothic")});
        font2.setPointSize(18);
        font2.setBold(false);
        playButton->setFont(font2);
        playButton->setMouseTracking(true);
        playButton->setStyleSheet(QString::fromUtf8("color: lightgreen; background:purple; border-radius: 5px; border: 1px solid lightgreen; "));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 20, 341, 101));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Showcard Gothic")});
        font3.setPointSize(72);
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("color:magenta"));
        label_3->setAlignment(Qt::AlignCenter);
        StartWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StartWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 750, 17));
        StartWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(StartWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        StartWindow->setStatusBar(statusbar);

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("StartWindow", "LINES", nullptr));
        label_2->setText(QCoreApplication::translate("StartWindow", "COLUMNS", nullptr));
        checkBoxPrefilled->setText(QCoreApplication::translate("StartWindow", "Prefilled Board", nullptr));
        playButton->setText(QCoreApplication::translate("StartWindow", "Play", nullptr));
        label_3->setText(QCoreApplication::translate("StartWindow", "TETRIS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
