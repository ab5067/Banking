/*
Arsh Bansal
3 May 2020
Revision History
*/

#include "ab5067_balancewindow.h"
#include "ui_balancewindow.h"


BalanceWindow::BalanceWindow(QWidget *parent, Customer* customerIn) :
    QDialog(parent),
    ui(new Ui::BalanceWindow)
{
    ui->setupUi(this);
    customer = customerIn;

    double checkingBalance = bank->displayBalance(true, customer);
    QString checkingString = QString::number(checkingBalance);

    ui->chekcingLabel->setText(checkingString);
    ui->savingsLabel->setText(QString::number(bank->displayBalance(false, customer)));

}

BalanceWindow::~BalanceWindow()
{
    delete ui;
}


void BalanceWindow::on_exitButton_clicked()
{
    this->close();
}
