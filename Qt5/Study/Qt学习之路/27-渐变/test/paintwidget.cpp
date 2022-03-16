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
//e.g.1
//    QPainter painter(this);
//    painter.setRenderHint(QPainter::Antialiasing, true);
//    QLinearGradient linearGradient(60,50,200,200); //起始点（60,50）  终止点（200,200）
//    linearGradient.setColorAt(0.2, Qt::white);
//    linearGradient.setColorAt(0.5, Qt::green);
//    linearGradient.setColorAt(1.0, Qt::black);
//    painter.setBrush(QBrush(linearGradient));

//    painter.drawEllipse(50,50,200,150);


//e.g.2
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    const int r = 150;

    //设置角度渐变的中心点为(0,0),起始角度为0
    QConicalGradient conicalGradient(0, 0, 0);

    conicalGradient.setColorAt(0.0, Qt::red);
    conicalGradient.setColorAt(60.0/360.0, Qt::yellow);
    conicalGradient.setColorAt(120.0/360.0, Qt::green);
    conicalGradient.setColorAt(180.0/360.0, Qt::cyan);
    conicalGradient.setColorAt(240.0/360.0, Qt::blue);
    conicalGradient.setColorAt(270.0/360.0, Qt::magenta);
    conicalGradient.setColorAt(1.0, Qt::red);

    //将坐标系的原点设置为(150,150)
    painter.translate(r,r);

    QBrush brush(conicalGradient);
    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
    painter.drawEllipse(QPoint(0,0), r,r);


}

