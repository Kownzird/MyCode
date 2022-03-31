#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QSharedMemory;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QSharedMemory *sharedMemory;
};
#endif // MAINWINDOW_H
