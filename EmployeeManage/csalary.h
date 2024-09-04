#ifndef CSALARY_H
#define CSALARY_H

#include <QString>
#include <QTextStream>

typedef struct SalaryRecord
{
    QString m_month;//月份
    float m_basicSalary;//基本工资
    float m_positionSalary;//岗位工资
    float m_workYearSalary;//工龄工资
    float m_allowance;//津贴
    float m_positionAllowance;//岗贴
    float m_subsidy;//补贴
    float m_houseSubsidy;//房贴
    float m_transportSubsidy;//交通补贴
} SalaryRecord;

class CSalary
{
public:
    CSalary();
    virtual ~CSalary();

    CSalary(const CSalary &salary);
    CSalary& operator=(const CSalary &salary);
    void CalculateBefore();//计算扣税前的工资

    void CalculateNetSalary(); // 计算实发工资
    float CalculateTax(float totalSalary); // 计算个人所得税

    void SaveSalary(QTextStream &aStream); // 保存工资信息到文件
    void ReadSalary(QTextStream &aStream); // 从文件读取工资信息

    SalaryRecord m_record;//各类工资的结构体
    float m_totalSalary;//未扣税前的工资
    float m_netSalary; // 实发工资
};

#endif // CSALARY_H
