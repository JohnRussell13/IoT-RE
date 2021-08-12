#include "dialog.h"
#include "ui_dialog.h"
#include <curl/curl.h>
#include <string>
#include <QTimer>

QT_CHARTS_USE_NAMESPACE

using namespace std;


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    wiringPiSetup();
    fd = wiringPiI2CSetup(PCF8591);

    //kreiranje podataka za prikaz
    series = new QLineSeries();

    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    //chart->createDefaultAxes();

    //postavljanje opsega
    QValueAxis *aX = new QValueAxis;
    aX->setRange(0,5);
    aX->setTickCount(6);
    chart->setAxisX(aX, series);

    QValueAxis *aY = new QValueAxis;
    aY->setRange(0,100);
    aY->setTickCount(5);
    chart->setAxisY(aY, series);

    chart->setTitle("Moisture value");

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    //postavljanje grafika u vertikal layout
    ui->verticalLayout->addWidget(chartView);

    start = 0;

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::funkcija()
{
    if(X > 5){
        X = 0;
        series->clear();
        series->append(X,Y);
        X++;
    }
    Y = wiringPiI2CReadReg8(fd,PCF8591+0);
    Y = (int)((255-Y)/255.0 * 100);
    Z = wiringPiI2CReadReg8(fd,PCF8591+1);
    Z = (int)((255-Z)/255.0 * 100);
    W = wiringPiI2CReadReg8(fd,PCF8591+2);
    W = (int)((255-W)/255.0 * 100);
    series->append(X,Y);

    //cURL code POST
    auto curl = curl_easy_init();
    if (curl) {
        string s0 = to_string(Y);
        string s1 = to_string(Z);
        string s2 = to_string(W);
        string temp_data = "moist=" + s0 + "&light=" + s1 + "&temp=" + s2;
        char const *data = temp_data.c_str();

        curl_easy_setopt(curl, CURLOPT_URL, URL_STR);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long) strlen(data));
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

        curl_easy_perform(curl);

        QString qstr = QString::fromStdString(data);
    }

    X++;
}


void Dialog::on_pushButton_clicked()
{
    if (!start){
        QTimer *myTimer1 = new QTimer(this);
        connect(myTimer1, SIGNAL(timeout()), this, SLOT(funkcija()));
        myTimer1->start(10000);
        X = 0;
        start = 1;
    }
}
