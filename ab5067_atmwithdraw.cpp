/*
Arsh Bansal
3 May 2020
Revision History
*/

#include "ab5067_atmwithdraw.h"
#include "QMessageBox"
#include <fstream>

using namespace std;

ATMWithdraw::ATMWithdraw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ATMWithdraw)
{
    ui->setupUi(this);

}

ATMWithdraw::~ATMWithdraw()
{
    delete ui;
}

void ATMWithdraw::on_atmWithdrawButton_clicked()
{
    int c;
    double withdrawalAmount;
    if(ui->atmCheckingsWithdrawButton->isChecked()) {
        withdrawalAmount = ui->atmCheckingsTextEdit->toPlainText().toDouble();
        c = p->withdrawl(1, withdrawalAmount, customer);
    } else if (ui->atmSavingsWithdrawButton->isChecked()) {
        withdrawalAmount = ui->atmSavingsTextEdit->toPlainText().toDouble();
        c = p->withdrawl(2, withdrawalAmount, customer);
    } else {
         QMessageBox::about(this, "Error", "Please Select An Option");
    }

    if(c == 0 || c == 3) {
         QMessageBox::about(this, "Success", "Withdrawal Success");
    } else if(c == 1) {
         QMessageBox::about(this, "Overdraft", "Please Pay your Overdraft fee");
    } else if(c == 4) {
         QMessageBox::about(this, "Error", "Withdrawl amount has to be less than 5000");
    }
}

void ATMWithdraw::on_exitButton_clicked()
{
    extern Customer* custArray;

    ofstream custUpdate;
    custUpdate.open("/Users/arshbansal/bank.txt"); // Path alteration required
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
