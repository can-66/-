#ifndef EMPLOYEEINFOTABLE_H
#define EMPLOYEEINFOTABLE_H
#include "cemployee.h"
#include <QVector>
#include<QFile>
class EmployeeInfoTable
{
public:
    EmployeeInfoTable();
    //从文件中读取职工信息
    bool ReadEmployeesFromFile(const QString &aReadFileName);
    //保存职工信息到文件
    bool SaveEmployeesToFile(const QString &aSaveFileName);
    //添加职工
    void AddEmployee(CEmployee &employee);
    //删除特定职工
    void RemoveEmployee(QString index);
    //获取特定职工信息
    CEmployee& GetEmployee(int index);
    //获取职工总数
    int GetEmployeeNum();

private:
    QVector<CEmployee> m_employees; // 职工列表
    int m_number; // 职工总数
};

#endif // EMPLOYEEINFOTABLE_H
