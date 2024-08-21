#ifndef SENSOR_H
#define SENSOR_H

#include <QObject>

class Sensor : public QObject
{
    Q_OBJECT
public:
    explicit Sensor(QObject *parent = nullptr);
    void GenerateSignal(int max_lengs, int sensor_counter);
    int maxxx;

signals:
    void CreateSignal(int value, int max_lengs, int No,int num, int sensor_counter);

public slots:
    void GetLengs(int max_size, int sensor_counter);


};

#endif // SENSOR_H
