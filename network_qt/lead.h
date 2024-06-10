#ifndef LEAD_H
#define LEAD_H

#include <QDialog>

namespace Ui {
class lead;
}

class lead : public QDialog
{
    Q_OBJECT

public:
    explicit lead(QWidget *parent = nullptr);
    ~lead();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::lead *ui;
};

#endif // LEAD_H
