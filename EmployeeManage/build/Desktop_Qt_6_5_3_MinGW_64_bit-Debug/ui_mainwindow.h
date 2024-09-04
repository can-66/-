/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QPushButton *OpenFile;
    QPushButton *SaveFile;
    QPushButton *addpushButton;
    QPushButton *DisplayInformation;
    QPushButton *DisplaySalary;
    QTableView *ShowInfotableView;
    QPushButton *deleteButton;
    QPushButton *actionmingdanshaixuan;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::WindowModality::WindowModal);
        MainWindow->resize(805, 634);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 30, 801, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        OpenFile = new QPushButton(centralwidget);
        OpenFile->setObjectName("OpenFile");
        OpenFile->setGeometry(QRect(-10, 0, 93, 41));
        OpenFile->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/pictures/style-5.qss.png);"));
        SaveFile = new QPushButton(centralwidget);
        SaveFile->setObjectName("SaveFile");
        SaveFile->setGeometry(QRect(80, 0, 93, 41));
        SaveFile->setStyleSheet(QString::fromUtf8("border-image: url(:/pictures/style-5.qss.png);"));
        addpushButton = new QPushButton(centralwidget);
        addpushButton->setObjectName("addpushButton");
        addpushButton->setGeometry(QRect(170, 0, 93, 41));
        addpushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/pictures/style-5.qss.png);"));
        DisplayInformation = new QPushButton(centralwidget);
        DisplayInformation->setObjectName("DisplayInformation");
        DisplayInformation->setGeometry(QRect(360, 0, 93, 41));
        DisplayInformation->setStyleSheet(QString::fromUtf8("border-image: url(:/pictures/style-5.qss.png);"));
        DisplaySalary = new QPushButton(centralwidget);
        DisplaySalary->setObjectName("DisplaySalary");
        DisplaySalary->setGeometry(QRect(450, 0, 101, 41));
        DisplaySalary->setStyleSheet(QString::fromUtf8("border-image: url(:/pictures/style-5.qss.png);"));
        ShowInfotableView = new QTableView(centralwidget);
        ShowInfotableView->setObjectName("ShowInfotableView");
        ShowInfotableView->setGeometry(QRect(0, 40, 801, 541));
        ShowInfotableView->setStyleSheet(QString::fromUtf8(""));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(260, 0, 101, 41));
        deleteButton->setStyleSheet(QString::fromUtf8("border-image: url(:/pictures/style-5.qss.png);"));
        actionmingdanshaixuan = new QPushButton(centralwidget);
        actionmingdanshaixuan->setObjectName("actionmingdanshaixuan");
        actionmingdanshaixuan->setGeometry(QRect(550, 0, 93, 41));
        actionmingdanshaixuan->setStyleSheet(QString::fromUtf8("border-image: url(:/pictures/style-5.qss.png);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 805, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        OpenFile->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        SaveFile->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
        addpushButton->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\350\201\214\345\267\245", nullptr));
        DisplayInformation->setText(QCoreApplication::translate("MainWindow", "\350\201\214\345\267\245\344\277\241\346\201\257\350\241\250", nullptr));
        DisplaySalary->setText(QCoreApplication::translate("MainWindow", "\350\201\214\345\267\245\346\234\210\345\267\245\350\265\204\350\241\250", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        actionmingdanshaixuan->setText(QCoreApplication::translate("MainWindow", "\347\255\233\351\200\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
