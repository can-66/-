#include "addemployee.h"
#include "ui_addemployee.h"

AddEmployee::AddEmployee(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddEmployee)
{
    ui->setupUi(this);
    //填写文字颜色
    ui->textEditId->setStyleSheet("QLineEdit { color: white; }");
    ui->textEditName->setStyleSheet("QLineEdit { color: white; }");
    ui->textEditAge->setStyleSheet("QLineEdit { color: white; }");
    ui->textEditNumber->setStyleSheet("QLineEdit { color: white; }");
    ui->textEditAddress->setStyleSheet("QLineEdit { color: white; }");
}

AddEmployee::~AddEmployee()
{
    delete ui;
}
QString AddEmployee::Name()
{
    return ui->textEditName->text();

}
QString AddEmployee::ID()
{
    return ui->textEditId->text();

}
int AddEmployee::Age()
{
    QString sAge=ui->textEditAge->text();
    int age=sAge.toInt();
    return age;
}
QDate AddEmployee::HireDate()
{
    return ui->textEditdate->date();
}
QString AddEmployee::Phone()
{
    return ui->textEditNumber->text();
}
QString AddEmployee::Address()
{
    return ui->textEditAddress->text();

}

