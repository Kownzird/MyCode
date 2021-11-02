#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QDebug>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //重置窗口大小
    resize(600,400);

    //菜单栏创建,最多只能有一个
    QMenuBar* bar = menuBar();

    //将菜单栏放入到窗口中
    setMenuBar(bar);

    //创建菜单
    QMenu* fileMenu = bar->addMenu("文件");
    QMenu* editMenu = bar->addMenu("编辑");

    //创建菜单项
    QAction* newAction = fileMenu->addAction("新建");
    //添加分隔线
    fileMenu->addSeparator();
    QAction* openAction = fileMenu->addAction("打开");

    QAction* undoAction = editMenu->addAction("撤销");
    QAction* cutAction = editMenu->addAction("剪切");
    QAction* copyAction = editMenu->addAction("复制");
    QAction* pasteAction = editMenu->addAction("粘贴");




    //工具栏，可以有多个
    QToolBar* toolbar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,toolbar);

    //后期设置，只允许左右停靠
    toolbar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);

    //设置浮动
    toolbar->setFloatable(true);

    //设置移动 （总开关）
    toolbar->setMovable(false);

    //工具栏中可以设置内容
    toolbar->addAction(newAction);
    //添加分割线
    toolbar->addSeparator();
    toolbar->addAction(openAction);

    //工具栏中添加控件
    QPushButton* btn = new QPushButton("aa",this);
    toolbar->addWidget(btn);




    //状态栏，最多只有一个
    QStatusBar* stbar = statusBar();

    //设置到窗口中
    setStatusBar(stbar);

    //放标签控件
    QLabel* label = new QLabel("提示信息",this);
    stbar->addWidget(label);

    QLabel* label2 = new QLabel("右侧提示信息",this);
    stbar->addPermanentWidget(label2);




    //铆接部件(浮动窗口)，可以有多个
    QDockWidget* dockWidget = new QDockWidget("浮动",this);
    addDockWidget(Qt::RightDockWidgetArea,dockWidget);

    //设置后期停靠区域，只允许左右
    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);



    //设置中心部件，只能一个
    QTextEdit* edit = new QTextEdit(this);
    setCentralWidget(edit);








}




MainWindow::~MainWindow()
{
}

