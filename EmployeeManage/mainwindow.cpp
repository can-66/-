#include "mainwindow.h"
#include "addemployee.h"
#include "cemployee.h"
#include "ui_mainwindow.h"
#include"readonlydelegate.h"
#include"CSalary.h"
#include<QDir>
#include<QFileDialog>
#include<QCheckBox>
#include <QHBoxLayout>
#include <QWidget>
#include<QMessageBox>
#include"selectdialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ShowInfotableView->setStyleSheet(
        "QTableView {"
        "background-color: lightgray;"  //表格背景颜色
        "gridline-color: black;"        // 网格线颜色
        "}"

        "QTableView::item {"
        "color: blue;"                // 单元格文本颜色
        "font-family: Arial;"         // 单元格字体
        "font-size: 12pt;"            // 单元格字体大小
        "font-weight: bold;"          // 单元格字体粗细
        "}"

        "QHeaderView::section {"
        "background-color: darkgray;" // 表头背景颜色
        "color: white;"               // 表头文本颜色
        "font-family: Arial;"         // 表头字体
        "font-size: 10pt;"            // 表头字体大小
        "font-weight: bold;"          // 表头字体粗细
        "}"
        );



    ui->ShowInfotableView->setSelectionMode(QAbstractItemView::SingleSelection); //单次选择
    //这行代码设置了 QTableView 的选择模式为 单次选择 (SingleSelection)，即用户在表格中一次只能选择
    //一个单元格或一行/列，而不能进行多选。
    ui->ShowInfotableView->setSelectionBehavior(QAbstractItemView::SelectItems); //选中一个item
    //这行代码设置了 QTableView 的选择行为为 选择单元格 (SelectItems)，即用户点击时只能选中单个单元格。
    //你还可以将其设置为选择整行 (SelectRows) 或整列 (SelectColumns)，根据需要更改选择行为。

    employeesInforModel = new QStandardItemModel();
    //这行代码创建了一个新的 QStandardItemModel 实例，employeesInforModel 用于管理和存储 QTableView 显示的数据。
    //QStandardItemModel 是一个可以存储任意数据的模型，适合用于 QTableView、QTreeView 等视图控件。

    //建立关联
    ui->ShowInfotableView->setModel(employeesInforModel);

    connect(ui->ShowInfotableView->itemDelegate(), &QAbstractItemDelegate::closeEditor, this, [this]() {
        this->on_ShowInfotableView_changed();
    });

    m_iCurTable = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::ShowInformationTable()
{
    m_iCurTable = 1; // 表示当前显示的是职工基本信息
    employeesInforModel->clear(); // 清空表格数据及表头
    employeesInforModel->setColumnCount(7); // 7列 (包括新增的QCheckBox列)

    // 表头
    // 复选框、工号、姓名、年龄、入职日期、电话、住址
    QStringList templist; // QStingList 是Qt中储存QString的容器
    templist.append(""); // 第一列空白，用于放置QCheckBox
    templist.append("工号");
    templist.append("姓名");
    templist.append("年龄");
    templist.append("入职日期");
    templist.append("电话");
    templist.append("住址");
    employeesInforModel->setHorizontalHeaderLabels(templist); // 设置表格水平横向表头，templist每一个元素为每一列的表头

    int RowCnt = m_InfoTable.GetEmployeeNum(); // 行数（不含标题）
    employeesInforModel->setRowCount(RowCnt);

    // 遍历，插入数据
    for(int i = 0; i < RowCnt; ++i)
    {
        CEmployee tempemployee = m_InfoTable.GetEmployee(i);

        // 使用 QStandardItem 来管理 QCheckBox 的状态
        QStandardItem *checkItem = new QStandardItem();
        checkItem->setCheckable(true); // 设置为可选中
        checkItem->setCheckState(Qt::Unchecked); // 默认未选中
        employeesInforModel->setItem(i, 0, checkItem); // 在第一列添加复选框



        QStandardItem *aTempItem = new QStandardItem(tempemployee.m_id);
        employeesInforModel->setItem(i, 1, aTempItem); // 设置表格的第一行第二列为aTempItem
        aTempItem = new QStandardItem(tempemployee.m_name);
        employeesInforModel->setItem(i, 2, aTempItem);
        QString tempStr = QString::number(tempemployee.m_age);
        aTempItem = new QStandardItem(tempStr);
        employeesInforModel->setItem(i, 3, aTempItem);
        tempStr = tempemployee.m_hireDate.toString("yyyy-MM-dd");
        aTempItem = new QStandardItem(tempStr);
        employeesInforModel->setItem(i, 4, aTempItem);
        // 电话
        aTempItem = new QStandardItem(tempemployee.m_phone);
        employeesInforModel->setItem(i, 5, aTempItem);
        // 住址
        aTempItem = new QStandardItem(tempemployee.m_address);
        employeesInforModel->setItem(i, 6, aTempItem);
    }

    // 设置工号为只读
    ReadOnlyDelegate* readOnlyDelegate = new ReadOnlyDelegate(this);
    ui->ShowInfotableView->setItemDelegateForColumn(1, readOnlyDelegate);
}


