#ifndef SELECTDIALOG_H
#define SELECTDIALOG_H

#include <QDialog>
#include <QButtonGroup>

namespace Ui {
class SelectDialog;
}

class SelectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectDialog(QWidget *parent = nullptr);
    ~SelectDialog();
    float GetValue();//获取lineEdit中的值
    int m_iSelectIndex; //当前选中的是哪个选项，0--身高；1--体重
    int m_iRadioID; //当前选中的是哪个，0--高于，1--等于，2--低于

private slots:

    void on_radioGreater_clicked();

    void on_radioEqual_clicked();

    void on_radioLower_clicked();

    void on_comboSpecialItem_currentTextChanged(const QString &arg1);

private:
    Ui::SelectDialog *ui;
     QButtonGroup * RadioGroup;
};

#endif // SELECTDIALOG_H
