#ifndef STATESMATRIX_OUTPUT_H
#define STATESMATRIX_OUTPUT_H

#include <QDialog>
#include"Graph.h"
#include"DisjointSetUnion.h"
#include <QTableWidget>
#include <QVBoxLayout>
void Load(std::vector<Person> &people, std::string filepath);
namespace Ui {
class Statesmatrix_output;
}

class Statesmatrix_output : public QDialog
{
    Q_OBJECT

public:
    explicit Statesmatrix_output(QWidget *parent = nullptr);
    ~Statesmatrix_output();

private:
    Ui::Statesmatrix_output *ui;
};

#endif // STATESMATRIX_OUTPUT_H
