#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "datatablewidget.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

private:
    DataTableWidget *topTable;
    DataTableWidget *bottomTable;

};

#endif // MAINWINDOW_H
