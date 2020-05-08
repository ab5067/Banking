/*
Arsh Bansal
3 May 2020
Revision History
*/

#include "ab5067_transferdirection.h"
#include "ui_transferdirection.h"
#include <QMessageBox>
#include <fstream>

using namespace std;

TransferDirection::TransferDirection(QWidget *parent,  Customer* customerIn) :
    QDialog(parent),
    ui(new Ui::TransferDirection)
{
    ui->setupUi(this);
    customer = customerIn;
}

TransferDirection::~TransferDirection()
{
    delete ui;
}

void TransferDirection::on_transferButton_clicked()
{
    if(ui->ctosButton->isChecked()){
        double amount = ui->ctosTextEdit->toPlainText().toDouble();
        bank->transferFunds(1, amount, customer);
        QMessageBox::about(this, "Amount Transferred", "Success");

    } else if(ui->stocButton->isChecked()) {
        double amount = ui->stocTextEdit->toPlainText().toDouble();
        bank->transferFunds(2, amount, customer);
        QMessageBox::about(this, "Amount Transferred", "Success");
    } else {
        QMessageBox::about(this, "Error", "Please Select An Option");
    }
}

void TransferDirection::on_exitButton_clicked()
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