void MainWindow::on_addpushButton_clicked()
{
    AddEmployee dlgSignup(this);
    int ret = dlgSignup.exec(); //以模态方式显示对话框
    if(ret==QDialog::Accepted)
    {
        //如果OK按钮被按下
        CEmployee tempemployee;
        tempemployee.m_id=dlgSignup.ID();
        tempemployee.m_name=dlgSignup.Name();
        tempemployee.m_address=dlgSignup.Address();
        tempemployee.m_hireDate=dlgSignup.HireDate();
        tempemployee.m_phone=dlgSignup.Phone();
        tempemployee.m_age=dlgSignup.Age();
        m_InfoTable.AddEmployee(tempemployee);
        ShowInformationTable();

    }
}
void MainWindow::ShowSalaryTable()
{
    m_iCurTable = 2;  // 表示当前显示职工各类工资
    employeesInforModel->clear();
    employeesInforModel->setColumnCount(13);  // 增加一列用于 QCheckBox

    // 表头
    QStringList templist;
    templist.append("");  // 第一列用于 QCheckBox，不需要表头
    templist.append("工号");
    templist.append("姓名");
    templist.append("月份");
    templist.append("基本工资");
    templist.append("岗位工资");
    templist.append("工龄工资");
    templist.append("津贴");
    templist.append("岗贴");
    templist.append("补贴");
    templist.append("房贴");
    templist.append("交通补贴");
    templist.append("个人所得税");
    templist.append("实发工资");
    employeesInforModel->setHorizontalHeaderLabels(templist);

    int RowCnt = m_InfoTable.GetEmployeeNum();  // 行数（不含标题）
    employeesInforModel->setRowCount(RowCnt);

    // 遍历，插入数据
    QString tempStr;
    for (int i = 0; i < RowCnt; ++i)
    {
        CEmployee tempemployee = m_InfoTable.GetEmployee(i);

        // 使用 QStandardItem 来管理 QCheckBox 的状态
        QStandardItem *checkItem = new QStandardItem();
        checkItem->setCheckable(true); // 设置为可选中
        checkItem->setCheckState(Qt::Unchecked); // 默认未选中
        employeesInforModel->setItem(i, 0, checkItem); // 在第一列添加复选框


        QStandardItem *aTempItem;

        aTempItem = new QStandardItem(tempemployee.m_id);//工号
        employeesInforModel->setItem(i, 1, aTempItem);
        aTempItem = new QStandardItem(tempemployee.m_name);//姓名
        employeesInforModel->setItem(i, 2, aTempItem);
        aTempItem = new QStandardItem(tempemployee.m_salary.m_record.m_month);  // 月份
        employeesInforModel->setItem(i, 3, aTempItem);
        tempStr = QString::number(tempemployee.m_salary.m_record.m_basicSalary);  // 基本工资
        aTempItem = new QStandardItem(tempStr);
        employeesInforModel->setItem(i, 4, aTempItem);
        tempStr = QString::number(tempemployee.m_salary.m_record.m_positionSalary);  // 岗位工资
        aTempItem = new QStandardItem(tempStr);
        employeesInforModel->setItem(i, 5, aTempItem);
        tempStr = QString::number(tempemployee.m_salary.m_record.m_workYearSalary);  // 工龄工资
        aTempItem = new QStandardItem(tempStr);
        employeesInforModel->setItem(i, 6, aTempItem);
        tempStr = QString::number(tempemployee.m_salary.m_record.m_allowance);  // 津贴
        aTempItem = new QStandardItem(tempStr);
        employeesInforModel->setItem(i, 7, aTempItem);
        tempStr = QString::number(tempemployee.m_salary.m_record.m_positionAllowance);  // 岗贴
        aTempItem = new QStandardItem(tempStr);
        employeesInforModel->setItem(i, 8, aTempItem);
        tempStr = QString::number(tempemployee.m_salary.m_record.m_subsidy);  // 补贴
        aTempItem = new QStandardItem(tempStr);
        employeesInforModel->setItem(i, 9, aTempItem);
        tempStr = QString::number(tempemployee.m_salary.m_record.m_houseSubsidy);  // 房贴
        aTempItem = new QStandardItem(tempStr);
        employeesInforModel->setItem(i, 10, aTempItem);
        tempStr = QString::number(tempemployee.m_salary.m_record.m_transportSubsidy);  // 交通补贴
        aTempItem = new QStandardItem(tempStr);
        employeesInforModel->setItem(i, 11, aTempItem);
        tempemployee.m_salary.CalculateBefore();
        float s_Tax = tempemployee.m_salary.CalculateTax(tempemployee.m_salary.m_totalSalary);
        tempStr = QString::number(s_Tax);  // 个人所得税
        aTempItem = new QStandardItem(tempStr);
        employeesInforModel->setItem(i, 12, aTempItem);
        tempemployee.m_salary.CalculateNetSalary();
        tempStr = QString::number(tempemployee.m_salary.m_netSalary);  // 实发工资
        aTempItem = new QStandardItem(tempStr);
        employeesInforModel->setItem(i, 13, aTempItem);
    }
    //自动调整列宽和行高
    ui->ShowInfotableView->resizeColumnsToContents();
    ui->ShowInfotableView->resizeRowsToContents();

}
//在表格中显示筛选名单
void MainWindow:: ShowSpecialList(int typeID, int RatioID, float valuedata)
{
    m_iCurTable = 3; // 表示当前显示的是筛选后的表格
    employeesInforModel->clear(); // 清空表格数据及表头
    employeesInforModel->setColumnCount(4); // 4列 (包括新增的QCheckBox列)

    QStringList templist;
    templist.append("");  // 第一列用于 QCheckBox，不需要表头
    templist.append("工号");
    templist.append("姓名");
    templist.append("实发工资");
    employeesInforModel->setHorizontalHeaderLabels(templist);
    int EmployeeNum = m_InfoTable.GetEmployeeNum(); //运动员总数
    int RowIndex = 0;
    float Var;
    for(int i=0; i<EmployeeNum; ++i)
    {
        CEmployee tempemployee=m_InfoTable.GetEmployee(i);

        //筛选
        if(typeID==0) //身高
            Var = tempemployee.m_age;
        else //体重
            Var = tempemployee.m_salary.m_netSalary;

        switch (RatioID)
        {
        case 0: //高于
            if(Var<=valuedata)
                continue;
            break;
        case 1: //等于
            if(Var!=valuedata)
                continue;
            break;
        case 2: //低于
            if(Var>=valuedata)
                continue;
            break;
        default:
            break;
        }
        // 使用 QStandardItem 来管理 QCheckBox 的状态
        QStandardItem *checkItem = new QStandardItem();
        checkItem->setCheckable(true); // 设置为可选中
        checkItem->setCheckState(Qt::Unchecked); // 默认未选中
        employeesInforModel->setItem(RowIndex, 0, checkItem); // 在第一列添加复选框

        QStandardItem *aTempItem;

        aTempItem = new QStandardItem(tempemployee.m_id);//工号
        employeesInforModel->setItem(RowIndex, 1, aTempItem);
        aTempItem = new QStandardItem(tempemployee.m_name);//姓名
        employeesInforModel->setItem(RowIndex, 2, aTempItem);
        tempemployee.m_salary.CalculateNetSalary();
        QString tempStr;
        tempStr = QString::number(tempemployee.m_salary.m_netSalary);  // 实发工资
        aTempItem = new QStandardItem(tempStr);
        employeesInforModel->setItem(RowIndex, 3, aTempItem);
        RowIndex++;
    }


}




