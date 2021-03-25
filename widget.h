#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QtMqtt/QtMqtt>
#include <QtMqtt/QMqttTopicName>
#include "setform.h"



QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void dealset();

    void dealreceivemessage(const QByteArray &message, const QMqttTopicName &topic);

    void connecttobroker();





public:




private slots:
    void on_set_pressed();

    void on_lts_clicked();

    void on_rts_clicked();

    void on_lbs_clicked();

    void on_rbs_clicked();

private:
    Ui::Widget *ui;

//    SetWidget* SetForm=NULL;

    QMqttClient* Client=NULL;

    QMqttTopicName* Topic=NULL;


     SetForm* setform=NULL;


};
#endif // WIDGET_H
