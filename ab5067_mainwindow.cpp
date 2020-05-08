/*
Arsh Bansal
3 May 2020
Revision History
*/

#include "ab5067_mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>

using namespace std;


MainWindow::MainWindow(QWidget *parent, Customer* custArray, int numrecs) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    customerData =  custArray;
    records = numrecs;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pinButton_clicked()
{
    QString stringPin = ui->textEdit->toPlainText();
    pin = stringPin.toInt();
    int i;

    for(i = 0; i < records; i++) {
        if(pin == (customerData+i)->Cust_pin()) {
            hide();
            optionWindow = new BankAtm(this, (customerData+i));
            optionWindow->show();
            break;
        }
    }
    if (i == records) {
    QMessageBox::about(this, "Incorrect Pin", "Your Pin was incorrect. Please Try Again");
    }
}




