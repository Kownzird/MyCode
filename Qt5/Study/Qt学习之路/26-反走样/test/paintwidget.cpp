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
    painter.setPen(QPen(Qt::black, 5, Qt::DashDotLine, Qt::RoundCap));
    painter.setBrush(Qt::yellow);
    painter.drawEllipse(50,150,200,150);

    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.drawEllipse(300,150,200,150);
}
