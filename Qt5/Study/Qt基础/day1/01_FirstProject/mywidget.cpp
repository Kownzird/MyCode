#include "mywidget.h"
#include <QPushButton> //按钮控件头文件
#include "mypushbutton.h"
#include <QDebug>

//命名规范
//类名 首字母大写，单词和单词之间首字母大写
//函数名 变量名称 首字母小写，单词和单词之间首字母大写

//快捷键
//注释 ctrl + /
//运行 ctrl + r
//编译 ctrl + b
//字体缩放 ctrl + 鼠标滚轮
//查找 ctrl + f
//整行移动 ctrl + shift + ↑ 或者 ↓
//帮助文档 F1打开 Esc关闭
//自动对齐 ctrl + i
//同名之间的.h和.cpp切换  F4
//帮助文档 第一种方式 F1  第二种方式 左侧按钮  第三种方式 Qt5.9.9\5.9.9\mingw53_32\bin\assistant.exe

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个按钮
    QPushButton * btn = new QPushButton;
    //btn->show(); //show以顶层方式弹出窗口控件

    //让btn对象，依赖在myWidget窗口中
    btn->setParent(this);

    //显示文本
    btn->setText("第一个按钮");

    //创建第二个按钮，按照控件的大小创建窗口
    QPushButton * btn2 = new QPushButton("第二个按钮",this);

    //移动btn2按钮
    btn2->move(100,0);

    //按钮重新制定大小
    btn2->resize(100,50);


    //重置窗口大小
    resize(600,400);

    //设置固定窗口大小
    setFixedSize(600,400);

    //设置窗口标题
    setWindowTitle("第一个窗口");


    //创建一个自己的按钮对象
    myPushButton * myBtn = new myPushButton;
    myBtn->setParent(this);  //设置到对象树中
    myBtn->setText("我自己的按钮");
    myBtn->move(200,0);

    // 需求，点击我自己的按钮，关闭窗口
    //connect()
    //参数1 信号发送者
    //参数2 发送的信号(函数的地址)
    //参数3 信号接收者
    //参数4 处理的槽函数
    connect(myBtn,&QPushButton::clicked,this,&myWidget::close);



}

myWidget::~myWidget()
{
    qDebug() << "myWidget对象析构";
}

