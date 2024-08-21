#include "butonlog.h"
#include <qDebug>
#include <QString>
#include <QStringBuilder>

QString ButonLog::Sens(bool num)
{
    if(val >= 1 && num == true) {
        val++;
        return  QString::number(val);
    }

    else if (val > 1 && num == false) {
        val--;
        return  QString::number(val);
    }

    return  QString::number(val);
}

int ButonLog::Start()
{
    return val;
}

ButonLog::ButonLog(QObject* parent) : QObject(parent) {
    // Конструктор по умолчанию
}

