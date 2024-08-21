#include "connect_json.h"
#include "sensor.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDebug>

Connect_JSON::Connect_JSON(QObject *parent)
    : QObject{parent}
{}

void Connect_JSON::Worck_with_json(const QString file_name, Sensor *sens, int max_lengs, bool stat, int sensor_counter)
{

    int max_lengs_defolt = 10;
    int max_lengs_new = max_lengs != 0 ? max_lengs : max_lengs_defolt;

    QFile file(file_name);

    if (!file.exists()) {
        qDebug() << "File does not exist, creating new file with default data.";
        if (!file.open(QIODevice::WriteOnly)) {
            qDebug() << "Error creating file.";
            return;
        }

        QJsonObject jsonObj;
        QJsonObject jsonData;
        jsonData["MAX_LENGS"] = max_lengs_new;
        jsonObj["DATA"] = jsonData;

        QJsonDocument doc(jsonObj);
        file.write(doc.toJson());
        file.close();

        connect(this, &Connect_JSON::giveLengs, sens, &Sensor::GenerateSignal);
        emit giveLengs(max_lengs_new, sensor_counter);
    } else {
        if (!file.open(QIODevice::ReadWrite)) {
            qDebug() << "Error opening file.";
            return;
        }

        QByteArray data = file.readAll();
        QJsonDocument doc(QJsonDocument::fromJson(data));

        if (doc.isNull() || !doc.isObject()) {
            qDebug() << "Error reading JSON file.";
            file.close();
            return;
        }

        QJsonObject jsonObj = doc.object();
        QJsonObject dataObj = jsonObj["DATA"].toObject();
        int size = dataObj["MAX_LENGS"].toInt();

        connect(this, &Connect_JSON::giveLengs, sens, &Sensor::GenerateSignal);

        if (stat == true ) {
            file.resize(0); // Clear file content
            dataObj["MAX_LENGS"] = max_lengs_new;
            jsonObj["DATA"] = dataObj;

            QJsonDocument newDoc(jsonObj);
            file.write(newDoc.toJson());
            file.flush();
            size = max_lengs_new;

            qDebug() << "Updated file with new max length:" << size;
            emit giveLengs(size, sensor_counter);
        }

        else   emit giveLengs(size, sensor_counter);

    }
}
