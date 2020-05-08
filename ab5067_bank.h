/*
Arsh Bansal
3 May 2020
Revision History
*/

#ifndef BANK_H
#define BANK_H
#include "ab5067_customer.h"

class Bank
{
public:
    Bank();
    void setpin();
    int getpin();

    char AskforAnotherTransaction();

    double displayBalance(bool f, Customer *customer);

    void depos(int selec, double depAmnt, Customer *customer);
    virtual int withdrawl(int selec, double withdrawalAmnt, Customer *customer);
    void transferFunds(int transdirect, double transAmnt, Customer *customer);

private:
    int PIN_Numb;
    int Trans_type;
    double Trans_AMNT;
    int Trans_Direc;
    int accnt;
    char another;

};

#endif // BANK_H
