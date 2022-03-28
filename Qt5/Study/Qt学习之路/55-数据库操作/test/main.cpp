#include "sqldatabase.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

//建立数据库连接
bool connect(const QString &dbName){
    //创建了一个QSqlDatabase实例
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //用于区分数据库连接的名字是QString("conn%1").arg(dbName)，而不是 "QSQLITE"
    //如果不指定，系统会给出一个默认的名字
    //此设计可以为一个数据库建立多个连接
    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE", QString("con%1").arg(dbName));

//    db.setUserName("root");
//    db.setPassword("123456");

//    db.setHostName("host");
//    db.setDatabaseName("dbname");
//    db.setUserName("username");
//    db.setPassword("password");
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

    //系统中所有可用的数据库驱动的名字列表
    QStringList sqlDriversList = QSqlDatabase::drivers();
    qDebug() << "sqlDriversList:" << sqlDriversList;

    //创建数据库表 student
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
    }

    //往数据库表student插入和读取数据
    //ODBC ?占位符
    //Oracle 风格:
    //query.prepare("INSERT INTO student (name, age) VALUES (:name, :age)");
    //query.bindValue(":name", names);
    //query.bindValue(":age", ages);
    if(connect("demo.db")){
        QSqlQuery query;

        //对这条 SQL 语句进行预处理，问号 ? 相当于占位符
        query.prepare("INSERT INTO student (name,age) VALUES (?,?)");

        //使用一个字符串列表 names 替换掉第一个问号的位置
        //一个整型列表 ages 替换掉第二个问号的位置
        //QSqlQuery::addBindValue() 将实际数据绑定到这个预处理的 SQL 语句上
        //QSqlQuery::execBatch()批量执行 SQL
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

        query.exec("SELECT name, age FROM student");
        while(query.next()){
            QString name = query.value(0).toString();
            int age = query.value(1).toInt();
            qDebug() << name << ": " << age;

        }
    }else{
        return 1;
    }

    return a.exec();
}
