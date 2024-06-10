#include "leadin.h"
#include "ui_leadin.h"

leadin::leadin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::leadin)
{
    ui->setupUi(this);
}

leadin::~leadin()
{
    delete ui;
}
