#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include "sensor.h"
#include "connect_json.h"
#include "list.h"

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
    void Draw(const QString file_name, Sensor *sens, int max_lengs, bool stat, Connect_JSON *JSON);

signals:
private:
    List * list;
};

#endif // WINDOW_H
