#include "paintwidget.h"
#include <QPainter>

PaintWidget::PaintWidget(QWidget *parent)
    : QWidget(parent)
{
}

PaintWidget::~PaintWidget()
{
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(10,10,50,100, Qt::red);
    painter.save();
    painter.translate(100,0); //向右平移 100px
    painter.fillRect(10,10,50,100, Qt::yellow);
    painter.restore();

    painter.save();
    painter.translate(300,0); //向右平移 300px
    painter.rotate(30);  //顺时针旋转30度
    painter.fillRect(10,10,50,100, Qt::green);
    painter.restore();

    painter.save();
    painter.translate(400,0); //向右平移 400px
    painter.scale(2,3); //横坐标放大2倍，纵坐标放大3倍
    painter.fillRect(10,10,50,100, Qt::blue);
    painter.restore();

    painter.save();
    painter.translate(600,0); //向右平移 600px
    painter.shear(0,1); //横坐标不变，纵坐标扭曲一倍
    painter.fillRect(10,10,50,100, Qt::cyan);
    painter.restore();

}
