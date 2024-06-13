/********************************************************************************
** Form generated from reading UI file 'statesmatrix_output.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATESMATRIX_OUTPUT_H
#define UI_STATESMATRIX_OUTPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_Statesmatrix_output
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Statesmatrix_output)
    {
        if (Statesmatrix_output->objectName().isEmpty())
            Statesmatrix_output->setObjectName("Statesmatrix_output");
        Statesmatrix_output->resize(800, 600);
        buttonBox = new QDialogButtonBox(Statesmatrix_output);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(230, 520, 201, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Statesmatrix_output);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Statesmatrix_output, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Statesmatrix_output, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Statesmatrix_output);
    } // setupUi

    void retranslateUi(QDialog *Statesmatrix_output)
    {
        Statesmatrix_output->setWindowTitle(QCoreApplication::translate("Statesmatrix_output", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Statesmatrix_output: public Ui_Statesmatrix_output {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATESMATRIX_OUTPUT_H
