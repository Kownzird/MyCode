#include "weather.h"
#include <QDebug>
#include <QDateTime>

WeatherDetail::WeatherDetail()
{

}



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
