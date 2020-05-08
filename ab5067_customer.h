/*
Arsh Bansal
3 May 2020
Revision History
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H


class Customer
{
public:
    Customer();

    void setChkActId(int s);
    int getChkActId();
    void setChkAcctBal(double s);
    double getChkAcctBal();

    void setOverdraft_flg(char s);
    char getOverdraft_flg();

    void setSavAcctId(int s);
    int getSavAcctId();
    void setSavAcctBal(double s);
    double getSavAcctBal();

    void setSvIntrst(double s);
    double getSvIntrst();

    void setPIN(int s);
    int Cust_pin();


private:
    int CheckingAcctNum;
    double CheckingAcctBal;
    char Is_Overdraft;
    int SavingAcctNum;
    double SavingAcctBalance;
    double Int_Rate;
    int PIN;;
};

#endif // CUSTOMER_H
