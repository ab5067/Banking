/*
Arsh Bansal
3 May 2020
Revision History
*/

#ifndef ATM_H
#define ATM_H

#include "ab5067_bank.h"

class ATM : public Bank
{
public:
    ATM();
    int withdrawl(int selec, double withdrawalAmnt, Customer *customer);
};

#endif // ATM_H
