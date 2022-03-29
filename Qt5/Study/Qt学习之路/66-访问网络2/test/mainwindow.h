#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);


private:
    class Private;
    friend class Private;
    Private *d;

};

#endif // MAINWINDOW_H
