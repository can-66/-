#ifndef CEMPLOYEE_H
#define CEMPLOYEE_H
#include"CSalary.h"
#include<QString>
#include<QDate>
#include<QTextStream>
class CEmployee
{
public:
    CEmployee();//默认构造
    CEmployee(const CEmployee& employee);//拷贝
    CEmployee& operator=(const CEmployee& employee);//重载=运算符
    virtual~CEmployee();//析构

    void SaveEmployee(QTextStream & aStream);//保存职工信息到文件
    void ReadEmployee(QTextStream & aStream);//读取职工信息到文件

    QString m_id;          // 工号
    QString m_name;        // 姓名
    int m_age;             // 年龄
    QDate m_hireDate;      // 入职日期
    QString m_phone;       // 电话
    QString m_address;     // 住址
    CSalary m_salary;      //各类工资信息

};

#endif // CEMPLOYEE_H
