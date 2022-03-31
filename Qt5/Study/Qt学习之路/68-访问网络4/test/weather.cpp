#include "weather.h"
#include <QDebug>
#include <QDateTime>

//WeatherDetail 内部类
class WeatherDetail::Private
{
public:
    QString desc;
    QString icon;
};

//WeatherInfo 内部类
class WeatherInfo::Private
{
public:
    QString cityName;
    quint32 id;
    QDateTime dateTime;
    float temperature;
    float humidity;
    float pressure;
    QList<WeatherDetail*> details;
};


WeatherDetail::WeatherDetail():d(new WeatherDetail::Private){}
WeatherDetail::~WeatherDetail(){
    delete d;
    d = 0;
}
WeatherInfo::WeatherInfo():d(new WeatherInfo::Private){}
WeatherInfo::~WeatherInfo(){
    delete d;
    d = 0;
}

//WeatherDetail函数实现
QString WeatherDetail::desc() const{
    return d->desc;
}

void WeatherDetail::setDesc(const QString &desc){
    d->desc = desc;
}

QString WeatherDetail::icon() const{
    return d->icon;
}

void WeatherDetail::setIcon(const QString &icon){
    d->icon = icon;
}


//WeatherInfo函数实现
QString WeatherInfo::cityName() const{
    return d->cityName;
}

void WeatherInfo::setCityName(const QString &cityName){
    d->cityName = cityName;
}

quint32 WeatherInfo::id() const{
    return d->id;
}

void WeatherInfo::setId(quint32 id){
    d->id = id;
}

QDateTime WeatherInfo::dateTime() const{
    return d->dateTime;
}

void WeatherInfo::setDateTime(const QDateTime &dateTime){
    d->dateTime = dateTime;
}

float WeatherInfo::temperature() const{
    return d->temperature;
}

void WeatherInfo::setTemperature(float temperature){
    d->temperature = temperature;
}

float WeatherInfo::humidity() const{
    return d->humidity;
}

void WeatherInfo::setHumidity(float humidity){
    d->humidity = humidity;
}

float WeatherInfo::pressure() const{
    return d->pressure;
}

void WeatherInfo::setPressure(float pressure){
    d->pressure = pressure;
}

QList<WeatherDetail *> WeatherInfo::details() const{
    return d->details;
}

void WeatherInfo::setDetails(const QList<WeatherDetail*> details){
    d->details = details;
}



//Debug Function
QDebug operator << (QDebug dbg, const WeatherDetail &w){
    dbg.nospace() << "("
                  << "Description: " << w.desc() << "; "
                  << "Icon: " << w.icon()
                  << ")";
}

QDebug operator << (QDebug dbg, const WeatherInfo &w){
    dbg.nospace() << "("
                  << "id: " << w.id() <<"; "
                  << "City name: " << w.cityName() << "; "
                  << "Date time: " << w.dateTime().toString(Qt::DefaultLocaleLongDate) << "; "
                  << "Temperature: " << w.temperature() << "; "
                  << "Presure: " << w.pressure() << "; "
                  << "Humidity: " << w.humidity() << "; "
                  << "Details: [";
    foreach(WeatherDetail *detail, w.details()){
        dbg.nospace() << "( Description: " << detail->desc() << ", "
                      << "Icon: " << detail->icon() << "), ";
    }

    dbg.nospace() << "])";
    return dbg.nospace();

}
