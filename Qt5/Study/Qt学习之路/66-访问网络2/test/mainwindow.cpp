#include "mainwindow.h"
#include "networker.h"

class MainWindow::Private
{
public:
    Private(){
        netWorker = NetWorker::instance();
    }

    void fetchWeather(const QString &cityName) const{
        netWorker->get(QString(
            "https://api.openweathermap.org/data/2.5/weather?q=%1,cn&mode=json&units=metric&lang=zh_cn&"
            "APPID=261df16dd00c9ce47eaa0e3540409eb5").arg(cityName));
    }

    NetWorker *netWorker;
};


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

}
