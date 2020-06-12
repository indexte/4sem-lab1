/**
 * @file mainwindow.h
 *
 * @brief This file is part of the examples of the Qt Toolkit.
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include<QFile>
#include<QFileDialog>
#include<QTextStream>
#include<QMessageBox>
#include<QPrinter>
#include<QPrintDialog>
#include <QListWidgetItem>
#include <QFont>
#include <QVector2D>
#include "text.h"
#include "section.h"
#include "sqlite_storage.h"
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_standard_clicked();

    void on_italic_clicked();

    void on_bold_clicked();

    void on_boldItalic_clicked();

    void SectionPrinter();

    void TextPrinter();

    void on_listSections_itemClicked(QListWidgetItem *item);

    void on_btnNewSect_clicked();

    void on_btnRemoveSect_clicked();

    void on_btnSortByName_clicked();

    void on_listSections_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_listFiles_itemClicked(QListWidgetItem *item);

    void TextAreaChanger();

    void on_textEdit_textChanged();

    void on_btnRemoveText_clicked();

    void on_btnSortByTime_clicked();

private:
    Ui::MainWindow *ui;
    //QString currentFile = "";
    QFont curFont;
    QFont standardFont;
    SqliteStorage * storage = new SqliteStorage();
    Section selectedSect;
    Text selectedText;
    Text nullText;
    int defSectInt;
    bool isClearing;
};
#endif // MAINWINDOW_H
