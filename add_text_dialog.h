/**
 * @file add_text_dialog.h
 *
 * @brief This is a file that brings up a dialog asking the user for the name of a new file.
 *
 */

#include <QDialog>
#include <vector>
#include "section.h"
#include "text.h"

using namespace std;

namespace Ui {
class AddTextDialog;
}

class AddTextDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTextDialog(QWidget *parent, vector<Text> textVec_);
    ~AddTextDialog();
    QString ResultStiring();

private slots:
    void on_btnOk_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::AddTextDialog *ui;
    vector<Text> textVec;
};