void MainWindow::on_DisplayInformation_clicked()
{
    ShowInformationTable();
}


void MainWindow::on_DisplaySalary_clicked()
{
    ShowSalaryTable();

}


void MainWindow::on_OpenFile_clicked()
{
    //获取当前程序路径保存到curPath中，QDir是Qt中的一个类，用于处理和操作文件系统中的目录
    //QDir::currentPath() 是一个静态函数，用于返回程序当前的工作目录路径。
    QString curPath = QDir::currentPath();
    //定义文件选择对话框的标题
    QString dlgTitle = "选择一个文件";
    //定义文件过滤器，用于限制用户可以选择的文件类型。filter 指定了两种过滤规则：
    //  文本文件(*.txt): 只显示 .txt 扩展名的文件。
    // 所有文件(*.*): 显示所有类型的文件。
     QString filter = "文本文件(*.txt);;所有文件(*.*)";

    //打开一个文件选择对话框，允许用户选择一个文件。对话框的标题为 dlgTitle，初始路径为 curPath，
    //并根据 filter 进行文件类型过滤。用户选择的文件路径和名称被存储在 aFileName 中。
    QString aFileName = QFileDialog::getOpenFileName(this, dlgTitle, curPath, filter);

    //如果为选择文件则直接返回
    if(aFileName.isEmpty())
            return;

        //创建成功，打开文件
        //将用户选择的文件路径 aFileName 传递给该方法。该方法应该实现从文件中读取数据并将其加载到程序的内存中。
    m_InfoTable.ReadEmployeesFromFile(aFileName);
        //刷新界面，显示从文件中读取的数据
    ShowInformationTable();
}

