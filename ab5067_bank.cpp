/*
Arsh Bansal
3 May 2020
Revision History
*/

#include "ab5067_bank.h"
#include <QMessageBox>

Bank::Bank()
{

}

double Bank::displayBalance(bool f, Customer *customer) {

    if(f == true) {
        return customer->getChkAcctBal();
    } else {
        return customer->getSavAcctBal();
    }

};

void Bank::transferFunds(int transdirect, double transAmnt, Customer *customer) {
    if(transdirect == 1) {
        double a = customer->getChkAcctBal() - transAmnt;
        customer->setChkAcctBal(a);
        double b = customer->getSavAcctBal() + transAmnt;
        customer->setSavAcctBal(b);
    } else if(transdirect == 2) {
        double a = customer->getSavAcctBal() - transAmnt;
        customer->setSavAcctBal(a);
        double b = customer->getChkAcctBal() + transAmnt;
        customer->setChkAcctBal(b);
    }
}

int Bank::withdrawl(int selec, double withdrawalAmnt, Customer *customer) {
    if(withdrawalAmnt > 0) {
        if(selec == 1) {
            if(customer->getOverdraft_flg() == 'N') {
                double a = customer->getChkAcctBal() - withdrawalAmnt;
                customer->setChkAcctBal(a);
                return 0;
            } else if(customer->getOverdraft_flg() == 'Y') {
                return 1;
            }
        } else if (selec == 2) {
            double a = customer->getSavAcctBal() - withdrawalAmnt;
            customer->setSavAcctBal(a);
            return 3;
        }
    } else {
        return 4;
    }
}

void Bank::depos(int selec, double depAmnt, Customer *customer) {

    if(selec == 1) {
        double a = customer->getChkAcctBal() + depAmnt;
        customer->setChkAcctBal(a);
    } else if(selec == 2) {
        double a = customer->getSavAcctBal() + depAmnt;
        customer->setSavAcctBal(a);
    }
};
