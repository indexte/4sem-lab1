/********************************************************************************
** Form generated from reading UI file 'addtextdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTEXTDIALOG_H
#define UI_ADDTEXTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddTextDialog
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *btnOk;

    void setupUi(QDialog *AddTextDialog)
    {
        if (AddTextDialog->objectName().isEmpty())
            AddTextDialog->setObjectName(QString::fromUtf8("AddTextDialog"));
        AddTextDialog->resize(189, 96);
        lineEdit = new QLineEdit(AddTextDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 30, 171, 21));
        label = new QLabel(AddTextDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 201, 16));
        btnOk = new QPushButton(AddTextDialog);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        btnOk->setEnabled(false);
        btnOk->setGeometry(QRect(40, 60, 113, 32));

        retranslateUi(AddTextDialog);

        QMetaObject::connectSlotsByName(AddTextDialog);
    } // setupUi

    void retranslateUi(QDialog *AddTextDialog)
    {
        AddTextDialog->setWindowTitle(QCoreApplication::translate("AddTextDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddTextDialog", "Enter unique text file name", nullptr));
        btnOk->setText(QCoreApplication::translate("AddTextDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTextDialog: public Ui_AddTextDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTEXTDIALOG_H
