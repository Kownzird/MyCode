#ifndef SQLDATABASE_H
#define SQLDATABASE_H

#include <QWidget>

class SqlDatabase : public QWidget
{
    Q_OBJECT

public:
    SqlDatabase(QWidget *parent = nullptr);
    ~SqlDatabase();
};
#endif // SQLDATABASE_H
