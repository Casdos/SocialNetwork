#ifndef CLUSTER_SHOW_H
#define CLUSTER_SHOW_H
#include <QListWidget>
#include <QDialog>
#include <QHBoxLayout>
#include"cluster.h"
#include<QTableWidget>
namespace Ui {
class Cluster_show;
}

class Cluster_show : public QDialog
{
    Q_OBJECT

public:
    explicit Cluster_show(QWidget *parent = nullptr);
    ~Cluster_show();

private:
    Ui::Cluster_show *ui;
};

#endif // CLUSTER_SHOW_H
