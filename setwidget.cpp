#include "setwidget.h"
#include "ui_setwidget.h"

SetWidget::SetWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetWidget)
{
    ui->setupUi(this);

    this->datafile=new QSettings("./clientdata.ini",QSettings::IniFormat,this);


    connect(ui->save,&QPushButton::pressed,this,&SetWidget::dealsavebutton);


    ui->statusbar->setText("状态：");


}

SetWidget::~SetWidget()
{
    delete ui;
}

void SetWidget::dealsavebutton()
{
   if(ui->clientid->text()==NULL||ui->username->text()==NULL||ui->password->text()==NULL){

      ui->statusbar->setText("用户信息不完整，保存失败");
      return;


   }

    this->datafile->beginGroup("ClientData");

    this->datafile->setValue("ClientID",ui->clientid->text());
    this->datafile->setValue("UserName",ui->username->text());
    this->datafile->setValue("PassWord",ui->password->text());
    this->datafile->endGroup();

    this->username=ui->username->text();
    this->deviceid=ui->clientid->text();
    this->password=ui->password->text();

    ui->statusbar->setText("状态：保存成功");

    emit this->saved();



}

void SetWidget::initwidget()
{


    ui->statusbar->setText("状态：");

}
