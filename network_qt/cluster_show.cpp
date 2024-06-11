#include "cluster_show.h"
#include "ui_cluster_show.h"

Cluster_show::Cluster_show(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Cluster_show)
{
    Cluster peoples;
    peoples.load("C:/Users/0/Desktop/SocialNetwork/network_qt/data.csv");
    std::vector<Cluster> clusters = peoples.hierarchicalClustering(peoples);

    int maxsize=0;
    for(int i=0;i<clusters.size();i++)
    {
        if(clusters[i].peoples.size()>maxsize)
            maxsize=clusters[i].peoples.size();
    }

    QTableWidget *tableWidget = new QTableWidget(maxsize,clusters.size(),this);
    int colorset=0;
    for (int column = 0; column < clusters.size(); ++column)
    {
        for (int row = 0; row < maxsize; ++row)
        {
            if(row<clusters[column].peoples.size())
            {
                QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(clusters[column].peoples[row].name));
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


    for (int i = 0; i <clusters.size(); i++) {
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
