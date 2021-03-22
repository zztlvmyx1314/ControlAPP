#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "setwidget.h"
#include <QtMqtt/QtMqtt>
#include <QMqttTopicName>


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








private:
    Ui::Widget *ui;

    SetWidget* SetForm=NULL;

    QMqttClient* Client=NULL;

    QMqttTopicName* Topic=NULL;




};
#endif // WIDGET_H
