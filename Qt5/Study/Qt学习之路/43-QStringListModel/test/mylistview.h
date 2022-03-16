#ifndef MYLISTVIEW_H
#define MYLISTVIEW_H

#include <QWidget>

class QStringListModel;
class QListView;

class MyListView : public QWidget
{
    Q_OBJECT
public:
    explicit MyListView(QWidget *parent = nullptr);

signals:

public slots:
    void insertData();
    void deleteData();
    void showData();

private:
    QStringListModel *model;
    QListView *listView;

};

#endif // MYLISTVIEW_H
