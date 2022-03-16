#include "widget.h"


Widget::Widget(QWidget *parent) : QWidget(parent)
{
    ProjectListWidget *p1 = new ProjectListWidget;
    ProjectListWidget *p2 = new ProjectListWidget;

    p1->insertItem(0, tr("P1 Row-1"));
    p1->insertItem(1, tr("P1 Row-2"));
    p1->insertItem(2, tr("P1 Row-3"));

    p2->insertItem(0, tr("P2 Row-1"));
    p2->insertItem(1, tr("P2 Row-2"));
    p2->insertItem(2, tr("P2 Row-3"));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(p1);
    layout->addWidget(p2);

    setLayout(layout);
}
