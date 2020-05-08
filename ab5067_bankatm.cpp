/*
Arsh Bansal
3 May 2020
Revision History
*/

#include "ab5067_bankatm.h"
#include "ui_bankatm.h"

BankAtm::BankAtm(QWidget *parent, Customer *customerin) :
    QDialog(parent),
    ui(new Ui::BankAtm)
{
    ui->setupUi(this);
    customer = customerin;

}

BankAtm::~BankAtm()
{
    delete ui;
}


void BankAtm::on_bankButton_clicked()
{
    hide();
    bankWindow = new BankWindow(this, customer);
    bankWindow->show();
}

void BankAtm::on_ATMButton_clicked()
{
    hide();
    atmWindow = new ATMWindow(this, customer);
    atmWindow->show();
}
