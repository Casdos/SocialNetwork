/********************************************************************************
** Form generated from reading UI file 'lead.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEAD_H
#define UI_LEAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lead
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox_2;
    QComboBox *comboBox;

    void setupUi(QDialog *lead)
    {
        if (lead->objectName().isEmpty())
            lead->setObjectName("lead");
        lead->resize(800, 600);
        pushButton = new QPushButton(lead);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(180, 430, 101, 28));
        pushButton_2 = new QPushButton(lead);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(430, 430, 101, 28));
        widget = new QWidget(lead);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(120, 90, 341, 211));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        comboBox_2 = new QComboBox(widget);
        comboBox_2->setObjectName("comboBox_2");

        gridLayout->addWidget(comboBox_2, 4, 1, 1, 1);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName("comboBox");

        gridLayout->addWidget(comboBox, 2, 1, 1, 1);


        retranslateUi(lead);

        QMetaObject::connectSlotsByName(lead);
    } // setupUi

    void retranslateUi(QDialog *lead)
    {
        lead->setWindowTitle(QCoreApplication::translate("lead", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("lead", "\345\257\274\345\205\245", nullptr));
        pushButton_2->setText(QCoreApplication::translate("lead", "\351\200\200\345\207\272", nullptr));
        label_2->setText(QCoreApplication::translate("lead", "\345\271\264\351\276\204", nullptr));
        label->setText(QCoreApplication::translate("lead", "\345\247\223\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("lead", "\350\201\214\344\270\232", nullptr));
        label_4->setText(QCoreApplication::translate("lead", "\346\200\247\345\210\253", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lead: public Ui_lead {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEAD_H
