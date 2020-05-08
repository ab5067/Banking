/*
Arsh Bansal
3 May 2020
Revision History
*/

#include "ab5067_atm.h"

ATM::ATM()
{

}

int ATM::withdrawl(int selec, double withdrawalAmnt, Customer *customer) {
    if(withdrawalAmnt > 0 && withdrawalAmnt < 5000.0) {
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
