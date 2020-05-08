#ifndef BANKWINDOW_H
#define BANKWINDOW_H

/*
Arsh Bansal
3 May 2020
Revision History
*/

#include <QDialog>
#include "ab5067_customer.h"
#include "ab5067_balancewindow.h"
#include "ab5067_transferdirection.h"
#include "ab5067_withdrawwindow.h"
#include "ab5067_depositwindow.h"

namespace Ui {
class BankWindow;
}

class BankWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BankWindow(QWidget *parent = nullptr, Customer* customerIn = nullptr);
    ~BankWindow();

private slots:
    void on_balanceButton_clicked();

    void on_transferButton_clicked();

    void on_withdrawButton_clicked();

    void on_depositButton_clicked();

private:
    Ui::BankWindow *ui;
    Customer* customer;
    BalanceWindow* balanceWindow;
    TransferDirection* transferWindow;
    WithdrawWindow* withdrawWindow;
    DepositWindow* depositWindow;

};

#endif // BANKWINDOW_H
