#include "cemployee.h"

CEmployee::CEmployee() {}
CEmployee::CEmployee(const CEmployee& employee)
{
    m_id = employee.m_id;
    m_name = employee.m_name;
    m_age = employee.m_age;
    m_hireDate = employee.m_hireDate;
    m_phone = employee.m_phone;
    m_address = employee.m_address;
    m_salary = employee.m_salary;

}
CEmployee& CEmployee::operator=(const CEmployee & employee)
{
    if(this!=& employee)
    {
        m_id = employee.m_id;
        m_name = employee.m_name;
        m_age = employee.m_age;
        m_hireDate = employee.m_hireDate;
        m_phone = employee.m_phone;
        m_address = employee.m_address;
        m_salary = employee.m_salary;
    }
    return *this;
}
//保存职工信息到文件
void CEmployee::SaveEmployee(QTextStream &aStream)
{
    aStream << m_id << " "
            << m_name << " "
            << m_age << " "
            << m_hireDate.toString("yyyy-MM-dd") << " "
            << m_phone << " "
            << m_address << "\n";

    m_salary.SaveSalary(aStream); // 保存工资信息

}
//从文件读取职工信息
void CEmployee::ReadEmployee(QTextStream &aStream)
{
    QString dateStr;
    aStream >> m_id >> m_name >> m_age >> dateStr >> m_phone >> m_address;
    m_hireDate = QDate::fromString(dateStr, "yyyy-MM-dd");

    m_salary.ReadSalary(aStream); // 读取工资信息

}
//析构函数
CEmployee::~CEmployee(){}




