/********************************************************************************
** Form generated from reading UI file 'matrix_output.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATRIX_OUTPUT_H
#define UI_MATRIX_OUTPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_matrix_output
{
public:

    void setupUi(QDialog *matrix_output)
    {
        if (matrix_output->objectName().isEmpty())
            matrix_output->setObjectName("matrix_output");
        matrix_output->resize(800, 600);

        retranslateUi(matrix_output);

        QMetaObject::connectSlotsByName(matrix_output);
    } // setupUi

    void retranslateUi(QDialog *matrix_output)
    {
        matrix_output->setWindowTitle(QCoreApplication::translate("matrix_output", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class matrix_output: public Ui_matrix_output {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATRIX_OUTPUT_H
