/********************************************************************************
** Form generated from reading UI file 'addsectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSECTDIALOG_H
#define UI_ADDSECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddSectDialog
{
public:
    QLineEdit *lineEdit;
    QPushButton *btnOk;
    QLabel *label;

    void setupUi(QDialog *AddSectDialog)
    {
        if (AddSectDialog->objectName().isEmpty())
            AddSectDialog->setObjectName(QString::fromUtf8("AddSectDialog"));
        AddSectDialog->resize(204, 104);
        lineEdit = new QLineEdit(AddSectDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 40, 161, 21));
        btnOk = new QPushButton(AddSectDialog);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        btnOk->setEnabled(false);
        btnOk->setGeometry(QRect(40, 70, 113, 32));
        label = new QLabel(AddSectDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 171, 16));

        retranslateUi(AddSectDialog);

        QMetaObject::connectSlotsByName(AddSectDialog);
    } // setupUi

    void retranslateUi(QDialog *AddSectDialog)
    {
        AddSectDialog->setWindowTitle(QCoreApplication::translate("AddSectDialog", "Dialog", nullptr));
        btnOk->setText(QCoreApplication::translate("AddSectDialog", "OK", nullptr));
        label->setText(QCoreApplication::translate("AddSectDialog", "Enter unique section name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddSectDialog: public Ui_AddSectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSECTDIALOG_H
