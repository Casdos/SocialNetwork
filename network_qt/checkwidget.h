#ifndef CHECKWIDGET_H
#define CHECKWIDGET_H

#include <QDialog>
#include"Graph.h"
#include"DisjointSetUnion.h"
#include<QMessageBox>
void Load(std::vector<Person> &people, std::string filepath);
namespace Ui {
class Checkwidget;
}

class Checkwidget : public QDialog
{
    Q_OBJECT

public:
    explicit Checkwidget(QWidget *parent = nullptr);
    ~Checkwidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Checkwidget *ui;
};

#endif // CHECKWIDGET_H
