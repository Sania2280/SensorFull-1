#ifndef BUTONLOG_H
#define BUTONLOG_H

#include <QObject>
#include <QDebug>
#include <QString>

class ButonLog : public QObject
{
    Q_OBJECT

public:
    explicit ButonLog(QObject* parent = nullptr);
    unsigned int val = 1;
    QString Sens(bool num);
    int Start();



};

#endif // BUTONLOG_H
