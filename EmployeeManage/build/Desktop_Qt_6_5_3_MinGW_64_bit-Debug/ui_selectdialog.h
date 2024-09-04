/********************************************************************************
** Form generated from reading UI file 'selectdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTDIALOG_H
#define UI_SELECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectDialog
{
public:
    QComboBox *comboSpecialItem;
    QLabel *label;
    QPushButton *btnCancel;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioGreater;
    QRadioButton *radioEqual;
    QRadioButton *radioLower;
    QLineEdit *lineEditSelectedValue;
    QLabel *label_2;
    QLabel *label_unit;
    QPushButton *btnOK;

    void setupUi(QDialog *SelectDialog)
    {
        if (SelectDialog->objectName().isEmpty())
            SelectDialog->setObjectName("SelectDialog");
        SelectDialog->resize(400, 300);
        SelectDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/pictures/style-1.qss.png);"));
        comboSpecialItem = new QComboBox(SelectDialog);
        comboSpecialItem->addItem(QString());
        comboSpecialItem->addItem(QString());
        comboSpecialItem->setObjectName("comboSpecialItem");
        comboSpecialItem->setGeometry(QRect(90, 10, 201, 31));
        comboSpecialItem->setStyleSheet(QString::fromUtf8("background-image: url(:/pictures/style-2.qss.png);"));
        label = new QLabel(SelectDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 54, 21));
        btnCancel = new QPushButton(SelectDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(180, 210, 75, 23));
        groupBox = new QGroupBox(SelectDialog);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 60, 301, 141));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 70, 261, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioGreater = new QRadioButton(horizontalLayoutWidget);
        radioGreater->setObjectName("radioGreater");

        horizontalLayout->addWidget(radioGreater);

        radioEqual = new QRadioButton(horizontalLayoutWidget);
        radioEqual->setObjectName("radioEqual");

        horizontalLayout->addWidget(radioEqual);

        radioLower = new QRadioButton(horizontalLayoutWidget);
        radioLower->setObjectName("radioLower");

        horizontalLayout->addWidget(radioLower);

        lineEditSelectedValue = new QLineEdit(groupBox);
        lineEditSelectedValue->setObjectName("lineEditSelectedValue");
        lineEditSelectedValue->setGeometry(QRect(90, 30, 121, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 40, 54, 21));
        label_unit = new QLabel(groupBox);
        label_unit->setObjectName("label_unit");
        label_unit->setGeometry(QRect(220, 40, 54, 21));
        btnOK = new QPushButton(SelectDialog);
        btnOK->setObjectName("btnOK");
        btnOK->setGeometry(QRect(70, 210, 75, 23));

        retranslateUi(SelectDialog);

        QMetaObject::connectSlotsByName(SelectDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectDialog)
    {
        SelectDialog->setWindowTitle(QCoreApplication::translate("SelectDialog", "Dialog", nullptr));
        comboSpecialItem->setItemText(0, QCoreApplication::translate("SelectDialog", "\345\271\264\351\276\204", nullptr));
        comboSpecialItem->setItemText(1, QCoreApplication::translate("SelectDialog", "\345\256\236\345\217\221\345\267\245\350\265\204", nullptr));

        label->setText(QCoreApplication::translate("SelectDialog", "<html><head/><body><p><span style=\" font-size:11pt;\">\347\211\271\345\276\201\351\241\271\357\274\232</span></p></body></html>", nullptr));
        btnCancel->setText(QCoreApplication::translate("SelectDialog", "Cancel", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SelectDialog", "\351\200\211\351\241\271", nullptr));
        radioGreater->setText(QCoreApplication::translate("SelectDialog", "\351\253\230\344\272\216", nullptr));
        radioEqual->setText(QCoreApplication::translate("SelectDialog", "\347\255\211\344\272\216", nullptr));
        radioLower->setText(QCoreApplication::translate("SelectDialog", "\344\275\216\344\272\216", nullptr));
        label_2->setText(QCoreApplication::translate("SelectDialog", "<html><head/><body><p><span style=\" font-size:11pt;\">\346\225\260\345\200\274\357\274\232</span></p></body></html>", nullptr));
        label_unit->setText(QCoreApplication::translate("SelectDialog", "<html><head/><body><p>\345\262\201</p></body></html>", nullptr));
        btnOK->setText(QCoreApplication::translate("SelectDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectDialog: public Ui_SelectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTDIALOG_H
