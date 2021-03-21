#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->SetForm=new SetWidget();
    this->SetForm->hide();
    this->Client=new QMqttClient(this);

    connect(ui->set,&QPushButton::pressed,this,&Widget::dealset);

    this->Client->setHostname("101.133.196.120");
    this->Client->setPort(1883);

    this->Client->setClientId(this->SetForm->deviceid);
    this->Client->setUsername(this->SetForm->username);
    this->Client->setPassword(this->SetForm->password);

    this->Client->connectToHost();

    this->Client->requestPing();

    connect(this->SetForm,&SetWidget::saved,this,&Widget::connecttobroker);



    connect(this->Client,&QMqttClient::connected,this,[=]{


       ui->constaus->setText("连接状态：连接成功");


    });

    connect(this->Client,&QMqttClient::disconnected,this,[=]{


       ui->constaus->setText("连接状态：连接已断开");


    });

    connect(this->Client,&QMqttClient::messageReceived,this,&Widget::dealreceivemessage);


   setStyleSheet("QPushButton { background-color:rgb(200,200,150);border-radius:100px;"
                 "border:3px solid green}"
                 "QPushButton:pressed{border:3px solid red}");









}

Widget::~Widget()
{
    delete ui;
}

void Widget::dealset()
{

     this->SetForm->show();





}

void Widget::dealreceivemessage(const QByteArray &message, const QMqttTopicName &topic)
{

     ui->constaus->setText(message);



}

void Widget::connecttobroker()
{
   if(this->Client->state()==QMqttClient::Connected){

       this->Client->disconnectFromHost();



   }


    ui->constaus->setText("连接状态：正在连接");


    this->Client->setClientId(this->SetForm->deviceid);
    this->Client->setUsername(this->SetForm->username);
    this->Client->setPassword(this->SetForm->password);

    this->Client->connectToHost();

    this->Client->requestPing();



}

