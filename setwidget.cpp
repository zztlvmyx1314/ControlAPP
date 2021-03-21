#include "setwidget.h"
#include "ui_setwidget.h"

SetWidget::SetWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetWidget)
{
    ui->setupUi(this);

    this->username=ui->username->text();
    this->deviceid=ui->clientid->text();
    this->password=ui->password->text();

    connect(ui->save,&QPushButton::pressed,this,&SetWidget::dealsavebutton);



}

SetWidget::~SetWidget()
{
    delete ui;
}

void SetWidget::dealsavebutton()
{

    this->username=ui->username->text();
    this->deviceid=ui->clientid->text();
    this->password=ui->password->text();



    emit this->saved();



}
