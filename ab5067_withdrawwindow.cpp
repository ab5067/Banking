/*
Arsh Bansal
3 May 2020
Revision History
*/

#include "ab5067_withdrawwindow.h"
#include "ui_withdrawwindow.h"
#include <QMessageBox>
#include <fstream>

using namespace  std;

WithdrawWindow::WithdrawWindow(QWidget *parent,  Customer* customerIn) :
    QDialog(parent),
    ui(new Ui::WithdrawWindow)
{
    ui->setupUi(this);
    customer = customerIn;
}

WithdrawWindow::~WithdrawWindow()
{
    delete ui;
}


void WithdrawWindow::on_withdrawButton_clicked()
{
    int c;
    double withdrawalAmount;
    if(ui->checkingsWithdrawButton->isChecked()) {
        withdrawalAmount = ui->checkingWithdrawTextEdit->toPlainText().toDouble();
        c = bank.withdrawl(1, withdrawalAmount, customer);
    } else if (ui->savingsWithdrawButton->isChecked()) {
        withdrawalAmount = ui->savingsWithdrawTextEdit->toPlainText().toDouble();
        c = bank.withdrawl(2, withdrawalAmount, customer);
    } else {
         QMessageBox::about(this, "Error", "Please Select An Option");
    }

    if(c == 0 || c == 3) {
         QMessageBox::about(this, "Success", "Withdrawal Success");
    } else if(c == 1) {
         QMessageBox::about(this, "Overdraft", "Please Pay your Overdraft fee");
    } else if(c == 4) {
         QMessageBox::about(this, "Error", "Withdrawl amount has to be greater than 0");
    }
}

void WithdrawWindow::on_exitButton_clicked()
{
    extern Customer* custArray;

    ofstream custUpdate;
    custUpdate.open("/Users/arshbansal/bank.txt");// Path alteration required
    if (custUpdate.fail())
    {
        QMessageBox::about(this, "Error", "Error:404 Banking File not found");
    } else {

        custUpdate << 10 << endl << endl;

        for (int i = 0; i < 10; i++)
        {
            ChkId = custArray[i].getChkActId();
            ChkBal = custArray[i].getChkAcctBal();
            Overd_flg = custArray[i].getOverdraft_flg();
            SavId = custArray[i].getSavAcctId();
            SavBal = custArray[i].getSavAcctBal();
            SvIntrstRate = custArray[i].getSvIntrst();
            PIN_num = custArray[i].Cust_pin();

            custUpdate << setprecision(2) << setiosflags(ios::fixed | ios::showpoint);
            custUpdate << ChkId << " " << ChkBal << " " << Overd_flg << " " << SavId
                << " " << SavBal << " " << SvIntrstRate << " " << PIN_num << endl << endl;
        }

        custUpdate.close();
        QMessageBox::about(this, "Success", "Success");
    }

    this->close();
}
