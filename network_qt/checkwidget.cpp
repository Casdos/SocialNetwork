#include "checkwidget.h"
#include "ui_checkwidget.h"

Checkwidget::Checkwidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Checkwidget)
{
    this->setStyleSheet("QWidget { background-color: #E7DAD2; }");
    ui->setupUi(this);
    std::vector<Person> people;
    std::string filepath = "C:/Users/0/Desktop/SocialNetwork/network_qt/data.csv";
    Load(people, filepath);
    for(Person i:people)
    {
        ui->comboBox->addItem(QString::fromStdString(i.name));
        ui->comboBox_2->addItem(QString::fromStdString(i.name));
    }
}

Checkwidget::~Checkwidget()
{
    delete ui;
}

void Checkwidget::on_pushButton_clicked()
{
    std::vector<Person> people;
    std::string filepath = "C:/Users/0/Desktop/SocialNetwork/network_qt/data.csv";
    Load(people, filepath);
    int vertices = people.size();
    Graph graph(vertices);
    graph.autoGenerateEdge(people);
    int** matrix = graph.dispaly01Matrix();
    DisjointSetUnion dsu(vertices);
    dsu.buildConnectionsFromMatrix(matrix, vertices);//ui->comboBox_2->currentIndex()
    if(graph.check(people[ui->comboBox->currentIndex()].name,people[ui->comboBox_2->currentIndex()].name,people,dsu))
    {
        QMessageBox::information(this, "Success", "可互相分享状态", QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, "Fail", "不可互相分享状态", QMessageBox::No);
    }
}

