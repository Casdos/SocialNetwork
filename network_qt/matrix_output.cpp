#include "matrix_output.h"
#include "ui_matrix_output.h"
#include <QTableWidget>
#include <QVBoxLayout>

matrix_output::matrix_output(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::matrix_output)
{

    std::vector<Person> people;
    std::string filepath = "C:/Users/0/Desktop/SocialNetwork/network_qt/data.csv";
    Load(people, filepath);
    int vertices = people.size();
    Graph graph(vertices);
    graph.autoGenerateEdge(people);
    int** matrix = graph.dispaly01Matrix();

    // Cluster peoples;
    // peoples.load("C:/Users/0/Desktop/SocialNetwork/network_qt/data.csv");
    // std::vector<Cluster> cluster = peoples.hierarchicalClustering(peoples);
    // std::vector<std::vector<int>> matrix = generateMatrix01(peoples.peoples.size(), cluster);

    ui->setupUi(this);
    QTableWidget *tableWidget = new QTableWidget(vertices,vertices,this);
    for (int row = 0; row < vertices; ++row) {
        for (int column = 0; column < vertices; ++column) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(matrix[row][column]));
            tableWidget->setItem(row, column, item);
        }
    }

    for (int i = 0; i <vertices; i++) {
        tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(QString::fromStdString(people[i].name)));
        tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(QString::fromStdString(people[i].name)));
    }
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(tableWidget);
    setLayout(layout);
}

matrix_output::~matrix_output()
{
    delete ui;
}
