#ifndef DIALOG_H
#define DIALOG_H

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

#include <QDialog>
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>

#include <curl/curl.h>
#include <string>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QLineSeries *series;
    QChart *chart;
    QChartView *chartView;

private slots:
    void funkcija();
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;

    const char PCF8591 = 0x48;
    int fd, X, Y, Z, W;
    char unsigned adcVal;
    bool start;
    char *URL_STR = "https://iot-try.herokuapp.com/sensors";
};

#endif // DIALOG_H
