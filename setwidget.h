#ifndef SETWIDGET_H
#define SETWIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class SetWidget;
}

class SetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SetWidget(QWidget *parent = nullptr);
    ~SetWidget();

    void dealsavebutton();



public:


    QString username=NULL;
    QString deviceid=NULL;
    QString password=NULL;


signals:

    void saved();

private:
    Ui::SetWidget *ui;


};

#endif // SETWIDGET_H
