#ifndef WEATHERDETAIL_H
#define WEATHERDETAIL_H

#include <QObject>

class QDebug;

class WeatherDetail
{
public:
    WeatherDetail();
    ~WeatherDetail();

    QString desc() const;
    void setDesc(const QString &desc);

    QString icon() const;
    void setIcon(const QString &icon);

private:
    class Private;
    friend class Private;
    Private *d;
};



class WeatherInfo
{
public:
    WeatherInfo();
    ~WeatherInfo();

    QString cityName() const;
    void setCityName(const QString &cityName);

    quint32 id() const;
    void setId(quint32 id);

    QDateTime dateTime() const;
    void setDateTime(const QDateTime &dateTime);

    float temperature() const;
    void setTemperature(float temperature);

    float humidity() const;
    void setHumidity(float humidity);

    float pressure() const;
    void setPressure(float pressure);

    QList<WeatherDetail *> details() const;
    void setDetails(const QList<WeatherDetail*> details);

private:
    class Private;
    friend class Private;
    Private *d;
};

QDebug operator << (QDebug dbg, const WeatherDetail &w);
QDebug operator << (QDebug dbg, const WeatherInfo &w);

#endif // WEATHERDETAIL_H
