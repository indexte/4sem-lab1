/**
 * @file mainwindow.cpp
 *
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVariant>
#include <QDebug>
#include <QList>
#include <QListWidgetItem>
#include <QDateTime>
#include "add_sect_dialog.h"
#include "add_text_dialog.h"

void MainWindow::SectionPrinter(){
    vector<Section> vecSect = storage->GetAllSections();

    for(int i = ui->listFiles->count()-1; i >=0; i--)
    {
        QListWidgetItem* item = ui->listFiles->item(i);
        ui->listFiles->takeItem(i);
        delete item;
    }

    for(int i = ui->listSections->count()-1; i >=0; i--)
    {
        QListWidgetItem* item = ui->listSections->item(i);
        ui->listSections->takeItem(i);
        delete item;
    }

    for(unsigned i=0 ; i<vecSect.size(); i++){
        QListWidgetItem * newItem = new QListWidgetItem(vecSect.at(i).sectionName);
        QVariant newVariant = QVariant::fromValue<Section>(vecSect.at(i));
        newItem->setData(Qt::UserRole, newVariant);
        ui->listSections->addItem(newItem);
    }

    ui->listSections->setCurrentRow(vecSect.size()-1);

    if(vecSect.size()>1){
        ui->btnRemoveSect->setEnabled(true);
    }
    else{
        ui->btnRemoveSect->setEnabled(false);
    }
}

void MainWindow::TextPrinter(){
    vector<Text> textVect = storage->GetAllTextInSection(selectedSect);

    for(int i = ui->listFiles->count()-1; i >=0; i--)
    {
        QListWidgetItem* item = ui->listFiles->item(i);
        ui->listFiles->takeItem(i);
        delete item;
    }

    for(unsigned i=0 ; i<textVect.size(); i++){
        QListWidgetItem * newItem = new QListWidgetItem(textVect.at(i).name);
        QVariant newVariant = QVariant::fromValue<Text>(textVect.at(i));
        newItem->setData(Qt::UserRole, newVariant);
        ui->listFiles->addItem(newItem);
    }
}


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Notepad");
    // STORAGE
        QDir dir(".");
        qDebug()<<"CUR DIR"<<dir.currentPath();
        storage->Start("..\\data\\data.sqlite");
        storage->ClearData();
        defSectInt = storage->InsertSection("Main");
        qDebug()<<"DEFAULT SECTION ID: "<<defSectInt;
        SectionPrinter();
    //

    // FONT
        curFont.setBold(false);
        curFont.setItalic(false);
        curFont.setFamily("Times new roman");
        curFont.setPixelSize(18);

        standardFont.setBold(false);
        standardFont.setItalic(false);
        standardFont.setFamily("Times new roman");
        standardFont.setPixelSize(18);

        ui->textEdit->setFont(curFont);
    //

        nullText.id = -1;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    AddTextDialog *addTextDialog = new AddTextDialog(this, storage->GetAllTextInSection(selectedSect));
    int status = addTextDialog->exec();

    if(status!=0){  // 0 - отклонено
        Text tempText;
        tempText.name = addTextDialog->ResultStiring();
        tempText.string = "";
        tempText.font = standardFont;
        tempText.time = QDateTime::currentDateTime();

        storage->InsertText(selectedSect, tempText);
        TextPrinter();

        ui->standard->setChecked(true);
        curFont.setBold(false);
        curFont.setItalic(false);
        ui->textEdit->setFont(curFont);
        ui->standard->setEnabled(false);
        ui->italic->setEnabled(false);
        ui->bold->setEnabled(false);
        ui->boldItalic->setEnabled(false);
    }
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    if(!fileName.isEmpty()){
        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
            return;
        }

        AddTextDialog *addTextDialog = new AddTextDialog(this, storage->GetAllTextInSection(selectedSect));
        int status = addTextDialog->exec();

        if(status!=0){  // 0 - отклонено

            QTextStream in(&file);
            QString text = in.readAll();

            int numOfStyles = 0;
            Text tempText;
            bool isBold = false;
            bool isItalic = false;

            if(text.length()>6){
                if(text[0]=='<'){
                    numOfStyles++;

                    if(text[1]=='b'){
                        isBold = true;
                    }
                    else if(text[1]=='i'){
                        isItalic = true;
                    }
                }
            }

            if(text.length()>13){
                if(text[3]=='<'){
                    numOfStyles++;

                    if(text[4]=='b'){
                        isBold = true;
                    }
                    else if(text[4]=='i'){
                        isItalic = true;
                    }
                }
            }

            QString subString = text.mid(numOfStyles*3,text.length()-(numOfStyles*7));

            tempText.string = subString;
            tempText.font = standardFont;
            tempText.font.setBold(isBold);
            tempText.font.setItalic(isItalic);
            tempText.time = QDateTime::currentDateTime();
            tempText.name = addTextDialog->ResultStiring();

            storage->InsertText(selectedSect, tempText);
            TextPrinter();

            ui->textEdit->setEnabled(false);

            ui->standard->setChecked(true);
            curFont.setBold(false);
            curFont.setItalic(false);
            ui->textEdit->setFont(curFont);
            ui->standard->setEnabled(false);
            ui->italic->setEnabled(false);
            ui->bold->setEnabled(false);
            ui->boldItalic->setEnabled(false);

            //ui->textEdit->setText(text);
            file.close();
        }
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName+".html");

    if(!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
        return;
    }
    //currentFile = fileName;
    //setWindowTitle(fileName);
    QTextStream out(&file);

    QString text = ui->textEdit->toPlainText();

    if(curFont.bold()){
        QString extraText = "<b>";
        extraText+=text;
        text=extraText;
        text+="</b>";
    }

    if(curFont.italic()){
        QString extraText = "<i>";
        extraText+=text;
        text=extraText;
        text+="</i>";
    }

    out << text;
    file.close();
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;

    // You'll put your printer name here
    printer.setPrinterName("Printer Name");

    // Create the print dialog and pass the name and parent
    QPrintDialog pDialog(&printer, this);

    if(pDialog.exec() == QDialog::Rejected){
        QMessageBox::warning(this, "Warning", "Cannot Access Printer");
        return;
    }

    // Send the text to the printer
    ui->textEdit->print(&printer);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_standard_clicked()
{
    curFont.setBold(false);
    curFont.setItalic(false);
    ui->textEdit->setFont(curFont);

    // UPDATING
    Text tempText = selectedText;
    tempText.string = ui->textEdit->toPlainText();
    tempText.font.setBold(false);
    tempText.font.setItalic(false);
    QVariant newVariant = QVariant::fromValue<Text>(tempText);
    ui->listFiles->selectedItems().at(0)->setData(Qt::UserRole, newVariant);
    storage->UpdateText(tempText);
    //

    qDebug()<<"STANDARD TEXT FOND";
}

void MainWindow::on_italic_clicked()
{
    curFont.setBold(false);
    curFont.setItalic(true);
    ui->textEdit->setFont(curFont);

    // UPDATING
    Text tempText = selectedText;
    tempText.string = ui->textEdit->toPlainText();
    tempText.font.setBold(false);
    tempText.font.setItalic(true);
    QVariant newVariant = QVariant::fromValue<Text>(tempText);
    ui->listFiles->selectedItems().at(0)->setData(Qt::UserRole, newVariant);
    storage->UpdateText(tempText);
    //
    qDebug()<<"ITALIC TEXT FOND";
}

void MainWindow::on_bold_clicked()
{
    curFont.setBold(true);
    curFont.setItalic(false);
    ui->textEdit->setFont(curFont);
    // UPDATING
    Text tempText = selectedText;
    tempText.string = ui->textEdit->toPlainText();
    tempText.font.setBold(true);
    tempText.font.setItalic(false);
    QVariant newVariant = QVariant::fromValue<Text>(tempText);
    ui->listFiles->selectedItems().at(0)->setData(Qt::UserRole, newVariant);
    storage->UpdateText(tempText);
    //
    qDebug()<<"BOLD TEXT FOND";
}

void MainWindow::on_boldItalic_clicked()
{
    curFont.setBold(true);
    curFont.setItalic(true);
    ui->textEdit->setFont(curFont);
    // UPDATING
    Text tempText = selectedText;
    tempText.string = ui->textEdit->toPlainText();
    tempText.font.setBold(true);
    tempText.font.setItalic(true);
    QVariant newVariant = QVariant::fromValue<Text>(tempText);
    ui->listFiles->selectedItems().at(0)->setData(Qt::UserRole, newVariant);
    storage->UpdateText(tempText);
    //
    qDebug()<<"BOLD ITALIC TEXT FOND";
}

void MainWindow::on_listSections_itemClicked(QListWidgetItem *item)
{
    selectedText = nullText;
    ui->textEdit->setEnabled(false);

    isClearing = true;
    ui->textEdit->clear();

    selectedSect = (item->data(Qt::UserRole)).value<Section>();
    if(selectedSect.id!=defSectInt){
        ui->btnRemoveSect->setEnabled(true);
    }
    else{
        ui->btnRemoveSect->setEnabled(false);
    }
    TextPrinter();
    qDebug()<<"end of changes after item click";
    isClearing = false;
}

void MainWindow::on_btnNewSect_clicked()
{
    AddSectDialog *addSectDialog = new AddSectDialog(this, storage->GetAllSections());
    int status = addSectDialog->exec();

    if(status!=0){  // 0 - отклонено
        storage->InsertSection(addSectDialog->ResultStiring());
        SectionPrinter();

        selectedText=nullText;

        ui->textEdit->setEnabled(false);
        ui->textEdit->clear();
    }
}

void MainWindow::on_btnRemoveSect_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Section removing", "Are you sure?");

    if(reply==QMessageBox::StandardButton::Yes){
        selectedSect = (ui->listSections->selectedItems().at(0)->data(Qt::UserRole)).value<Section>();
        storage->RemoveSection(selectedSect);
        SectionPrinter();
    }
}

void MainWindow::on_btnSortByName_clicked()
{
    if(ui->rbAscending->isChecked()){
        ui->listFiles->sortItems(Qt::AscendingOrder);
    }
    else{
        ui->listFiles->sortItems(Qt::DescendingOrder);
    }
}

void MainWindow::on_listSections_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    selectedSect = (ui->listSections->selectedItems().at(0)->data(Qt::UserRole)).value<Section>();
    TextPrinter();

    ui->standard->setEnabled(false);
    ui->italic->setEnabled(false);
    ui->bold->setEnabled(false);
    ui->boldItalic->setEnabled(false);
}

void MainWindow::TextAreaChanger(){
    isClearing=true;

    ui->textEdit->clear();
    ui->textEdit->setText(selectedText.string);

    if(selectedText.font.bold()){
        if(selectedText.font.italic()){
            ui->boldItalic->setChecked(true);
            curFont.setBold(true);
            curFont.setItalic(true);
            ui->textEdit->setFont(curFont);
        }
        else{
            ui->bold->setChecked(true);
            curFont.setBold(true);
            curFont.setItalic(false);
            ui->textEdit->setFont(curFont);
        }
    }
    else{
        if(selectedText.font.italic()){
            ui->italic->setChecked(true);
            curFont.setBold(false);
            curFont.setItalic(true);
            ui->textEdit->setFont(curFont);
        }
        else{
            ui->standard->setChecked(true);
            curFont.setBold(false);
            curFont.setItalic(false);
            ui->textEdit->setFont(curFont);
        }
    }

    isClearing=false;
}

void MainWindow::on_listFiles_itemClicked(QListWidgetItem *item)
{
    selectedText = (ui->listFiles->selectedItems().at(0)->data(Qt::UserRole)).value<Text>();
    ui->textEdit->setEnabled(true);

    ui->standard->setEnabled(true);
    ui->italic->setEnabled(true);
    ui->bold->setEnabled(true);
    ui->boldItalic->setEnabled(true);

    ui->btnRemoveText->setEnabled(true);
    TextAreaChanger();
}

void MainWindow::on_textEdit_textChanged()
{
    selectedSect = (ui->listSections->selectedItems().at(0)->data(Qt::UserRole)).value<Section>();
    if(storage->GetAllTextInSection(selectedSect).size()<=0){
        selectedText=nullText;
        ui->textEdit->setEnabled(false);
    }

    if(!isClearing && selectedText.id!=-1){
        Text tempText = selectedText;
        tempText.string = ui->textEdit->toPlainText();

        QVariant newVariant = QVariant::fromValue<Text>(tempText);
        ui->listFiles->selectedItems().at(0)->setData(Qt::UserRole, newVariant);

        storage->UpdateText(tempText);
    }

}

void MainWindow::on_btnRemoveText_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Section removing", "Are you sure?");

    if(reply==QMessageBox::StandardButton::Yes){
        ui->standard->setEnabled(false);
        ui->italic->setEnabled(false);
        ui->bold->setEnabled(false);
        ui->boldItalic->setEnabled(false);

        ui->standard->setChecked(true);
        curFont.setBold(false);
        curFont.setItalic(false);
        ui->textEdit->setFont(curFont);

        storage->RemoveText(selectedText);
        selectedText=nullText;
        ui->textEdit->setEnabled(false);
        ui->textEdit->clear();
        TextPrinter();
    }
}

bool dataLessThan(const QListWidgetItem &v1, const QListWidgetItem &v2)
 {
    QListWidgetItem i1 = v1;
    QListWidgetItem i2 = v2;

    QDateTime t1 = i1.data(Qt::UserRole).value<Text>().time;
    QDateTime t2 = i2.data(Qt::UserRole).value<Text>().time;

    return t1<t2;
 }

bool dataGraterThan(const QListWidgetItem &v1, const QListWidgetItem &v2)
 {
    QListWidgetItem i1 = v1;
    QListWidgetItem i2 = v2;

    QDateTime t1 = i1.data(Qt::UserRole).value<Text>().time;
    QDateTime t2 = i2.data(Qt::UserRole).value<Text>().time;

    return t1>t2;
 }

void MainWindow::on_btnSortByTime_clicked()
{
    QList<QListWidgetItem> listForSort;

    for(int i =0; i<ui->listFiles->count(); i++){
        QListWidgetItem tempItem = *ui->listFiles->item(i);
        listForSort.push_back(tempItem);
    }

    for(int i = ui->listFiles->count()-1; i >=0; i--)
    {
        QListWidgetItem* item = ui->listFiles->item(i);
        ui->listFiles->takeItem(i);
        delete item;
    }

    if(ui->rbAscending->isChecked()){
        qSort(listForSort.begin(), listForSort.end(), dataLessThan);
    }
    else{
        qSort(listForSort.begin(), listForSort.end(), dataGraterThan);
    }

    for(int i=0 ; i<listForSort.size(); i++){
        QListWidgetItem * newItem = new QListWidgetItem();
        *newItem = listForSort.at(i);
        ui->listFiles->addItem(newItem);
    }

    selectedText=nullText;
    ui->standard->setEnabled(false);
    ui->italic->setEnabled(false);
    ui->bold->setEnabled(false);
    ui->boldItalic->setEnabled(false);

    ui->standard->setChecked(true);
    curFont.setBold(false);
    curFont.setItalic(false);
    ui->textEdit->setFont(curFont);

    ui->textEdit->setEnabled(false);
    ui->textEdit->clear();
}
