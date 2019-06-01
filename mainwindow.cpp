#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QTime>
#include <QTimeZone>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timeZoneTest();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeZoneTest()
{
    // Getting the current time
    QDateTime dateTime = QDateTime::currentDateTime();
    // Debug: Current time in local timezone
    qDebug() << dateTime.toString();
    // Debug: Current time / local timezone, formatted
    qDebug() << dateTime.toString("hh");
    qDebug() << dateTime.toString("mm");
    qDebug() << dateTime.toString("ss");

    // Create a new timezone object to convert
    QTimeZone newZone("America/Chicago");
    // Debug: Check if the new zone is valid
    qDebug() << newZone;

    // Convert the current time to the new timezone
    QDateTime newDateTime = dateTime.toTimeZone(newZone);

    // Debug: The converted time
    qDebug() << newDateTime.toString();
    // Debug: The converted time (formatted: hr, min, sec)
    qDebug() << newDateTime.toString("hh");
    qDebug() << newDateTime.toString("mm");
    qDebug() << newDateTime.toString("ss");

    // To list all available timezone IDs, use the following's output
    //qDebug() << QTimeZone::availableTimeZoneIds();
}
