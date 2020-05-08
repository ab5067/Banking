/*
Arsh Bansal
3 May 2020
Revision History
*/

#ifndef ATMWINDOW_H
#define ATMWINDOW_H

#include <QDialog>
#include "ab5067_customer.h"
#include "ab5067_atmwithdraw.h"
#include "ab5067_depositwindow.h"
#include "ab5067_balancewindow.h"

namespace Ui {
class ATMWindow;
}

class ATMWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ATMWindow(QWidget *parent = nullptr, Customer* customerIn = nullptr);
    ~ATMWindow();

private slots:
    void on_balanceButton_clicked();

    void on_depositButton_clicked();

    void on_withdrawButton_clicked();

private:
    Ui::ATMWindow *ui;
    Customer* customer;
    BalanceWindow* balanceWindow;
    ATMWithdraw* withdrawWindow;
    DepositWindow* depositWindow;

};

#endif // ATMWINDOW_H
