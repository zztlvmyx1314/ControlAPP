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
    this->Topic=new QMqttTopicName("/a119pHQEFSr/ControlAPP/user/onoroff");


    connect(ui->set,&QPushButton::pressed,this,&Widget::dealset);

    this->Client->setHostname("101.133.196.120");  // 设置云服务器的IP地址
    this->Client->setPort(1883);   // 端口号

/***************************配置用户信息*************************/
    this->Client->setClientId(this->SetForm->datafile->value("ClientData/ClientID").toString());
    this->Client->setUsername(this->SetForm->datafile->value("ClientData/UserName").toString());
    this->Client->setPassword(this->SetForm->datafile->value("ClientData/PassWord").toString());

    this->Client->connectToHost();  // 启动云服务器的连接

    this->Client->requestPing();    // 发送心跳包

    connect(this->SetForm,&SetWidget::saved,this,&Widget::connecttobroker);  // 保存用户信息并连接云服务器

/**************************控制按钮响应********************************/

    connect(ui->lts,&QPushButton::pressed,this,[=]{

         this->Client->publish(*(this->Topic),"=01");

    });

   connect(ui->lbs,&QPushButton::pressed,this,[=]{

       this->Client->publish(*(this->Topic),"=00");

  });

   connect(ui->rts,&QPushButton::pressed,this,[=]{

       this->Client->publish(*(this->Topic),"=11");

  });

   connect(ui->rbs,&QPushButton::pressed,this,[=]{

       this->Client->publish(*(this->Topic),"=10");

  });


/***********************连接云服务器***********************/

   connect(ui->conntobroker,&QPushButton::pressed,this,[=]{

       this->Client->connectToHost();

       this->Client->requestPing();

   });


/*************************连接状态************************/

    connect(this->Client,&QMqttClient::connected,this,[=]{


       ui->constaus->setText("连接状态：连接成功");


    });

    connect(this->Client,&QMqttClient::disconnected,this,[=]{


       ui->constaus->setText("连接状态：连接已断开");


    });


/*************************处理接收信息***********************/

    connect(this->Client,&QMqttClient::messageReceived,this,&Widget::dealreceivemessage);


/***************************控件样式*************************/

   setStyleSheet("QPushButton { background-color:rgb(200,200,150);border-radius:100px;"
                 "border:3px solid green}"
                 "QPushButton:pressed{border:3px solid red}");

   ui->set->setStyleSheet("background-color:rgb(240,240,240)");
   ui->conntobroker->setStyleSheet("background-color:rgb(240,240,240)");







}

Widget::~Widget()
{
    delete ui;
}

void Widget::dealset()
{

     this->SetForm->show();
     this->SetForm->initwidget();

//     this->hide();



}

void Widget::dealreceivemessage(const QByteArray &message, const QMqttTopicName &topic)
{

     ui->constaus->setText("状态："+message);



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



