/*
Arsh Bansal
3 May 2020
Revision History
*/

#ifndef WITHDRAWWINDOW_H
#define WITHDRAWWINDOW_H

#include <QDialog>
#include "ab5067_customer.h"
#include "ab5067_bank.h"


namespace Ui {
class WithdrawWindow;
}

class WithdrawWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WithdrawWindow(QWidget *parent = nullptr,  Customer* customerIn = nullptr);
    ~WithdrawWindow();

private slots:


    void on_withdrawButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::WithdrawWindow *ui;
    Customer* customer;
    Bank bank;

    int    ChkId;
    double ChkBal;
    char   Overd_flg;
    int    SavId;
    double SavBal;
    double SvIntrstRate;
    int    PIN_num;
};

#endif // WITHDRAWWINDOW_H
