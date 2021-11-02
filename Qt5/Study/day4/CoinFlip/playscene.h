#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mycoin.h"

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
//    explicit PlayScene(QWidget *parent = nullptr);

    PlayScene(int levelNum);

    int levelIndex; //内部成员属性，记录所选关卡

    //重写paintEvent事件
    void paintEvent(QPaintEvent* ev);

    //二维数字，维护每个关卡的具体数据
    int gameArray[4][4];

    MyCoin* coinBtn[4][4];

    //是否胜利标志
    bool isWin;

signals:
    void chooseSceneBack();
};

#endif // PLAYSCENE_H
