#include <QApplication>
#include <QPixmap>
#include <QPainter>
#include <QDebug>


#define JAVASTYLE 0
#define STLSTYLE  1


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap p1,p2;
    p1.load("image.png");
    p2 = p1;  //p1和p2数据共享

    QPainter paint;
    paint.begin(&p2);  //从此，p2 与 p1 分道扬镳
    paint.drawText(0,50,"Hi");
    paint.end();


    return a.exec();
}
