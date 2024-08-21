#include "list.h"

List::List(QWidget *parent)
    : QWidget{parent}
{}

void List::Print(int num)
{

}

void List::getFromAnaliser(QVector<int> max, QVector<int> min, QVector<__int64> average, QVector<__int64> median, int sensor_counter)
{
    MAX = max;
    MIN = min;
    AVERAGE = average;
    MEDIAN = median;
}
