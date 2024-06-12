#include "lead.h"
#include "ui_lead.h"

lead::lead(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::lead)
{
    this->setStyleSheet("QWidget { background-color: #E7DAD2; }");
    ui->setupUi(this);
    ui->comboBox->addItem("male");
    ui->comboBox->addItem("female");
    ui->comboBox_2->addItem("teacher");
    ui->comboBox_2->addItem("doctor");
    ui->comboBox_2->addItem("nurse");
    ui->comboBox_2->addItem("policeman");
    ui->comboBox_2->addItem("fireman");
}

lead::~lead()
{
    delete ui;
}



void lead::on_pushButton_2_clicked()
{
    close();
}


void lead::on_comboBox_activated(int index)
{

}


void lead::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    int  age = ui->lineEdit_2->text().toInt();
    QString sex=ui->comboBox->currentText();
    QString job=ui->comboBox_2->currentText();
    QString filePath="C:/Users/0/Desktop/SocialNetwork/network_qt/data.csv";
    QFile file(filePath);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qWarning() << "Cannot open file for appending";
    }
    QTextStream out(&file);
    out <<name<<","<<age<<","<<sex<<","<<job;
    file.close();

    QMessageBox::information(this, "Success", "导入完成", QMessageBox::Ok);

}

