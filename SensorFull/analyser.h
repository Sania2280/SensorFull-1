#ifndef ANALYSER_H
#define ANALYSER_H

#include <QObject>
#include <QVector>
#include <QMap>

class Analyser : public QObject
{
    Q_OBJECT
public:
    explicit Analyser(QObject *parent = nullptr);

public slots:
    void getData(QMap<QString, QVector<int>>, int sensor_counter);

signals:
    void onList(QVector<int> MAX, QVector<int> MIN, QVector<__int64> AVERAGE, QVector<__int64> MEDIAN, int sesor_counter);
private:


    QVector<int> MAX ;
    QVector<int> MIN;
    QVector<__int64> AVERAGE;
    QVector<__int64> MEDIAN;




};

#endif // ANALYSER_H
