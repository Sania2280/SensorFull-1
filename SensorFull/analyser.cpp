#include "analyser.h"
#include <QDebug>
#include <QString>
#include <QStringBuilder>
#include <QMap>

#include "list.h"


// #include <algorithm>

Analyser::Analyser(QObject *parent)
    : QObject{parent}
{}

void Analyser::getData(QMap<QString, QVector<int>> Sensor, int sensor_counter){

    qDebug()<<"Counters "<< sensor_counter;
    for(int i = 1, p = 0; i < sensor_counter + 1; i++, p++){
        qDebug()<<"i "<< i;

        QString KEY = "Sensor" % QString::number(i);
        QVector <int>& vector = Sensor[KEY];


        if (!Sensor.contains(KEY)) {
            qWarning() << "Key" << KEY << "does not exist in the map!";
            return;
        }
        qDebug()<<"Size"<<vector.size() ;
        qDebug()<<vector.capacity();



        MAX.push_back(vector[0]);
        std::for_each(vector.begin(), vector.end(), [&](int a){qDebug()<<a;});

        std::for_each(vector.begin(), vector.end(), [&](int a){if (MAX.last() < a) {MAX.push_back(a);}});
        qDebug()<<"Max"<< p + 1 << " =" << MAX.last();



        MIN.push_back(vector[0]);

        std::for_each(vector.begin(), vector.end(),[&](int a){if (a < MIN.last()) MIN.push_back(a);});
        qDebug()<<"Min"<< i << " =" << MIN.last();




    std::sort(vector.begin(), vector.end(), [](int a, int b){return a < b;});

        // for(auto m:vector)qDebug()<<m;

    AVERAGE.push_back(0);
        for(auto p = 0; p < vector.size();p++){AVERAGE.last() += static_cast<__int64> (vector[p]);}

        AVERAGE.last() = AVERAGE.last() / vector.size();
    qDebug()<<"Average"<< i << " =" << AVERAGE.last();


     size_t size1 = vector.size();

    MEDIAN.push_back(0);

    if (size1 % 2 == 1) {
        // Непарна кількість елементів
        MEDIAN.last() = static_cast<double>(vector[size1 / 2]);
    } else {
        // Парна кількість елементів
        MEDIAN.last() = (static_cast<double>(vector[(size1 / 2) - 1]) + static_cast<double>(vector[size1 / 2])) / 2.0;
    }
    qDebug()<<"Median" << i << "=" << MEDIAN.last();


    }

    List * list = new List();
    QObject::connect(this, &Analyser::onList,list, &List::getFromAnaliser );

    emit this ->onList(MAX, MIN, AVERAGE, MEDIAN, sensor_counter);
}
