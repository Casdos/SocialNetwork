#ifndef MATRIX_OUTPUT_H
#define MATRIX_OUTPUT_H


#include <QDialog>
#include"Graph.h"
#include"DisjointSetUnion.h"
#include <QTableWidget>
#include <QVBoxLayout>
void Load(std::vector<Person> &people, std::string filepath);

namespace Ui {
class matrix_output;
}

class matrix_output : public QDialog
{
    Q_OBJECT

public:
    explicit matrix_output(QWidget *parent = nullptr);
    ~matrix_output();

private:
    Ui::matrix_output *ui;
};

#endif // MATRIX_OUTPUT_H
