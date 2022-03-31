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
#include <QMap>
#include <QEventLoop>
#include <QDebug>

class MainWindow::Private
{
public:
    Private(MainWindow *q) : mainWindow(q){
        netWorker = NetWorker::instance();
    }

    //当QNetworkAccessManager发出请求之后，我们进入一个新的事件循环，将操作进行阻塞
    //防止连续访问网络，第一次放回结果较慢，导致第二次结果比第一次先到，而后再次刷新显示第一次结果
    void fetchWeather(const QString &cityName){
        QEventLoop eventLoop;
        connect(netWorker, &NetWorker::finished, &eventLoop, &QEventLoop::quit);


        QNetworkReply *reply = netWorker->get(QString(
            "https://api.openweathermap.org/data/2.5/weather?q=%1,cn&mode=json&units=metric&lang=zh_cn&"
            "APPID=261df16dd00c9ce47eaa0e3540409eb5").arg(cityName));
        replyMap.insert(reply, FetchWeatherInfo);

        //网络访问为异步操作
        qDebug() << "eventLoop exec";
        eventLoop.exec();
    }

    void fetchIcon(const QString &iconName){
        QEventLoop eventLoop;
        connect(netWorker, &NetWorker::finished, &eventLoop, &QEventLoop::quit);

        QNetworkReply *reply = netWorker->get(QString("https://openweathermap.org/img/w/%1.png").arg(iconName));
        replyMap.insert(reply, FetchWeatherIcon);

        eventLoop.exec();
    }

    NetWorker *netWorker;
    MainWindow *mainWindow;
    QMap<QNetworkReply *, RemoteRequest> replyMap;
};

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), d(new MainWindow::Private(this))
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
    QHBoxLayout *weatherDetailLayout = new QHBoxLayout;
    weatherDetailLayout->addWidget(new QLabel(this)); //description
    weatherDetailLayout->addWidget(new QLabel(this)); //icon
    weatherLayout->addLayout(weatherDetailLayout);

    QWidget *mainWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);
    mainLayout->addLayout(cityListLayout);
    mainLayout->addLayout(weatherLayout);
    setCentralWidget(mainWidget);
    resize(320,120);
    setWindowTitle(tr("Weather"));


    connect(d->netWorker, &NetWorker::finished, [=](QNetworkReply *reply){
        RemoteRequest request = d->replyMap.value(reply);
        switch (request) {
        case FetchWeatherInfo:
        {
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

                        //获取description Label位置
                        QLabel *descLabel = (QLabel *)weatherDetailLayout->itemAt(0)->widget();
                        descLabel->setText(detail->desc());

                        d->fetchIcon(detail->icon());

                    }
                    weather.setDetails(details);

                    qDebug() << weather;

                    cityNameLabel->setText(weather.cityName());
                    dateTimeLabel->setText(weather.dateTime().toString(Qt::DefaultLocaleLongDate));
                    temperatureLabel->setText(QString("%1°C").arg(weather.temperature()));
                }
            }else{
                QMessageBox::critical(this, tr("Error"), error.errorString());
            }
            break;
        }
        case FetchWeatherIcon:
        {
            //根据QHBoxLayout的itemAt()函数找到先前添加的用于显示图片的 label，
            //然后读取 reply 的数据值，以二进制的形式加载图片
            QHBoxLayout *weatherDetailLayout = (QHBoxLayout *)(weatherLayout->itemAt(3)->layout()); //两种方式定位控件位置
            QLabel *iconLabel = (QLabel *)(weatherDetailLayout->itemAt(1)->widget());
            QPixmap pixmap;
            pixmap.loadFromData(reply->readAll());
            iconLabel->setPixmap(pixmap);
            break;
        }
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
