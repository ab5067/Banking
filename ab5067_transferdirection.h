#ifndef TRANSFERDIRECTION_H
/*
Arsh Bansal
3 May 2020
Revision History
*/

#define TRANSFERDIRECTION_H

#include <QDialog>
#include "ab5067_customer.h"
#include "ab5067_bank.h"

namespace Ui {
class TransferDirection;
}

class TransferDirection : public QDialog
{
    Q_OBJECT

public:
    explicit TransferDirection(QWidget *parent = nullptr, Customer* customerIn = nullptr);
    ~TransferDirection();

private slots:
    void on_transferButton_clicked();


    void on_exitButton_clicked();

private:
    Ui::TransferDirection *ui;
    Customer* customer;
    Bank* bank;

    int    ChkId;
    double ChkBal;
    char   Overd_flg;
    int    SavId;
    double SavBal;
    double SvIntrstRate;
    int    PIN_num;
};

#endif // TRANSFERDIRECTION_H
