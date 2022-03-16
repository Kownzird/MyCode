#include "widget.h"

#include <QApplication>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QLabel>
#include <QDebug>

class EventLabel:public QLabel
{
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

void EventLabel::mouseMoveEvent(QMouseEvent *event)
{
    this->setText(QString("<center><h1>Move:(%1, %2)</h1></center>").arg(QString::number(event->x()), QString::number(event->y())));
}

void EventLabel::mousePressEvent(QMouseEvent *event)
{
    this->setText(QString("<center><h1>Move:(%1, %2)</h1></center>").arg(QString::number(event->x()), QString::number(event->y())));
}

void EventLabel::mouseReleaseEvent(QMouseEvent *event)
{
    QString msg;
    msg.sprintf("<center><h1>Move:(%d, %d)</h1></center>",event->x(), event->y());
    this->setText(msg);
}

void EventLabel::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key Press";
    this->setText(QString("<center><h1>Key Press</h1></center>"));
}

void EventLabel::keyReleaseEvent(QKeyEvent *event)
{
    qDebug() << "Key Release";
    this->setText(QString("<center><h1>Key Release</h1></center>"));
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    EventLabel *label = new EventLabel;
    label->setWindowTitle("MouseEvent Demo");
    label->resize(300,200);
    label->setMouseTracking(true); //设置鼠标跟踪
    label->show();

    return a.exec();
}