void MainWindow::on_SaveFile_clicked()
{
    QString curPath = QDir::currentPath();
    QString dlgTitle = "另存为一个文件";
    QString filter = "文本文件(*.txt);;所有文件(*.*)";
    QString aFileName = QFileDialog::getSaveFileName(this, dlgTitle, curPath, filter);
    //QFileDialog::getSaveFileName 是 Qt 提供的一个静态函数，用于显示“保存文件”对话框，允许用户选择一个
    //保存文件的位置和文件名。该函数返回用户选择的文件的完整路径,this指mainwindow

    if(aFileName.isEmpty())
            return;

     m_InfoTable.SaveEmployeesToFile(aFileName);

}
void MainWindow::on_ShowInfotableView_changed()
{
    QModelIndex index=ui->ShowInfotableView->currentIndex();
    //ui->ShowInfotableView: 这是一个指向 QTableView 对象的指针
    //currentIndex(): 这是 QTableView 类的一个成员函数，返回一个 QModelIndex 对象，表示当前在视图中选中的单元格的位置。
    //如果没有选中的单元格，这个函数将返回一个无效的 QModelIndex。
    //QModelIndex 是 Qt 中用于表示模型/视图框架中一个特定位置的类。它包含了在模型中的行、列以及模型的内部状态等信息

    int iemployee=index.row();//哪位职工
    int iCol=index.column();//哪一列
    CEmployee &employee=m_InfoTable.GetEmployee(iemployee);//获取当前职工
    QVariant data;//数据
    //QVariant 是一个通用的数据容器，可以用于存储和传递不同的数据类型，而不需要知道数据的确切类型
    switch(m_iCurTable)//根据当前选择的表格不同进行相应的修改
    {
    case 1://当前职工基本信息表
        //修改职工对应的数值
        data=employeesInforModel->data(index);//data 函数 用于从模型中获取特定位置的数据

        switch(iCol)
        {
            //工号、姓名、年龄、入职日期、电话、住址
        case 1://工号
            employee.m_id=data.toString();
            break;
        case 2://姓名
            employee.m_name=data.toString();
            break;
        case 3://年龄
            employee.m_age=data.toInt();
            break;
        case 4://入职日期
            employee.m_hireDate=data.toDate();
            break;
        case 5://电话
            employee.m_phone=data.toString();
            break;
        case 6://住址
            employee.m_address=data.toString();
            break;
        default:
            break;
        }
        ShowInformationTable();
        break;
    case 2://当前是职工工资信息，修改工资信息
        //姓名，月份，基本工资，岗位工资，工龄工资，津贴，岗贴，补贴，房贴，交通补贴，个人所得税，实发工资//个人所得税，实发工资不可修改
        data=employeesInforModel->data(index);//data 函数 用于从模型中获取特定位置的数据
        switch(iCol)
        {
        case 1://工号
            employee.m_id=data.toString();
            break;
        case 2://姓名
            employee.m_name=data.toString();
            break;
        case 3://月份
            employee.m_salary.m_record.m_month=data.toString();
            break;
        case 4://基本工资
            employee.m_salary.m_record.m_basicSalary=data.toFloat();
            break;
        case 5://岗位工资
            employee.m_salary.m_record.m_positionSalary=data.toFloat();
            break;
        case 6://工龄工资
            employee.m_salary.m_record.m_workYearSalary=data.toFloat();
            break;
        case 7://津贴
            employee.m_salary.m_record.m_allowance=data.toFloat();
            break;
        case 8://岗贴
            employee.m_salary.m_record.m_positionAllowance=data.toFloat();
            break;
        case 9://补贴
            employee.m_salary.m_record.m_subsidy=data.toFloat();
            break;
        case 10://房贴
            employee.m_salary.m_record.m_houseSubsidy=data.toFloat();
            break;
        case 11://交通补贴
            employee.m_salary.m_record.m_transportSubsidy=data.toFloat();
            break;
        default:
            break;
        }
        ShowSalaryTable();//重新显示，更新数据
        break;

    }

}

