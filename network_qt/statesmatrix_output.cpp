#include "statesmatrix_output.h"
#include "ui_statesmatrix_output.h"

Statesmatrix_output::Statesmatrix_output(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Statesmatrix_output)
{
    this->setStyleSheet("QWidget { background-color: #E7DAD2; }");
    std::vector<Person> people;
    std::string filepath = "C:/Users/0/Desktop/SocialNetwork/network_qt/data.csv";
    Load(people, filepath);
    int vertices = people.size();
    Graph graph(vertices);
    graph.autoGenerateEdge(people);
    int** matrix = graph.dispaly01Matrix();
    DisjointSetUnion dsu(vertices);
    dsu.buildConnectionsFromMatrix(matrix, vertices);
    int** StateMatrix = new int* [vertices];
    for (int i = 0; i < vertices; ++i) {
        StateMatrix[i] = new int[vertices](); // 为每一行分配内存并初始化为0
    }
    for(int i=0;i<vertices;++i){
        for(int j=i;j<vertices;++j){
            if(graph.check(i,j,dsu)){
                StateMatrix[i][j] = 1;
                StateMatrix[j][i] = 1;
            }
        }
    }

    // Cluster peoples;
    // peoples.load("C:/Users/0/Desktop/SocialNetwork/network_qt/data.csv");
    // std::vector<Cluster> cluster = peoples.hierarchicalClustering(peoples);
    // std::vector<std::vector<int>> matrix = generateMatrix01(peoples.peoples.size(), cluster);

    ui->setupUi(this);
    QTableWidget *tableWidget = new QTableWidget(vertices,vertices,this);
    for (int row = 0; row < vertices; ++row) {
        for (int column = 0; column < vertices; ++column) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(StateMatrix[row][column]));
            tableWidget->setItem(row, column, item);
        }
    }

    for (int i = 0; i <vertices; i++) {
        tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(QString::fromStdString(people[i].name)));
        tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(QString::fromStdString(people[i].name)));
    }
    tableWidget->setStyleSheet( "QHeaderView::section {"
                               "    background-color: #E7DAD2; /* 表头背景颜色 */"
                               "}"
                               );
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(tableWidget);
    setLayout(layout);
}

Statesmatrix_output::~Statesmatrix_output()
{
    delete ui;
}
