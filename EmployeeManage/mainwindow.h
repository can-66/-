#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include"employeeinfotable.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //在表格中显示信息表
    void ShowInformationTable();
    //在表格中显示各类补贴
    void ShowSalaryTable();
    //在表格中显示筛选名单
    void ShowSpecialList(int typeID, int RatioID, float valuedata);

private slots:

    void on_addpushButton_clicked();

    void on_DisplayInformation_clicked();

    void on_DisplaySalary_clicked();

    void on_OpenFile_clicked();

    void on_SaveFile_clicked();

    void on_ShowInfotableView_changed();

    void on_deleteButton_clicked();

    void on_actionmingdanshaixuan_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel * employeesInforModel; //显示表格信息数据模型
    //QStandardItemModel 是 Qt 中的一个标准数据模型，用于在 QTableView 或 QListView 等视图中显示二维数据。
    EmployeeInfoTable m_InfoTable; //数据汇总类
    int m_iCurTable; //表示当前表格显示的信息，0--初始状态；1--显示职工信息；2--显示是职工各类工资成绩；3--显示筛选名单
};
#endif // MAINWINDOW_H
