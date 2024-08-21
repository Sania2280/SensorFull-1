#include <QCommandLineParser>
#include <QApplication>

#include "window.h"
#include "sensor.h"
#include "connect_json.h"
#include "sensormetric.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCommandLineParser parser;

    int max_lengs = 0;
    bool stat;

    parser.setApplicationDescription("Sensor imitation");
    parser.addHelpOption();
    parser.addOption({ {"m", "memory"}, "Input max lengs", "memory"});
    parser.process(app);

    Connect_JSON * JSON = new Connect_JSON();
    Sensor * sens = new Sensor();
    SensorMetric * metric = new SensorMetric();

    if(parser.isSet("memory") ){
        int mem = parser.value("memory").toInt();
        qDebug() << "Size :" << mem;
        stat = true;
        max_lengs = mem;
    }

    qDebug()<<"qwer";
    // QObject::connect(JSON, &Connect_JSON::giveLengs, sens, &Sensor::GetLengs);
    QObject::connect(sens, &Sensor::CreateSignal, metric, &SensorMetric::Target);

    // JSON -> Worck_with_json("config.json", sens, max_lengs, stat);


    Window * wind = new Window();
    wind->Draw("config.json", sens, max_lengs, stat, JSON);

    return app.exec();
}
