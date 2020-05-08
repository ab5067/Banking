/*
Arsh Bansal
3 May 2020
Revision History
*/

#ifndef BALANCEWINDOW_H
#define BALANCEWINDOW_H

#include <QDialog>
#include "ab5067_customer.h"
#include "ab5067_bank.h"
#include <iostream>

namespace Ui {
class BalanceWindow;
}

class BalanceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BalanceWindow(QWidget *parent = nullptr, Customer* customerIn = nullptr);
    ~BalanceWindow();

private slots:


    void on_exitButton_clicked();

private:
    Ui::BalanceWindow *ui;
    Customer* customer;
    Bank* bank;
};

#endif // BALANCEWINDOW_H
