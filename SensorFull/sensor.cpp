#include "sensor.h"
#include <QRandomGenerator>
#include <QDebug>
#include <QVector>
#include <unistd.h>
#include <QStringBuilder>



Sensor::Sensor(QObject *parent)
    : QObject{parent}
{}


void Sensor::GetLengs(int max_lengs, int sensor_counter){

    Sensor::GetLengs(max_lengs, sensor_counter);

}

void Sensor::GenerateSignal(int max_lengs, int sensor_counter){
    qDebug()<<"Gen Signal";
    int value;
    int counter = 0;
    qDebug()<<sensor_counter;



    for(int No = 1; No < sensor_counter + 1; No++){
    for (auto num = 0; num < max_lengs; num++){
        value = QRandomGenerator::global()->bounded(INT_MAX);

        qDebug()<<"Sensor "<< No <<++counter <<value<< "       ";

        emit CreateSignal(value, max_lengs, No, num, sensor_counter);

        usleep(5000);
    }
    }

}


