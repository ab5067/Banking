/*
Arsh Bansal
3 May 2020
Revision History
*/

#ifndef BANKATM_H
#define BANKATM_H

#include <QDialog>
#include "ab5067_bankwindow.h"
#include "ab5067_customer.h"
#include "ab5067_atmwindow.h"


namespace Ui {
class BankAtm;
}

class BankAtm : public QDialog
{
    Q_OBJECT

public:
    explicit BankAtm(QWidget *parent = nullptr, Customer* customerin = nullptr);
    ~BankAtm();

private slots:

    void on_bankButton_clicked();

    void on_ATMButton_clicked();

private:
    Ui::BankAtm *ui;
    BankWindow *bankWindow;
    Customer* customer;
    ATMWindow* atmWindow;

};

#endif // BANKATM_H
