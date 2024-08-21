#ifndef SENSORMETRIC_H
#define SENSORMETRIC_H

#include <QObject>
#include <QMap>

class SensorMetric : public QObject
{
    Q_OBJECT
public:
    explicit SensorMetric(QObject *parent = nullptr);



    void Target(int value, int max_lengs, int No, int num, int sensor_counter);

signals:
    void onAnalyser(QMap<QString, QVector<int>> , int srnsor_counter);
    void onLoger(QMap<QString, QVector<QString>>, int sensors_counter, int max_l);

private:

    QMap<QString, QVector<int>> Sensors;
    QMap<QString, QVector<QString>> Sensors_cahnged;
};

#endif // SENSORMETRIC_H
