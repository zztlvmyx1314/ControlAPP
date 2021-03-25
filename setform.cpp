#include "setform.h"
#include "ui_setform.h"

SetForm::SetForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetForm)
{
    ui->setupUi(this);

    this->hide();

    this->DataFile=new QSettings(DataFilePath,QSettings::IniFormat,this);


    ui->statusbar->setText("状态：");

     ui->save->setStyleSheet("background-color:rgb(240,240,240)");
     ui->back->setStyleSheet("background-color:rgb(240,240,240)");

//     this->resize(this->parentWidget()->width(),this->parentWidget()->height());




}

SetForm::~SetForm()
{
    delete ui;
}

void SetForm::on_save_pressed()
{

    if(ui->userid->text()==NULL||ui->username->text()==NULL||ui->password->text()==NULL){

       ui->statusbar->setText("状态：用户信息不完整,保存失败");
            return;

    }


    this->DataFile->beginGroup(ClientData);
    this->DataFile->setValue(UserID,ui->userid->text());
    this->DataFile->setValue(UserName,ui->username->text());
    this->DataFile->setValue(PassWord,ui->password->text());
    this->DataFile->endGroup();

    this->userid=ui->userid->text();
    this->username=ui->username->text();
    this->password=ui->password->text();

    ui->statusbar->setText("状态：保存成功");


   emit this->saved();




}

void SetForm::on_back_pressed()
{
    emit back();
    this->close();


}
