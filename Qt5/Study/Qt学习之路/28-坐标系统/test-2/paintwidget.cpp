#include "paintwidget.h"
#include <QPainter>
#include <QThread>

PaintWidget::PaintWidget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(400,400);
}

PaintWidget::~PaintWidget()
{
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //将窗口矩形设置为左上角坐标为 (0, 0)，长和宽都是 200px
    //对于原来的 (400, 400) 点，新的窗口坐标是 (200, 200)
//    painter.setWindow(0,0,200,200);
//    painter.fillRect(0,0,200,200, Qt::red);

    //将坐标原点设置到 (200, 200) 处，横坐标范围是 [-200, 200]，纵坐标范围是 [-200, 200]
    //将物理宽 400px 映射成窗口宽 320px，物理高 400px 映射成窗口高 640px
    //假设原来有个点坐标是 (64， 60)，那么新的窗口坐标下对应的坐标应该是 ((-160 + 64 * 320 / 400), (-320 + 60 * 640 / 400)) = (-108.8, -224)
//    painter.translate(200,200);
//    painter.setWindow(-160,-320,320,640);
//    painter.fillRect(-160,-320,320,640, Qt::blue);

    painter.setViewport(0,0,200,200);
    painter.fillRect(0,0,200,200, Qt::yellow);



}
