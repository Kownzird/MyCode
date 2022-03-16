#ifndef FILESYSTEMWIDGET_H
#define FILESYSTEMWIDGET_H

#include <QWidget>

class QFileSystemModel;
class QTreeView;

class FileSystemWidget : public QWidget
{
    Q_OBJECT

public:
    FileSystemWidget(QWidget *parent = nullptr);
    ~FileSystemWidget();

public slots:
    void mkdir();
    void remove();

private:
    QFileSystemModel *model;
    QTreeView *treeView;

};
#endif // FILESYSTEMWIDGET_H
