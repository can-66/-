#include "employeeinfotable.h"

EmployeeInfoTable::EmployeeInfoTable() {}

//从文件中读取职工信息
bool EmployeeInfoTable::ReadEmployeesFromFile(const QString &aReadFileName)
{
    QFile file(aReadFileName);
    if (!file.exists()) // 文件不存在
        return false;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {//以文本方式打开
        return false;
    }

    QTextStream aStream(&file);
    //初始化
    m_employees.clear();
    m_number=0;
    //逐个读取职工信息
    aStream>>m_number;//运动员总数

    CEmployee tempemployee;
    if(m_number>0)
    {
        for(int i=0;i<m_number;++i){
        tempemployee.ReadEmployee(aStream);
            m_employees.push_back(tempemployee);
        }
    }
    file.close();//关闭文件
    return true;
}

//保存职工信息到文件
bool EmployeeInfoTable::SaveEmployeesToFile(const QString &aSaveFileName)
{
    QFile aFile(aSaveFileName);
    if (!aFile.open(QIODevice::WriteOnly | QIODevice::Text)) // 保存为文本
      return false;

    QTextStream aStream(&aFile);//用文件流保存文件

    //逐个写入职工信息
    aStream<<m_number<<'\n';//职工总数
    if(m_number>0)
    {
        for(int i=0;i<m_number;++i)
        {
            m_employees[i].SaveEmployee(aStream);
        }
    }
        aFile.close();
        return true;

}
//添加职工
void EmployeeInfoTable::AddEmployee(CEmployee &employee)
{
    m_employees.push_back(employee);
    m_number++;

}
//删除职工
void EmployeeInfoTable::RemoveEmployee(QString number)
{
    for (int i = 0; i < m_employees.size(); ++i) {
        if (m_employees[i].m_id == number) {
            m_employees.removeAt(i);
            m_number =m_employees.size();
            break;
        }
    }
}
//获取特定职工信息
CEmployee& EmployeeInfoTable::GetEmployee(int index)
{
    return m_employees[index];

}
//获取职工总数
int EmployeeInfoTable::GetEmployeeNum()
{
    m_number=m_employees.size();
    return m_number;

}
