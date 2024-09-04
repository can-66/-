#ifndef ADDEMPLOYEE_H
#define ADDEMPLOYEE_H

#include <QDialog>
#include<QString>

namespace Ui {
class AddEmployee;
}

class AddEmployee : public QDialog
{
    Q_OBJECT

public:
    explicit AddEmployee(QWidget *parent = nullptr);
    ~AddEmployee();
    //这些成员函数用于获取用户在界面中输入的各种员工信息
    QString Name();
    QString  ID();
    int Age();
    QDate HireDate();
    QString Phone();
    QString Address();

private:
    Ui::AddEmployee *ui;
};

#endif // ADDEMPLOYEE_H
