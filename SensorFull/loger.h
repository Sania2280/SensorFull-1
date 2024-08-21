#ifndef LOGER_H
#define LOGER_H

#include <QObject>
#include <QMap>

class Loger : public QObject
{
    Q_OBJECT
public:
    explicit Loger(QObject *parent = nullptr);

signals:
public slots:
    void getLoger(QMap<QString, QVector<QString>>, int sensors_counter, int max_lengs);

private:

};

#endif // LOGER_H
