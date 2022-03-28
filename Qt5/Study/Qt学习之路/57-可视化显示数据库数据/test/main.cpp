#include "sqldatabase.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QTableView>
#include <QHeaderView>
#include <QDebug>

enum ColumnIndex
{
    Column_ID = 0,
    Column_Name = 1,
    Column_Age = 2
};

//建立数据库连接
bool connect(const QString &dbName){

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);

    if(!db.open()){
        QMessageBox::critical(NULL, QObject::tr("Database Error"), db.lastError().text());
        return false;
    }

    qDebug() << "db:" << db.database();
    return true;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(connect("demo.db")){
        QSqlQuery query;

        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("student");
        model->setSort(Column_Name, Qt::AscendingOrder);
        model->setHeaderData(Column_Name, Qt::Horizontal, "Name");
        model->setHeaderData(Column_Age, Qt::Horizontal, "Age");
        model->select();


        QTableView *view = new QTableView;
        view->setModel(model);
        view->setSelectionMode(QAbstractItemView::SingleSelection);
        view->setSelectionBehavior(QAbstractItemView::SelectRows);
        view->setColumnHidden(Column_ID, true);

        //每列宽度适配其内容
        view->resizeColumnsToContents();
        //禁用编辑功能
        view->setEditTriggers(QAbstractItemView::NoEditTriggers);
        //设置最后一列充满整个窗口
        QHeaderView *header = view->horizontalHeader();
        header->setStretchLastSection(true);

        view->show();


        //整表查询
        query.exec("SELECT name, age FROM student");
        while(query.next()){
            QString name = query.value(0).toString();
            int age = query.value(1).toInt();
            qDebug() << name << ": " << age;
        }
    }

    return a.exec();
}
