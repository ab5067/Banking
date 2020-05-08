#include "ab5067_mainwindow.h"
# include <iostream>
# include <fstream>
/*
Arsh Bansal
3 May 2020
Revision History
*/

# include <iomanip>
# include "ab5067_customer.h"
# include "ab5067_depositwindow.h"


#include <QApplication>

using namespace std;

Customer* custArray = new Customer[50];

int main(int argc, char *argv[])
{

    ifstream custFile;
    /* The file path of bank.txt has to be changed according to the
     * computer it's being used on. Other files that require a
     * similar edit are mentioned below
     * ab5067_atmwithdraw.cpp
     * ab5067_depositwindow.cpp
     * ab5067_transferdirection.cpp
     * ab5067_withdrawwindow.cpp
     */
    custFile.open("/Users/arshbansal/bank.txt");
    if (custFile.fail())
    {
        cout << "Unable to Access Bank Records" << endl;
        exit(1);
    };

    int numrecs = 0;
    custFile >> numrecs;   

    int    ChkId;
    double ChkBal;
    char   Overd_flg;
    int    SavId;
    double SavBal;
    double SvIntrstRate;
    int    PIN_num;

    int i = 0;

    while (custFile >> ChkId >> ChkBal >> Overd_flg >> SavId
        >> SavBal >> SvIntrstRate >> PIN_num)
    {
        custArray[i].setChkActId(ChkId);
        custArray[i].setChkAcctBal(ChkBal);
        custArray[i].setOverdraft_flg(Overd_flg);
        custArray[i].setSavAcctId(SavId);
        custArray[i].setSavAcctBal(SavBal);
        custArray[i].setSvIntrst(SvIntrstRate);
        custArray[i].setPIN(PIN_num);
        i++;
    }//endwhile

    custFile.close();

    QApplication a(argc, argv);
    MainWindow w(nullptr, custArray, numrecs);
    w.show();
    return a.exec();

}
