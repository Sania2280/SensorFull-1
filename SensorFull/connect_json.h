#ifndef CONNECT_JSON_H
#define CONNECT_JSON_H

#include <QObject>

class Sensor;

class Connect_JSON : public QObject
{
    Q_OBJECT
public:
    explicit Connect_JSON(QObject *parent = nullptr);
    void Worck_with_json(const QString file_name, Sensor *sens, int max_lengs, bool stat, int sensor_counter);
    int max_lengs(){
        return MAX;
    }
signals:
    void giveLengs(int max_lengs, int sensor_counter);
private:
    int MAX = 0;
};

#endif // CONNECT_JSON_H
