#ifndef MATRIX_OUTPUT_H
#define MATRIX_OUTPUT_H

#include"cluster.h"
#include <QDialog>
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
