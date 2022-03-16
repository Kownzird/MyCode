#include "paintwidget.h"
#include <QPainter>
#include <QRadialGradient>

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

    painter.setBrush(Qt::Dense7Pattern);

    QPen pen(Qt::green, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);

//    QPainter painter(this);
//    QPen pen;  // creates a default pen

//    pen.setStyle(Qt::DashDotLine);
//    pen.setWidth(3);
//    pen.setBrush(Qt::green);
//    pen.setCapStyle(Qt::RoundCap);
//    pen.setJoinStyle(Qt::RoundJoin);

//    painter.setPen(pen);

    painter.drawEllipse(50,100,200,100);

    QVector<qreal> dashes;
    qreal space = 4;
    dashes << 1 << space << 3 << space << 9 << space << 27 << space << 9 << space;
    pen.setDashPattern(dashes);
    painter.setPen(pen);
    painter.drawEllipse(150,200,200,100);

}
