#ifndef SETFORM_H
#define SETFORM_H

#include <QDialog>
#include <QSettings>
#define DataFilePath "./DataFile.ini"
#define ClientData "ClientData"
#define UserID "UserID"
#define UserName "UserName"
#define PassWord "PassWord"

namespace Ui {
class SetForm;
}

class SetForm : public QDialog
{
    Q_OBJECT

public:
    explicit SetForm(QWidget *parent = nullptr);
    ~SetForm();

signals:

    void saved();
    void back();


public:

      QString  userid=NULL;
      QString  username=NULL;
      QString  password=NULL;
      QSettings* DataFile=NULL;



private slots:
    void on_save_pressed();

    void on_back_pressed();

private:
    Ui::SetForm *ui;




};

#endif // SETFORM_H
