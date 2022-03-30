#include "mainwindow.h"
#include "networker.h"
#include "weather.h"

#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QDateTime>
#include <QMessageBox>
#include <QDebug>

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

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), d(new MainWindow::Private)
{
    QComboBox *cityList = new QComboBox(this);
    cityList->addItem(tr("Zhongshan"), QLatin1String("Zhongshan,cn"));
    cityList->addItem(tr("Zhuhai"), QLatin1String("Zhuhai,cn"));
    cityList->addItem(tr("Guangzhou"), QLatin1String("Guangzhou,cn"));
    cityList->addItem(tr("Beijing"), QLatin1String("Beijing,cn"));
    cityList->addItem(tr("Harbin"), QLatin1String("Harbin,cn"));
    QLabel *cityLabel = new QLabel(tr("City: "), this);
    QPushButton *refreshButton = new QPushButton(tr("refresh"), this);
    QHBoxLayout *cityListLayout = new QHBoxLayout;
    cityListLayout->addWidget(cityLabel);
    cityListLayout->addWidget(cityList);
    cityListLayout->addWidget(refreshButton);

    QVBoxLayout *weatherLayout = new QVBoxLayout;
    weatherLayout->setDirection(QBoxLayout::TopToBottom);
    QLabel *cityNameLabel = new QLabel(this);
    weatherLayout->addWidget(cityNameLabel);
    QLabel *dateTimeLabel = new QLabel(this);
    weatherLayout->addWidget(dateTimeLabel);
    QLabel *temperatureLabel = new QLabel(this);
    weatherLayout->addWidget(temperatureLabel);
    QLabel *descLabel = new QLabel(this);
    weatherLayout->addWidget(descLabel);

    QWidget *mainWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);
    mainLayout->addLayout(cityListLayout);
    mainLayout->addLayout(weatherLayout);
    setCentralWidget(mainWidget);
    resize(320,120);
    setWindowTitle(tr("Weather"));


    connect(d->netWorker, &NetWorker::finished, [=](QNetworkReply *reply){
        qDebug() << reply;
        QJsonParseError error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll(), &error);
        if(error.error == QJsonParseError::NoError){
            //&&的优先级高于||，因此先执行&&
            if(!(jsonDocument.isNull() || jsonDocument.isEmpty() && jsonDocument.isObject())){
                QVariantMap data = jsonDocument.toVariant().toMap();
                WeatherInfo weather;
                weather.setCityName(data[QLatin1String("name")].toString());
                QDateTime dateTime;
                dateTime.setTime_t(data[QLatin1String("dt")].toULongLong());
                weather.setDateTime(dateTime);

                QVariantMap main = data[QLatin1String("main")].toMap();
                weather.setTemperature(main[QLatin1String("temp")].toFloat());
                weather.setPressure(main[QLatin1String("pressure")].toFloat());
                weather.setHumidity(main[QLatin1String("humidity")].toFloat());

                qDebug() << main[QLatin1String("humidity")].toFloat();

                QVariantList detailList = data[QLatin1String("weather")].toList();
                QList<WeatherDetail*> details;
                foreach(QVariant w, detailList){
                    QVariantMap wm = w.toMap();
                    WeatherDetail *detail = new WeatherDetail;
                    detail->setDesc(wm[QLatin1String("description")].toString());
                    detail->setIcon(wm[QLatin1String("icon")].toString());
                    details.append(detail);
                }
                weather.setDetails(details);

                qDebug() << weather;

                cityNameLabel->setText(weather.cityName());
                dateTimeLabel->setText(weather.dateTime().toString(Qt::DefaultLocaleLongDate));
                temperatureLabel->setText(QString("%1°C").arg(weather.temperature()));
//                descLabel->setText(weather.details["description"]);

            }
        }else{
            QMessageBox::critical(this, tr("Error"), error.errorString());
        }
        reply->deleteLater();
    });

    //
    connect(refreshButton, &QPushButton::clicked, [=](){
        d->fetchWeather(cityList->itemData(cityList->currentIndex()).toString());
    });

}


MainWindow::~MainWindow(){
    delete d;
    d = 0;
}
