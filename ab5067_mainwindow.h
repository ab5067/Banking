/*
Arsh Bansal
3 May 2020
Revision History
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include "ab5067_customer.h"
#include "ab5067_bankatm.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, Customer* custArray = nullptr, int numrecs = 0);
    ~MainWindow();
     BankAtm* optionWindow;
     Customer* customerData ;

public slots:
    void on_pinButton_clicked();

private:
    Ui::MainWindow *ui;
    int pin;
    int records;

};

#endif // MAINWINDOW_H
