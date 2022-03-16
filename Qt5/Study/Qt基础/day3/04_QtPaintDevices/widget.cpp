#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QImage>
#include <QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


//    //Pixmap绘图设备  专门为平台做了显示优化
//    QPixmap pix(300,300);

//    //填充颜色
//    pix.fill(Qt::white);

//    //声明画家
//    QPainter painter(&pix);
//    painter.setPen(QPen(Qt::green));
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(150,150),50,50);

//    //保存
//    pix.save("D:\\2-Myspace\\QTProject\\pix.png");



//    //QImage 绘图设备  可以对像素点进行访问
//    QImage img(300,300,QImage::Format_RGB32);
//    img.fill(Qt::white);

//    QPainter painter(&img);
//    painter.setPen(QPen(Qt::blue));
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(150,150),100,100);

//    img.save("D:\\2-Myspace\\QTProject\\img.png");



    //QPicture 绘图设备 可以记录和重现绘图指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);  //开始往pic上画
    painter.setPen(QPen(Qt::cyan));
    painter.drawEllipse(QPoint(150,150),100,100);
    painter.end();  //结束画画

    //保存到磁盘
    pic.save("D:\\2-Myspace\\QTProject\\pic.zt");

}


//绘图事件
void Widget::paintEvent(QPaintEvent *event)
{
//    QPainter painter(this);

//    //利用QImage 对像素进行修改
//    QImage img;
//    img.load(":/Image/Luffy.png");

//    //修改像素点
//    for(int i=80; i<120; i++)
//    {
//        for(int j=150; j<190; j++)
//        {
//            QRgb value = qRgb(255,0,0);
//            img.setPixel(i,j,value);
//        }
//    }

//    painter.drawImage(0,0,img);



    QPainter painter(this);
    //重现QPicture的绘图指令
    QPicture pic;
    pic.load("D:\\2-Myspace\\QTProject\\pic.zt");
    painter.drawPicture(0,0,pic);


}

Widget::~Widget()
{
    delete ui;
}

