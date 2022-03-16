#ifndef MYLISTVIEW_H
#define MYLISTVIEW_H

#include <QWidget>

class QStringListModel;
class QListView;

class MyListView : public QWidget
{
    Q_OBJECT

public:
    MyListView(QWidget *parent = nullptr);
    ~MyListView();

private slots:
    void showModel();

private:
    QStringListModel *model;
    QListView *listView;
};
#endif // MYLISTVIEW_H
