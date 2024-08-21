#include "window.h"
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QObject>
#include <QLabel>
#include <QListWidget>
#include <QSpacerItem>
#include <QStringBuilder>
#include <QDebug>
#include <QRegularExpressionMatch>

#include "connect_json.h"
#include "resizebutton.h"
#include "butonlog.h"
#include "list.h"

Window::Window(QWidget *parent)
    : QWidget{parent}
{}

void Window::Draw(const QString file_name, Sensor *sens, int max_lengs, bool stat, Connect_JSON *JSON)
{

    this->list = list;
    int maxWidth = 150;

    // Создаем виджеты
    ResizeButton *butonAdd = new ResizeButton("Add Sensor", maxWidth);
    ResizeButton *butonDel = new ResizeButton("Delete Sensor", maxWidth);
    QPushButton *start = new QPushButton("Start");
    QSpacerItem* spacer = new QSpacerItem(10, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QVBoxLayout *layout = new QVBoxLayout();
    QLabel *label = new QLabel();
    QListWidget *list = new QListWidget();
    QListWidget *otherList = new QListWidget();  // Додано новий список
    QHBoxLayout *layoutS = new QHBoxLayout();

    list->addItem("Sensor 1");
    label->setText("Sensor quantity 1");

    // Добавляем виджеты в макет
    layout->addWidget(butonAdd);
    layout->setSpacing(20);
    layout->addWidget(butonDel);
    layout->addWidget(label);
    layout->setSpacing(40);
    layout->addWidget(list);
    layout->addWidget(otherList);  // Додано другий список
    layout->addItem(spacer);

    QHBoxLayout *hLayout = new QHBoxLayout();
    QSpacerItem* spacer1 = new QSpacerItem(100, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(spacer1);
    hLayout->addWidget(start);
    hLayout->setAlignment(Qt::AlignCenter);
    layout->addLayout(hLayout);

    // Создаем объект логики
    ButonLog *but = new ButonLog();

    // Соединяем сигналы и слоты
    QObject::connect(butonAdd, &QPushButton::clicked, [=]() {
        QString text = but->Sens(true);
        label->setText("Sensor quantity " % text);
        list->addItem("Sensor " % text);
    });

    QObject::connect(butonDel, &QPushButton::clicked, [=]() {
        QString text = but->Sens(false);
        label->setText("Sensor quantity " % text);
        int itemCount = list->count();  // Получаем количество элементов
        if(itemCount == 1 ) return;

        if (itemCount > 0 ) {
            delete list->item(itemCount - 1);
        }
    });

    QObject::connect(start, &QPushButton::clicked, [=]() {
        int val = but->Start();
        qDebug() << "Start";
        JSON->Worck_with_json(file_name, sens,  max_lengs, stat, val);
    });

    //  обработчик кликов для первого списка
    QObject::connect(list, &QListWidget::itemClicked, [=](QListWidgetItem* item) {
        QString sensorName = item->text();

        QRegularExpression re("\\d+");
        QRegularExpressionMatch match = re.match(sensorName);

        otherList->clear();


            QString numberStr = match.captured(0);

            otherList->addItem(numberStr);

            // otherList->addItem(List::li->);

    });

    // Настройки окна
    this->setLayout(layout);
    this->resize(575, 300);
    this->setStyleSheet("background-color: #e0d3db;");
    this->show();
}
