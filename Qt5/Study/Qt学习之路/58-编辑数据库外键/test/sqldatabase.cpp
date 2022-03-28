#include "sqldatabase.h"

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QTableView>
#include <QHeaderView>
#include <QDebug>


SqlDatabase::SqlDatabase(QWidget *parent)
    : QWidget(parent)
{
    //创建数据库表
    if(connect("demo.db")){
        QSqlQuery query;
        if(!query.exec("CREATE TABLE city ("
                       "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                       "name VARCHAR)")){
            QMessageBox::critical(NULL, "Database Error", query.lastError().text());
        }
        query.exec("INSERT INTO city (name) VALUES ('Beijing')");
        query.exec("INSERT INTO city (name) VALUES ('Shanghai')");
        query.exec("INSERT INTO city (name) VALUES ('Nanjing')");
        query.exec("INSERT INTO city (name) VALUES ('Tianjin')");
        query.exec("INSERT INTO city (name) VALUES ('Wuhan')");
        query.exec("INSERT INTO city (name) VALUES ('Hangzhou')");
        query.exec("INSERT INTO city (name) VALUES ('Suzhou')");
        query.exec("INSERT INTO city (name) VALUES ('Guangzhou')");

        if(!query.exec("CREATE TABLE student ("
                       "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                       "name VARCHAR,"
                       "age INTEGER,"
                       "address INTEGER,"
                       "FOREIGN KEY(address) REFERENCES city(id))")){
            QMessageBox::critical(NULL, "Database Error", query.lastError().text());
        }
        query.exec("PRAGMA foreign_keys = ON");
        query.exec("INSERT INTO student (name, age, address) VALUES ('Tom', 20, 2)");
        query.exec("INSERT INTO student (name, age, address) VALUES ('Jack', 23, 1)");
        query.exec("INSERT INTO student (name, age, address) VALUES ('Jane', 22, 4)");
        query.exec("INSERT INTO student (name, age, address) VALUES ('Jerry', 25, 5)");

        query.exec("SELECT name,age,address FROM student;");
        while (query.next()) {
            QString stuName = query.value(0).toString();
            int stuAge = query.value(1).toInt();
            int stuAddr = query.value(2).toInt();
            qDebug() << "name:" << stuName << " age:" << stuAge << " addr:" << stuAddr;
        }
    }



    if(connect("demo.db")){
        //仅列出保存的外键
//        model = new QSqlTableModel(this);
//        model->setTable("student");
//        model->setSort(Column_Name, Qt::AscendingOrder);
//        model->setHeaderData(Column_Name, Qt::Horizontal, "Name");
//        model->setHeaderData(Column_Age, Qt::Horizontal, "Age");
//        model->setHeaderData(Column_City, Qt::Horizontal, "City");
//        model->select();

//        view = new QTableView(this);
//        view->setModel(model);
//        view->setSelectionMode(QAbstractItemView::SingleSelection);
//        view->setSelectionBehavior(QAbstractItemView::SelectRows);
//        view->setEditTriggers(QAbstractItemView::NoEditTriggers);
//        view->resizeColumnsToContents();

//        header = view->horizontalHeader();
//        header->setStretchLastSection(true);

        //带有外键支持
        rmodel = new QSqlRelationalTableModel(this);
        rmodel->setTable("student");
        rmodel->setSort(Column_Name, Qt::AscendingOrder);
        rmodel->setHeaderData(Column_Name, Qt::Horizontal, "Name");
        rmodel->setHeaderData(Column_Age, Qt::Horizontal, "Age");
        rmodel->setHeaderData(Column_City, Qt::Horizontal, "City");
        rmodel->setRelation(Column_City, QSqlRelation("city", "id", "name"));
        rmodel->select();

        view = new QTableView(this);
        view->setModel(rmodel);
        view->setSelectionMode(QAbstractItemView::SingleSelection);
        view->setSelectionBehavior(QAbstractItemView::SelectRows);
        view->setEditTriggers(QAbstractItemView::NoEditTriggers);
        view->resizeColumnsToContents();

        header = view->horizontalHeader();
        header->setStretchLastSection(true);

        view->show();
    }
}

SqlDatabase::~SqlDatabase()
{
}

//建立数据库连接
bool SqlDatabase::connect(const QString &dbName){

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);

    if(!db.open()){
        QMessageBox::critical(NULL, QObject::tr("Database Error"), db.lastError().text());
        return false;
    }

    qDebug() << "db:" << db.database();
    return true;
}

void SqlDatabase::resizeEvent(QResizeEvent *event){

    view->resize(this->width(), this->height());
    header->setSectionResizeMode(QHeaderView::Stretch);

//    header->setSectionResizeMode(Column_Name,QHeaderView::ResizeToContents);
//    header->setSectionResizeMode(Column_Age,QHeaderView::ResizeToContents);
//    header->setSectionResizeMode(Column_City,QHeaderView::ResizeToContents);
}
