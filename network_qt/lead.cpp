#include "lead.h"
#include "ui_lead.h"

lead::lead(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::lead)
{
    ui->setupUi(this);
}

lead::~lead()
{
    delete ui;
}



void lead::on_pushButton_2_clicked()
{
    close();
}

