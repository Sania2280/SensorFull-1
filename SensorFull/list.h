#ifndef LIST_H
#define LIST_H

#include <QWidget>
#include <QVector>
#include <QMap>

class List : public QWidget
{
    Q_OBJECT
public:
    explicit List(QWidget *parent = nullptr);
    void Print(int num);


signals:
public slots:
    void getFromAnaliser(QVector<int> max, QVector<int> min, QVector<__int64> average, QVector<__int64> MEDIAN, int sensor_counter);

private:
    QVector<int> MAX;
    QVector<int> MIN;
    QVector<__int64> AVERAGE;
    QVector<__int64> MEDIAN;
};

#endif // LIST_H
