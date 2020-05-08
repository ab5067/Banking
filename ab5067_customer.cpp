/*
Arsh Bansal
3 May 2020
Revision History
*/

#include "ab5067_customer.h"
#include <iostream>

using namespace std;

Customer::Customer()
{

}
void Customer::setChkActId(int s) {CheckingAcctNum = s;};

int Customer::getChkActId() {return CheckingAcctNum;};

void Customer::setChkAcctBal(double s) {CheckingAcctBal = s;};

double Customer::getChkAcctBal() {return CheckingAcctBal;};


//Setters and Getter for Overdraft
void Customer::setOverdraft_flg(char s) {Is_Overdraft = s;};

char Customer::getOverdraft_flg() {return Is_Overdraft;};


//Setters and Getter for Savings Accounts
void Customer::setSavAcctId(int s) {SavingAcctNum = s;};

int Customer::getSavAcctId() {return SavingAcctNum;};

void Customer::setSavAcctBal(double s) {SavingAcctBalance = s;};

double Customer::getSavAcctBal() {return SavingAcctBalance;};


//Setters and Getter for Saving Intrest
void Customer::setSvIntrst(double s) {Int_Rate = s;};

double Customer::getSvIntrst() {return Int_Rate;};


//Setters and Getter for PIN
void Customer::setPIN(int s) {PIN = s;};

int Customer::Cust_pin() {return PIN;};
