#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

enum RemoteRequest {
    FetchWeatherInfo,
    FetchWeatherIcon
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    class Private;
    friend class Private;
    Private *d;

};

#endif // MAINWINDOW_H
