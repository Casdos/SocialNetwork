/********************************************************************************
** Form generated from reading UI file 'checkwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKWIDGET_H
#define UI_CHECKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Checkwidget
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *Checkwidget)
    {
        if (Checkwidget->objectName().isEmpty())
            Checkwidget->setObjectName("Checkwidget");
        Checkwidget->resize(800, 600);
        verticalLayoutWidget_2 = new QWidget(Checkwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(350, 200, 271, 151));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(verticalLayoutWidget_2);
        comboBox->setObjectName("comboBox");

        verticalLayout_2->addWidget(comboBox);

        comboBox_2 = new QComboBox(verticalLayoutWidget_2);
        comboBox_2->setObjectName("comboBox_2");

        verticalLayout_2->addWidget(comboBox_2);

        verticalLayoutWidget = new QWidget(Checkwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(100, 200, 211, 151));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(Checkwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(330, 480, 93, 28));

        retranslateUi(Checkwidget);

        QMetaObject::connectSlotsByName(Checkwidget);
    } // setupUi

    void retranslateUi(QDialog *Checkwidget)
    {
        Checkwidget->setWindowTitle(QCoreApplication::translate("Checkwidget", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("Checkwidget", "<html><head/><body><p><span style=\" font-size:16pt;\">\344\272\272\347\211\251\345\247\223\345\220\2151</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Checkwidget", "<html><head/><body><p><span style=\" font-size:16pt;\">\344\272\272\347\211\251\345\247\223\345\220\2152</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("Checkwidget", "\346\243\200\346\237\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Checkwidget: public Ui_Checkwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKWIDGET_H
