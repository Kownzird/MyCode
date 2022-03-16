#include "widget.h"
#include <QLabel>
#include <QListWidget>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    label = new QLabel(this);
    label->setText("Chorm");
    label->setFixedWidth(100);
    label->setFixedHeight(200);

    listWidget = new QListWidget(this);

    //三种向列表添加列表项的方法
    new QListWidgetItem(QIcon(":/image/Chorm.png"), tr("Chorm"), listWidget);
    new QListWidgetItem(QIcon(":/image/Firefox.png"), tr("Firefox"), listWidget);

    listWidget->addItem(new QListWidgetItem(QIcon(":/image/IE.png"), tr("IE")));
    listWidget->addItem(new QListWidgetItem(QIcon(":/image/Maxthon.png"), tr("Maxthon")));
    listWidget->addItem(new QListWidgetItem(QIcon(":/image/Netscape.png"), tr("Netscape")));
    listWidget->addItem(new QListWidgetItem(QIcon(":/image/safari.png"), tr("safari")));

    QListWidgetItem *newItem = new QListWidgetItem;
    newItem->setIcon(QIcon(":/image/opera.png"));
    newItem->setText("opera");
    listWidget->insertItem(3, newItem);

    //图标显示模式
//    listWidget->setViewMode(QListView::IconMode);

    //布局
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(listWidget);

    setLayout(layout);

    connect(listWidget, &QListWidget::currentTextChanged, label, &QLabel::setText);


}

Widget::~Widget()
{
}

