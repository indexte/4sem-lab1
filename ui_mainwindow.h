/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave_as;
    QAction *actionPrint;
    QAction *actionExit;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCut;
    QAction *actionUndo;
    QAction *actionRedo;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *rbs;
    QRadioButton *standard;
    QRadioButton *italic;
    QRadioButton *bold;
    QRadioButton *boldItalic;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QListWidget *listSections;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnRemoveSect;
    QPushButton *btnNewSect;
    QLabel *label_2;
    QListWidget *listFiles;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *rbDescending;
    QPushButton *btnSortByTime;
    QLabel *label_3;
    QPushButton *btnSortByName;
    QRadioButton *rbAscending;
    QPushButton *btnRemoveText;
    QMenuBar *menubar;
    QMenu *menuNotepad;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1015, 596);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/New.bmp"), QSize(), QIcon::Normal, QIcon::On);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imgs/Open.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imgs/Save.bmp"), QSize(), QIcon::Normal, QIcon::On);
        actionSave_as->setIcon(icon2);
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(290, 50, 701, 491));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(false);

        verticalLayout->addWidget(textEdit);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(290, 10, 701, 41));
        rbs = new QHBoxLayout(horizontalLayoutWidget);
        rbs->setObjectName(QString::fromUtf8("rbs"));
        rbs->setContentsMargins(0, 0, 0, 0);
        standard = new QRadioButton(horizontalLayoutWidget);
        standard->setObjectName(QString::fromUtf8("standard"));
        standard->setEnabled(false);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(14);
        standard->setFont(font);
        standard->setChecked(true);

        rbs->addWidget(standard);

        italic = new QRadioButton(horizontalLayoutWidget);
        italic->setObjectName(QString::fromUtf8("italic"));
        italic->setEnabled(false);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(14);
        font1.setItalic(true);
        italic->setFont(font1);

        rbs->addWidget(italic);

        bold = new QRadioButton(horizontalLayoutWidget);
        bold->setObjectName(QString::fromUtf8("bold"));
        bold->setEnabled(false);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        bold->setFont(font2);

        rbs->addWidget(bold);

        boldItalic = new QRadioButton(horizontalLayoutWidget);
        boldItalic->setObjectName(QString::fromUtf8("boldItalic"));
        boldItalic->setEnabled(false);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setWeight(75);
        boldItalic->setFont(font3);

        rbs->addWidget(boldItalic);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 261, 521));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(14);
        groupBox->setFont(font4);
        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 40, 241, 331));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Arial"));
        font5.setPointSize(12);
        label->setFont(font5);

        verticalLayout_2->addWidget(label);

        listSections = new QListWidget(verticalLayoutWidget_2);
        listSections->setObjectName(QString::fromUtf8("listSections"));

        verticalLayout_2->addWidget(listSections);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnRemoveSect = new QPushButton(verticalLayoutWidget_2);
        btnRemoveSect->setObjectName(QString::fromUtf8("btnRemoveSect"));
        btnRemoveSect->setEnabled(false);
        QFont font6;
        font6.setFamily(QString::fromUtf8("Arial"));
        font6.setPointSize(10);
        btnRemoveSect->setFont(font6);

        horizontalLayout_2->addWidget(btnRemoveSect);

        btnNewSect = new QPushButton(verticalLayoutWidget_2);
        btnNewSect->setObjectName(QString::fromUtf8("btnNewSect"));
        btnNewSect->setFont(font6);

        horizontalLayout_2->addWidget(btnNewSect);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font5);

        verticalLayout_2->addWidget(label_2);

        listFiles = new QListWidget(verticalLayoutWidget_2);
        listFiles->setObjectName(QString::fromUtf8("listFiles"));

        verticalLayout_2->addWidget(listFiles);

        label->raise();
        label_2->raise();
        listFiles->raise();
        listSections->raise();
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 410, 241, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        rbDescending = new QRadioButton(gridLayoutWidget);
        rbDescending->setObjectName(QString::fromUtf8("rbDescending"));
        rbDescending->setFont(font6);
        rbDescending->setChecked(true);

        gridLayout->addWidget(rbDescending, 1, 1, 1, 1);

        btnSortByTime = new QPushButton(gridLayoutWidget);
        btnSortByTime->setObjectName(QString::fromUtf8("btnSortByTime"));
        btnSortByTime->setEnabled(true);
        btnSortByTime->setFont(font6);

        gridLayout->addWidget(btnSortByTime, 2, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font5);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        btnSortByName = new QPushButton(gridLayoutWidget);
        btnSortByName->setObjectName(QString::fromUtf8("btnSortByName"));
        btnSortByName->setFont(font6);

        gridLayout->addWidget(btnSortByName, 2, 0, 1, 1);

        rbAscending = new QRadioButton(gridLayoutWidget);
        rbAscending->setObjectName(QString::fromUtf8("rbAscending"));
        rbAscending->setFont(font6);

        gridLayout->addWidget(rbAscending, 1, 0, 1, 1);

        btnRemoveText = new QPushButton(groupBox);
        btnRemoveText->setObjectName(QString::fromUtf8("btnRemoveText"));
        btnRemoveText->setEnabled(false);
        btnRemoveText->setGeometry(QRect(70, 375, 120, 32));
        btnRemoveText->setFont(font6);
        MainWindow->setCentralWidget(centralwidget);
        groupBox->raise();
        verticalLayoutWidget->raise();
        horizontalLayoutWidget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1015, 26));
        menuNotepad = new QMenu(menubar);
        menuNotepad->setObjectName(QString::fromUtf8("menuNotepad"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuNotepad->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuNotepad->addAction(actionNew);
        menuNotepad->addAction(actionOpen);
        menuNotepad->addAction(actionSave_as);
        menuNotepad->addAction(actionPrint);
        menuNotepad->addAction(actionExit);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_as->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPrint->setText(QCoreApplication::translate("MainWindow", "Print", nullptr));
#if QT_CONFIG(shortcut)
        actionPrint->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        actionPaste->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
        actionCut->setText(QCoreApplication::translate("MainWindow", "Cut", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        standard->setText(QCoreApplication::translate("MainWindow", "Standard", nullptr));
        italic->setText(QCoreApplication::translate("MainWindow", "Italic", nullptr));
        bold->setText(QCoreApplication::translate("MainWindow", "Bold", nullptr));
        boldItalic->setText(QCoreApplication::translate("MainWindow", "Bold italic", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Data", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Sections:", nullptr));
        btnRemoveSect->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        btnNewSect->setText(QCoreApplication::translate("MainWindow", "New...", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Files:", nullptr));
        rbDescending->setText(QCoreApplication::translate("MainWindow", "Descending", nullptr));
        btnSortByTime->setText(QCoreApplication::translate("MainWindow", "By time", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Sorting:", nullptr));
        btnSortByName->setText(QCoreApplication::translate("MainWindow", "By name", nullptr));
        rbAscending->setText(QCoreApplication::translate("MainWindow", "Ascending", nullptr));
        btnRemoveText->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        menuNotepad->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
