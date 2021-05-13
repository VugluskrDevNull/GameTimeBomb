#ifndef CONSOLE_H
#define CONSOLE_H
#pragma once                                   // console.h

#include <QObject>
#include <QSocketNotifier>
#include <iostream>

class Console : public QObject
{
    QString retline;
    Q_OBJECT;
public:
    Console();
    void run();
signals:
    void quit();
    void userInput(QString);
private:
    QSocketNotifier *m_notifier;
private slots:
    void readCommand();
};

#endif // CONSOLE_H
