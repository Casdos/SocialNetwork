/********************************************************************************
** Form generated from reading UI file 'cluster_show.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLUSTER_SHOW_H
#define UI_CLUSTER_SHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_Cluster_show
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Cluster_show)
    {
        if (Cluster_show->objectName().isEmpty())
            Cluster_show->setObjectName("Cluster_show");
        Cluster_show->resize(800, 600);
        buttonBox = new QDialogButtonBox(Cluster_show);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(120, 510, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Cluster_show);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Cluster_show, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Cluster_show, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Cluster_show);
    } // setupUi

    void retranslateUi(QDialog *Cluster_show)
    {
        Cluster_show->setWindowTitle(QCoreApplication::translate("Cluster_show", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cluster_show: public Ui_Cluster_show {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLUSTER_SHOW_H
