/*
Arsh Bansal
3 May 2020
Revision History
*/

#ifndef ATMWITHDRAW_H
#define ATMWITHDRAW_H

#include <QDialog>
#include "ab5067_customer.h"
#include "ui_atmwithdraw.h"
#include "ab5067_atm.h"
#include "ab5067_bank.h"

namespace Ui {
class ATMWithdraw;
}

class ATMWithdraw : public QDialog
{
    Q_OBJECT

public:
    explicit ATMWithdraw(QWidget *parent = nullptr);
    explicit ATMWithdraw(QWidget *parent = nullptr, Customer* customerIn = nullptr):
        QDialog(parent),
        ui(new Ui::ATMWithdraw) {
        p = &atm;
        customer = customerIn;
        ui->setupUi(this);

    };
    ~ATMWithdraw();

private slots:
    void on_atmWithdrawButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::ATMWithdraw *ui;
    Customer* customer;
    Bank *p;
    ATM atm;

    int    ChkId;
    double ChkBal;
    char   Overd_flg;
    int    SavId;
    double SavBal;
    double SvIntrstRate;
    int    PIN_num;
};

#endif // ATMWITHDRAW_H
