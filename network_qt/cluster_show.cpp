#include "cluster_show.h"
#include "ui_cluster_show.h"

Cluster_show::Cluster_show(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Cluster_show)
{
    std::vector<Person> people;
    std::string filepath = "C:/Users/0/Desktop/SocialNetwork/network_qt/data.csv";
    Load(people, filepath);
    int vertices = people.size();
    Graph graph(vertices);
    graph.autoGenerateEdge(people);
    int** matrix = graph.dispaly01Matrix();
    DisjointSetUnion dsu(vertices);
    dsu.buildConnectionsFromMatrix(matrix, vertices);
    std::vector<int> RootPositionInSet = dsu.displaySets();
    int maxsize=0;
    for (int i : RootPositionInSet)
    {
        std::vector<int> elements = dsu.getElementsInSet(i);
        if(elements.size()>maxsize)
            maxsize=elements.size();
    }
    QTableWidget *tableWidget = new QTableWidget(maxsize,RootPositionInSet.size(),this);
    int colorset=0;
    for (int column = 0; column < RootPositionInSet.size(); ++column)//每一列
    {
        for (int row = 0; row < maxsize; ++row)//每行
        {
            std::vector<int> elements = dsu.getElementsInSet(RootPositionInSet[column]);
            if(row<elements.size())
            {
                QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(people[elements[row]].name));
                switch(colorset)
                {
                case 0:item->setBackground(Qt::green);
                    break;
                case 1:item->setBackground(Qt::red);
                    break;
                case 2:item->setBackground(Qt::blue);
                    break;
                case 3:item->setBackground(Qt::yellow);
                    break;
                }

                tableWidget->setItem(row, column, item);
            }
            else
                break;

        }
        colorset++;
        colorset%=4;
    }

    for (int i = 0; i <RootPositionInSet.size(); i++) {
        tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(QString::number(i)));
    }
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(tableWidget);
    setLayout(layout);
     ui->setupUi(this);
}

Cluster_show::~Cluster_show()
{
    delete ui;
}
