/**
 * @file add_sect_dialog.cpp
 *
 */

#include "add_sect_dialog.h"
#include "ui_addsectdialog.h"

AddSectDialog::AddSectDialog(QWidget *parent, vector<Section> sectVec_) :
    QDialog(parent),
    ui(new Ui::AddSectDialog)
{
    ui->setupUi(this);
    sectVec = sectVec_;
}

AddSectDialog::~AddSectDialog()
{
    delete ui;
}

void AddSectDialog::on_lineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        ui->btnOk->setEnabled(false);
    }
    else{
        bool present = false;

        for(size_t i=0; i<sectVec.size(); i++){
            if(sectVec.at(i).sectionName==arg1){
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

QString AddSectDialog::ResultStiring(){
    return ui->lineEdit->text();
}

void AddSectDialog::on_btnOk_clicked()
{
    AddSectDialog::done(1);
}
