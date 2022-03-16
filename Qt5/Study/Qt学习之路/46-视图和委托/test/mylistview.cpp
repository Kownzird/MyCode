#include "mylistview.h"
#include "spinboxdelegate.h"
#include <QStringListModel>
#include <QListView>
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

MyListView::MyListView(QWidget *parent)
    : QWidget(parent)
{
    QStringList data;
    data << "0" << "1" << "2";
    model = new QStringListModel(this);
    model->setStringList(data);

    listView = new QListView(this);
    listView->setModel(model);

    QPushButton *showBtn = new QPushButton(tr("Show Model"), this);
    connect(showBtn, &QPushButton::clicked, this, &MyListView::showModel);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(showBtn);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(listView);
    layout->addLayout(buttonLayout);

    setLayout(layout);
    //new 操作符并不会真的创建编辑器实例。只有在真正需要时，Qt 才会生成一个编辑器实例
    listView->setItemDelegate(new SpinBoxDelegate(listView));
}

MyListView::~MyListView()
{
}

void MyListView::showModel()
{
    QStringList data = model->stringList();
    QString str;
    foreach(QString s, data){
        str += s;
    }
    QMessageBox::information(this, tr("Show Model"), str);
}

