#include "csalary.h"

CSalary::CSalary()
{
    m_record.m_month=' ';
    m_record.m_basicSalary=0.0f;
    m_record.m_positionSalary=0.0f;
    m_record.m_workYearSalary=0.0f;
    m_record.m_positionAllowance=0.0f;
    m_record.m_allowance=0.0f;
    m_record.m_houseSubsidy=0.0f;
    m_record.m_transportSubsidy=0.0f;
    m_record.m_subsidy=0.0f;

}

CSalary::~CSalary(){}

CSalary::CSalary(const CSalary &salary)
{
    m_record=salary.m_record;
}
CSalary& CSalary::operator=(const CSalary&salary )
{
    if(this !=&salary){
        m_record=salary.m_record;
        m_netSalary=salary.m_netSalary;
    }
    return *this;
}
void CSalary::CalculateBefore()
{
    m_totalSalary= m_record.m_basicSalary + m_record.m_positionSalary + m_record.m_workYearSalary +
                  m_record.m_allowance + m_record.m_positionAllowance + m_record.m_subsidy +
                  m_record.m_houseSubsidy + m_record.m_transportSubsidy;

}
//计算个人所得税
float CSalary::CalculateTax(float totalSalary)
{
    float tax=0.0f;
    if(totalSalary<=800)
    {
        tax=0.0f;
    }
    else if(totalSalary<=1000)
    {
        tax=(totalSalary-800)*0.05f;
    }else if(totalSalary<=5000)
    {
        tax=(1000-800)*0.05f+(totalSalary-1000)*0.1f;
    }else
    {
        tax=(1000-800)*0.05f+(5000-1000)*0.10f+(totalSalary-5000)*0.20f;
    }
    return tax;

}

//计算工资
void CSalary::CalculateNetSalary()
{
    float totalSalary = m_record.m_basicSalary + m_record.m_positionSalary + m_record.m_workYearSalary +
                        m_record.m_allowance + m_record.m_positionAllowance + m_record.m_subsidy +
                        m_record.m_houseSubsidy + m_record.m_transportSubsidy;
    float tax=CalculateTax(totalSalary);
    m_netSalary=totalSalary-tax;
}
//保存工资信息到文件
void CSalary::SaveSalary(QTextStream &aStream)
{
    aStream << m_record.m_month << " "
            << m_record.m_basicSalary << " "
            << m_record.m_positionSalary << " "
            << m_record.m_workYearSalary << " "
            << m_record.m_allowance << " "
            << m_record.m_positionAllowance << " "
            << m_record.m_subsidy << " "
            << m_record.m_houseSubsidy << " "
            << m_record.m_transportSubsidy << "\n";
}

// 从文件读取工资信息
void CSalary::ReadSalary(QTextStream &aStream)
{
    aStream >> m_record.m_month
        >> m_record.m_basicSalary
        >> m_record.m_positionSalary
        >> m_record.m_workYearSalary
        >> m_record.m_allowance
        >> m_record.m_positionAllowance
        >> m_record.m_subsidy
        >> m_record.m_houseSubsidy
        >> m_record.m_transportSubsidy;
}

