/********************************************************************************
** Form generated from reading UI file 'addemployee.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEMPLOYEE_H
#define UI_ADDEMPLOYEE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddEmployee
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *textEditId;
    QLineEdit *textEditName;
    QLineEdit *textEditAge;
    QLineEdit *textEditNumber;
    QLabel *label_5;
    QLineEdit *textEditAddress;
    QLabel *label_6;
    QDateEdit *textEditdate;

    void setupUi(QDialog *AddEmployee)
    {
        if (AddEmployee->objectName().isEmpty())
            AddEmployee->setObjectName("AddEmployee");
        AddEmployee->resize(400, 300);
        AddEmployee->setStyleSheet(QString::fromUtf8("background-image: url(:/pictures/style-1.qss.png);"));
        buttonBox = new QDialogButtonBox(AddEmployee);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(-60, 270, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(AddEmployee);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 10, 69, 19));
        label_2 = new QLabel(AddEmployee);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 50, 69, 19));
        label_3 = new QLabel(AddEmployee);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 90, 69, 19));
        label_4 = new QLabel(AddEmployee);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 140, 69, 19));
        textEditId = new QLineEdit(AddEmployee);
        textEditId->setObjectName("textEditId");
        textEditId->setGeometry(QRect(160, 10, 113, 25));
        textEditName = new QLineEdit(AddEmployee);
        textEditName->setObjectName("textEditName");
        textEditName->setGeometry(QRect(160, 50, 113, 25));
        textEditAge = new QLineEdit(AddEmployee);
        textEditAge->setObjectName("textEditAge");
        textEditAge->setGeometry(QRect(160, 90, 113, 25));
        textEditNumber = new QLineEdit(AddEmployee);
        textEditNumber->setObjectName("textEditNumber");
        textEditNumber->setGeometry(QRect(160, 190, 141, 25));
        label_5 = new QLabel(AddEmployee);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 190, 69, 19));
        textEditAddress = new QLineEdit(AddEmployee);
        textEditAddress->setObjectName("textEditAddress");
        textEditAddress->setGeometry(QRect(160, 230, 141, 25));
        label_6 = new QLabel(AddEmployee);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 230, 69, 19));
        textEditdate = new QDateEdit(AddEmployee);
        textEditdate->setObjectName("textEditdate");
        textEditdate->setGeometry(QRect(160, 140, 110, 25));

        retranslateUi(AddEmployee);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddEmployee, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddEmployee, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddEmployee);
    } // setupUi

    void retranslateUi(QDialog *AddEmployee)
    {
        AddEmployee->setWindowTitle(QCoreApplication::translate("AddEmployee", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddEmployee", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">\345\267\245\345\217\267</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("AddEmployee", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">\345\247\223\345\220\215</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("AddEmployee", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">\345\271\264\351\276\204</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("AddEmployee", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">\345\205\245\350\201\214\346\227\245\346\234\237</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("AddEmployee", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">\347\224\265\350\257\235</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("AddEmployee", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">\344\275\217\345\235\200</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddEmployee: public Ui_AddEmployee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEMPLOYEE_H
