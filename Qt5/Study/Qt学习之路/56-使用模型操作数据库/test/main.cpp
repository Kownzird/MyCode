#include "sqldatabase.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>

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
        if (!query.exec("CREATE TABLE student ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "name VARCHAR,"
                        "age INT)")) {
                QMessageBox::critical(0, QObject::tr("Database Error"),
                        query.lastError().text());
                return 1;
        }
        query.finish();

        query.prepare("INSERT INTO student (name,age) VALUES (?,?)");
        QVariantList names;
        names << "Tom" << "Jack" << "Jane" << "Jerry";
        query.addBindValue(names);
        QVariantList ages;
        ages << 20 << 23 << 22 << 25;
        query.addBindValue(ages);
        if(!query.execBatch()){
            QMessageBox::critical(NULL, QObject::tr("Database Error"), query.lastError().text());
        }
        query.finish();



        QSqlTableModel model;

        //过滤查询
        //设置所需要操作的表格
        model.setTable("student");
        //添加过滤器
        model.setFilter("age > 20 and age < 25");
        if(model.select()){
            for(int i=0; i<model.rowCount(); i++){
                QSqlRecord record = model.record(i);
                QString name = record.value("name").toString();
                int age = record.value("age").toInt();
                qDebug() << name << ": " << age;
            }
        }

        //插入操作
        model.setTable("student");
        int row = 0;
        model.insertRows(row, 1);
        model.setData(model.index(row, 1), "Cheng");
        model.setData(model.index(row, 2), 24);
        model.submitAll();


        //修改操作
        model.setTable("student");
        model.setFilter("age = 25");
        if(model.select()){
            if(model.rowCount() == 1){
                QSqlRecord record = model.record(0);
                record.setValue("age", 26);
                model.setRecord(0, record);
                model.submitAll();
            }
        }
//        if(model.select()){
//            if(model.rowCount() == 1){
//                model.setData(model.index(0, 2), 26);
//                model.submitAll();
//            }
//        }

        //删除操作
        model.setTable("student");
        model.setFilter("age = 25");
        if(model.select()){
            if(model.rowCount() == 1){
                model.removeRows(0, 1);
                model.submitAll();
            }
        }

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
