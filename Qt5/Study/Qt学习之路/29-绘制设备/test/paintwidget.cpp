#include "paintwidget.h"
#include <QPainter>
#include <QPixmap>
#include <QBitmap>
#include <QImage>
#include <QPicture>

PaintWidget::PaintWidget(QWidget *parent)
    : QWidget(parent)
{
}

PaintWidget::~PaintWidget()
{
}

void PaintWidget::paintEvent(QPaintEvent *event)
{

//QPixmap
//    QPainter painter(this);
//    QPixmap pixmap(":/images/qt_logo.png");
//    QBitmap bitmap(":/images/qt_logo.png");
//    painter.drawPixmap(10,10,250,125, pixmap);
//    painter.drawPixmap(270,10,250,125, bitmap);

//    QPixmap whitepixmap(":/images/qt_white_logo.png");
//    QBitmap whitebitmap(":/images/qt_white_logo.png");
//    painter.drawPixmap(10,140,250,125, whitepixmap);
//    painter.drawPixmap(270,140,250,125, whitebitmap);



//QImage
//    //QPixmap使用底层平台的绘制系统进行绘制，无法提供像素级别的操作，
//    //而QImage则是使用独立于硬件的绘制系统，实际上是自己绘制自己，因此提供了像素级别的操作
//    QPainter painter(this);
//    QImage image(3,3, QImage::Format_RGB32);
//    QRgb value;

//    value = qRgb(189,149,39);
//    image.setPixel(1,1,value);

//    value = qRgb(122,163,39);
//    image.setPixel(0,1,value);
//    image.setPixel(1,0,value);

//    value = qRgb(237,187,51);
//    image.setPixel(2,1,value);

//    painter.drawImage(20,20,image);



//QPicture
    QPicture picture;
    QPainter painter;
    painter.begin(&picture);
    painter.drawEllipse(10,20,80,70); //在picture上进行绘制
    painter.end();                    //绘制完成
    picture.save("Ellipse.pic");      //保存picture

    picture.load("Ellipse.pic");      //加载picture
    painter.begin(this);              //在当前设备上进行绘制
    painter.drawPicture(0,0,picture); //在(0,0)点进行绘制
    painter.end();

}
