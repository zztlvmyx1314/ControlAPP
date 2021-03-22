#ifndef SETWIDGET_H
#define SETWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QSettings>

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
    void initwidget();



public:


    QString username=NULL;
    QString deviceid=NULL;
    QString password=NULL;

    QSettings *datafile=NULL;


signals:

    void saved();

private:
    Ui::SetWidget *ui;




};

#endif // SETWIDGET_H
