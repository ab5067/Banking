/*
Arsh Bansal
3 May 2020
Revision History
*/

#ifndef DEPOSITWINDOW_H
#define DEPOSITWINDOW_H

#include <QDialog>
#include "ab5067_customer.h"
#include "ab5067_bank.h"

namespace Ui {
class DepositWindow;
}

class DepositWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DepositWindow(QWidget *parent = nullptr, Customer* customerIn = nullptr);
    ~DepositWindow();

private slots:
    void on_depositButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::DepositWindow *ui;
    Customer* customer;
    Bank* bank;


    int    ChkId;
    double ChkBal;
    char   Overd_flg;
    int    SavId;
    double SavBal;
    double SvIntrstRate;
    int    PIN_num;
};

#endif // DEPOSITWINDOW_H
