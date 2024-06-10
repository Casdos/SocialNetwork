#include "matrix_output.h"
#include "ui_matrix_output.h"
#include <QTableWidget>
#include <QVBoxLayout>

matrix_output::matrix_output(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::matrix_output)
{
    // std::vector<Person> people = {};
    // loadfile(people,"data.csv");
    // std::vector<Cluster> cluster = hierarchicalClustering(people);
    // std::vector<std::vector<int>> matrix = generateMatrix01(PeopleNum(people), cluster);


    Cluster peoples;
    peoples.load("C:/Users/0/Desktop/SocialNetwork/network_qt/data.csv");
    std::vector<Cluster> cluster = peoples.hierarchicalClustering(peoples);
    std::vector<std::vector<int>> matrix = generateMatrix01(peoples.peoples.size(), cluster);

    ui->setupUi(this);
    QTableWidget *tableWidget = new QTableWidget(peoples.peoples.size(),peoples.peoples.size(),this);
    for (int row = 0; row < peoples.peoples.size(); ++row) {
        for (int column = 0; column < peoples.peoples.size(); ++column) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(matrix[row][column]));
            tableWidget->setItem(row, column, item);
        }
    }

    // 设置表格的行标题和列标题
    for (int i = 0; i <peoples.peoples.size(); i++) {
        tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(QString::fromStdString(peoples.peoples[i].name)));
        tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(QString::fromStdString(peoples.peoples[i].name)));
    }
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(tableWidget);
    setLayout(layout);
}

matrix_output::~matrix_output()
{
    delete ui;
}
