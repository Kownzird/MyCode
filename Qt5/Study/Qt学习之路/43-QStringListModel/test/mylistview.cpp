#include "mylistview.h"
#include <QStringListModel>
#include <QListView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>

MyListView::MyListView(QWidget *parent) : QWidget(parent){
    QStringList data;
    data << "Letter A" << "Letter B" << "Letter C";
    model = new QStringListModel(this);
    model->setStringList(data);

    listView = new QListView(this);
    listView->setModel(model);

    QPushButton *insertBtn = new QPushButton(tr("Insert"), this);
    connect(insertBtn, &QPushButton::clicked, this, &MyListView::insertData);
    QPushButton *delBtn = new QPushButton(tr("Delete"), this);
    connect(delBtn, &QPushButton::clicked, this, &MyListView::deleteData);
    QPushButton *showBtn = new QPushButton(tr("Show"), this);
    connect(showBtn, &QPushButton::clicked, this, &MyListView::showData);

    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addWidget(insertBtn);
    btnLayout->addWidget(delBtn);
    btnLayout->addWidget(showBtn);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(listView);
    mainLayout->addLayout(btnLayout);
    setLayout(mainLayout);


}

void MyListView::insertData(){
    bool isOK;

    QString text = QInputDialog::getText(this, "Insert", "Please input data:", QLineEdit::Normal,
                                         "You are inserting data", &isOK);
    if(isOK){
        int row = listView->currentIndex().row();  //listView->currentIndex()返回QModelIndex类型
        model->insertRows(row, 1); //插入一行空白行
        QModelIndex index = model->index(row); //获取改行QModelIndex类型
        model->setData(index, text);
        listView->setCurrentIndex(index); //把当前行设置为新插入的一行
        listView->edit(index); //使这一行可以被编辑


//        if (isOK) {
//            QModelIndex currIndex = listView->currentIndex();
//            model->insertRows(currIndex.row(), 1);
//            model->setData(currIndex, text);
//            listView->edit(currIndex);
//        }
    }

}

void MyListView::deleteData(){
    if(model->rowCount() > 1){
        model->removeRows(listView->currentIndex().row(), 1);
    }
}



void MyListView::showData(){
    QStringList data = model->stringList();
    QString str;
    foreach(QString s, data){
        str += s + "\n";
    }

    QMessageBox::information(this,"Data", str);
}
