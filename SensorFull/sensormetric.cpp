#include "sensormetric.h"
#include "analyser.h"
#include "loger.h"
#include "QDebug"
#include <QString>
#include <QStringBuilder>
#include <QDate>
#include <QTime>
#include <QMap>



SensorMetric::SensorMetric(QObject *parent)
    : QObject{parent}
{}



void SensorMetric:: Target(int value, int max_lengs, int No, int num, int sensor_counter){




    if(!Sensors.contains("Sensor" % QString::number(No))){
        Sensors.insert("Sensor" % QString::number(No), QVector<int>());
    }

    QVector<int>& vector =  Sensors["Sensor" % QString::number(No)];
    vector.push_back(value);

    if(!Sensors_cahnged.contains("Sensor" % QString::number(No))){
        Sensors_cahnged.insert("Sensor" % QString::number(No), QVector<QString>());
    }

    QVector<QString>& vector_changed = Sensors_cahnged["Sensor" % QString::number(No)];

    QString date1 = QDate::currentDate(). toString("yyyy-MM-dd") % " | " % QTime::currentTime().toString("HH:mm:ss.zzz") % " | Sensor " % QString::number(No) % " | Value = " % QString::number(value) ;
    vector_changed.push_back(date1);




    if((num + 1)  == max_lengs && No  == sensor_counter){
        qDebug()<<sensor_counter;

    Analyser * analyser = new Analyser();
    Loger * loger = new Loger();
    connect(this, &SensorMetric::onAnalyser, analyser, &Analyser::getData);
    connect(this, &SensorMetric::onLoger, loger, &Loger::getLoger);
    emit this -> onAnalyser(Sensors, sensor_counter);
    emit this -> onLoger(Sensors_cahnged, sensor_counter, max_lengs);

    }
}
