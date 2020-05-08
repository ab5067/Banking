/*
Arsh Bansal
3 May 2020
Revision History
*/

#include "ab5067_bankwindow.h"
#include "ui_bankwindow.h"

BankWindow::BankWindow(QWidget *parent, Customer* customerIn) :
    QDialog(parent),
    ui(new Ui::BankWindow)
{
    ui->setupUi(this);
    customer = customerIn;

}

BankWindow::~BankWindow()
{
    delete ui;
}

void BankWindow::on_balanceButton_clicked()
{
    hide();
    balanceWindow = new BalanceWindow(this, customer);
    balanceWindow->show();
}

void BankWindow::on_transferButton_clicked()
{
    hide();
    transferWindow = new TransferDirection(this, customer);
    transferWindow->show();
}

void BankWindow::on_withdrawButton_clicked()
{
    hide();
    withdrawWindow= new WithdrawWindow(this, customer);
    withdrawWindow->show();
}

void BankWindow::on_depositButton_clicked()
{
    hide();
    depositWindow = new DepositWindow(this, customer);
    depositWindow->show();
}



