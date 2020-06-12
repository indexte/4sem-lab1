/**
 * @file add_text_dialog.cpp
 *
 */

#include "add_text_dialog.h"
#include "ui_addtextdialog.h"

AddTextDialog::AddTextDialog(QWidget *parent, vector<Text> textVec_) :
    QDialog(parent),
    ui(new Ui::AddTextDialog)
{
    ui->setupUi(this);
    textVec = textVec_;
}

AddTextDialog::~AddTextDialog()
{
    delete ui;
}

void AddTextDialog::on_btnOk_clicked()
{
    AddTextDialog::done(1);
}

void AddTextDialog::on_lineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        ui->btnOk->setEnabled(false);
    }
    else{
        bool present = false;

        for(size_t i=0; i<textVec.size(); i++){
            if(textVec.at(i).name==arg1){
                present = true;
            }
        }

        if(!present){
            ui->btnOk->setEnabled(true);
        }
        else{
            ui->btnOk->setEnabled(false);
        }
    }
}

QString AddTextDialog::ResultStiring(){
    return ui->lineEdit->text();
}
