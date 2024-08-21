#include "loger.h"
#include <QFile>
#include <QTextStream>
#include <QStringBuilder>
#include <qdebug.h>

Loger::Loger(QObject *parent)
    : QObject{parent}
{}

void Loger::getLoger(QMap<QString, QVector<QString>> Sensors, int sensors_counter, int max_lengs)
{


    qDebug()<< " ";
    QFile file("Sensor_value.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    for(int i = 1; i < sensors_counter + 1; i++){

        QVector<QString>& vector = Sensors["Sensor" + QString::number(i)];
        for(int p = 0; p < max_lengs; p++){
            out << vector.at(p) << "\n";
        }
        out<<"\n";
    }

}

