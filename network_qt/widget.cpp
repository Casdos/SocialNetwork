#include "widget.h"
#include "ui_widget.h"
#include"lead.h"
#include"matrix_output.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()//导入
{
    lead leadin;
    leadin.exec();
}


void Widget::on_pushButton_3_clicked()//01矩阵
{
    matrix_output matrix_outputshow;
    matrix_outputshow.exec();
}

void Widget::on_pushButton_4_clicked()//可视化图
{
    Cluster_show cluster_show;
    cluster_show.exec();
}


void Widget::on_pushButton_clicked()
{
    Checkwidget  checkwidget;
    checkwidget.exec();
}