void MainWindow::on_deleteButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认删除", "确定要删除选中的职工吗？", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QStandardItemModel *model = qobject_cast<QStandardItemModel *>(ui->ShowInfotableView->model());
        if (!model) {
            qDebug() << "无法转换模型类型。";
            return;
        }

        qDebug() << "行数：" << model->rowCount();

        for (int i = model->rowCount() - 1; i >= 0; --i) {
            QStandardItem *item = model->item(i, 0); // 假设 QCheckBox 在第一列
            if (!item) {
                qDebug() << "item 为 nullptr, 第 " << i << " 行的第一列没有 item.";
                continue;
            }

            qDebug() << "行 " << i << " 的 checkState 是：" << item->checkState();

            if (item->checkState() == Qt::Checked) {
                QString numberToDelete = model->item(i, 1)->text(); // 假设员工 ID 在第二列
                qDebug() << "删除职工编号：" << numberToDelete;
                m_InfoTable.RemoveEmployee(numberToDelete); // 从数据结构中删除
                model->removeRow(i); // 从模型中删除（因此也会从视图中删除）
                qDebug() << "删除成功";
            } else {
                qDebug() << "第 " << i << " 行未被选中，跳过删除。";
            }
        }
    }
}


 void MainWindow:: on_actionmingdanshaixuan_clicked()
{
     SelectDialog dlgSelectDlg(this);
    int ret = dlgSelectDlg.exec(); //以模态方式显示对话框
    int typeID;
    float dataValue;
    int radioType; //选中的是高于、等于还是低于
    if(ret==QDialog::Accepted)
    {//OK按钮被按下
        typeID = dlgSelectDlg.m_iSelectIndex;
        dataValue = dlgSelectDlg.GetValue();
        radioType = dlgSelectDlg.m_iRadioID;
        ShowSpecialList(typeID, radioType, dataValue);
    }

}

