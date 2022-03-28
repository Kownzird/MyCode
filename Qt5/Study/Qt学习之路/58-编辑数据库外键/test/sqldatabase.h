#ifndef SQLDATABASE_H
#define SQLDATABASE_H

#include <QWidget>

enum ColumnIndex
{
    Column_ID = 0,
    Column_Name = 1,
    Column_Age = 2,
    Column_City = 3
};

class QHeaderView;
class QTableView;
class QSqlTableModel;
class QSqlRelationalTableModel;
class SqlDatabase : public QWidget
{
    Q_OBJECT

public:
    SqlDatabase(QWidget *parent = nullptr);
    ~SqlDatabase();

    bool connect(const QString &dbName);

protected:
    void resizeEvent(QResizeEvent *event);

private:
    QHeaderView *header;
    QTableView *view;
    QSqlTableModel *model;
    QSqlRelationalTableModel *rmodel;
};
#endif // SQLDATABASE_H
