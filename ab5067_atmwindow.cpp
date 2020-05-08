/*
Arsh Bansal
3 May 2020
Revision History
*/

#include "ab5067_atmwindow.h"
#include "ui_atmwindow.h"

ATMWindow::ATMWindow(QWidget *parent, Customer* customerIn) :
    QDialog(parent),
    ui(new Ui::ATMWindow)
{
    ui->setupUi(this);
    customer = customerIn;
    //exitl = exit;
}

ATMWindow::~ATMWindow()
{
    delete ui;
}

void ATMWindow::on_balanceButton_clicked()
{
    hide();
    balanceWindow = new BalanceWindow(this, customer);
    balanceWindow->show();
}

void ATMWindow::on_depositButton_clicked()
{
    hide();
    depositWindow = new DepositWindow(this, customer);
    depositWindow->show();
}

void ATMWindow::on_withdrawButton_clicked()
{
    hide();
    withdrawWindow = new ATMWithdraw(this, customer);
    withdrawWindow->show();
}
