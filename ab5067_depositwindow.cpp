/*
Arsh Bansal
3 May 2020
Revision History
*/

#include "ab5067_depositwindow.h"
#include "ui_depositwindow.h"
#include <QMessageBox>
#include <fstream>

using namespace std;

DepositWindow::DepositWindow(QWidget *parent, Customer* customerIn) :
    QDialog(parent),
    ui(new Ui::DepositWindow)
{
    ui->setupUi(this);
    customer = customerIn;

}

DepositWindow::~DepositWindow()
{
    delete ui;
}

void DepositWindow::on_depositButton_clicked()
{
    double depositAmount;
    if(ui->checkingsDepositButton->isChecked()) {
        depositAmount = ui->checkingsTextEdit->toPlainText().toDouble();
        bank->depos(1, depositAmount, customer);
         QMessageBox::about(this, "Success", "Deposit Success");
    } else if (ui->savingsDepositButton->isChecked()) {
        depositAmount = ui->savingsTextEdit->toPlainText().toDouble();
        bank->depos(2, depositAmount, customer);
        QMessageBox::about(this, "Success", "Deposit Success");
    } else {
         QMessageBox::about(this, "Error", "Please Select An Option");
    }
}


void DepositWindow::on_exitButton_clicked()
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
