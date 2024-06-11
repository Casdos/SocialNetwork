#ifndef LEAD_H
#define LEAD_H

#include <QDialog>
#include<QString>
#include<qmessagebox.h>
#include<QFile>
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

    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

private:
    Ui::lead *ui;
};

#endif // LEAD_H
