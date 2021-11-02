#include "mainscene.h"
#include "ui_mainscene.h"
#include "mypushbutton.h"
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QSound>  //多媒体模块下的音效头文件

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //配置主场景

    //设置固定大小
    setFixedSize(390,588);

    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    setWindowTitle("翻金币主场景");

    //退出按钮实现
    connect(ui->actionquit, &QAction::triggered,[=](){
        this->close();
    });

    //准备开始按钮的音效
    QSound* startSound = new QSound(":/res/TapButtonSound.wav",this);
//    startSound->setLoops(10);  //设置10次循环播放，-1为无限循环
//    startSound->play();

    //开始按钮
    MyPushButton* startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width() * 0.5 - startBtn->width() * 0.5, this->height() * 0.7);

    //实例化选择关卡场景
    chooseScene = new ChooseLevelScene;

    //监听选择关卡的返回按钮信号
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack, this, [=](){
        this->setGeometry(chooseScene->geometry());
        chooseScene->hide();  //将选择关卡场景 隐藏掉
        this->show(); //重新选择主场景
    });

    connect(startBtn, &QPushButton::clicked, [=](){
//        qDebug() << "点击了开始";
        //播放开始按钮音效
        startSound->play();

        //做弹起特效
        startBtn->zoom1();
        startBtn->zoom2();

        //延时进入到选择关卡场景中
        QTimer::singleShot(500,this,[=](){
            //设置chooseScene场景的位置
            chooseScene->setGeometry(this->geometry());

            //自身隐藏
            this->hide();
            chooseScene->show();
        });


    });


}


void MainScene::paintEvent(QPaintEvent *ev)
{

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");

    //将图片拉伸成屏幕的宽高
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画背景板上图标
    pix.load(":/res/Title.png");

    //缩放图标
    pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);

    painter.drawPixmap(10,30,pix);
}


MainScene::~MainScene()
{
    delete ui;
}

