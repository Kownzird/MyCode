#include "widget.h"
#include <QTableWidget>
#include <QItemSelection>
#include <QItemSelectionModel>
#include <QHBoxLayout>
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    tableWidget = new QTableWidget(8, 4);
    selectionModel = tableWidget->selectionModel();//获得QTableView的选择模型



    //设置选取
    QModelIndex topLeft = tableWidget->model()->index(0, 0, QModelIndex());
    QModelIndex bottomRight = tableWidget->model()->index(5, 2, QModelIndex());
    QItemSelection selection(topLeft, bottomRight);
    selectionModel->select(selection, QItemSelectionModel::Select);

    //toggle对前面设置进一步操作，取反
    QItemSelection toggleSelection;
    topLeft = tableWidget->model()->index(2, 1, QModelIndex());
    bottomRight = tableWidget->model()->index(7, 3, QModelIndex());
    toggleSelection.select(topLeft, bottomRight);
    selectionModel->select(toggleSelection, QItemSelectionModel::Toggle);

    //设置行与列
    QItemSelection columnSelection;
    topLeft = tableWidget->model()->index(0, 1, QModelIndex());
    bottomRight = tableWidget->model()->index(0, 2, QModelIndex());
    columnSelection.select(topLeft, bottomRight);
    selectionModel->select(columnSelection, QItemSelectionModel::Select | QItemSelectionModel::Columns);

    QItemSelection rowSelection;
    topLeft = tableWidget->model()->index(0, 0, QModelIndex());
    bottomRight = tableWidget->model()->index(1, 0, QModelIndex());
    rowSelection.select(topLeft, bottomRight);
    selectionModel->select(rowSelection, QItemSelectionModel::Select | QItemSelectionModel::Rows | QItemSelectionModel::Clear);

    //全选
    topLeft = tableWidget->model()->index(0, 0, QModelIndex());
    bottomRight = tableWidget->model()->index(tableWidget->model()->rowCount(QModelIndex())-1,
                                              tableWidget->model()->columnCount(QModelIndex())-1, QModelIndex());
    QItemSelection allSelection(topLeft, bottomRight);
    selectionModel->select(allSelection, QItemSelectionModel::Select);

    //获取选区
    QModelIndexList indexs = selectionModel->selectedIndexes();
    QModelIndex index;
    foreach(index, indexs){
        QString text = QString("(%1,%2)").arg(index.row()).arg(index.column());
        tableWidget->model()->setData(index, text);
    }

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(tableWidget);
    setLayout(layout);

    //在选择发生更改时，选择模型会发出selectionChanged()信号。
    //信号有两个参数：第一个是新选择的项目，第二个是刚刚被取消选择的项目
    connect(selectionModel, &QItemSelectionModel::selectionChanged, this, &Widget::updateSelection);

    //currentChanged()，可以追踪当前有焦点的项
    //信号有两个参数，第一个是新的当前项，第二个是上一个当前项
    connect(selectionModel, &QItemSelectionModel::currentChanged, this, &Widget::changeCurrent);
}

Widget::~Widget()
{
}

void Widget::updateSelection(const QItemSelection& selected, const QItemSelection& deselected)
{
    QModelIndex index;
    QModelIndexList items = selected.indexes();

    foreach(index, items){
        QString text = QString("(%1,%2)").arg(index.row()).arg(index.column());
        tableWidget->model()->setData(index, text);
    }

    items = deselected.indexes();
    foreach(index, items){
        tableWidget->model()->setData(index, "");
    }
}


void Widget::changeCurrent(const QModelIndex& current, const QModelIndex& previous)
{
    qDebug() << tr("Move from (%1,%2) to (%3,%4)").arg(previous.row()).arg(previous.column()).arg(current.row()).arg(current.column());
}
