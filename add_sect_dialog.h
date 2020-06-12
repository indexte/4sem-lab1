/**
 * @file add_sect_dialog.h
 *
 * @brief This is a file that brings up a dialog asking the user for the name of a new section.
 *
 */

#include <QDialog>
#include <vector>
#include <section.h>
#include <QString>

using namespace std;

namespace Ui {
class AddSectDialog;
}

class AddSectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddSectDialog(QWidget *parent, vector<Section> sectVec_);
    ~AddSectDialog();
    QString ResultStiring();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_btnOk_clicked();

private:
    Ui::AddSectDialog *ui;
    vector<Section> sectVec;
};
