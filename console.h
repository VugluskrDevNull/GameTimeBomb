#ifndef CONSOLE_H
#define CONSOLE_H
#pragma once                                   // console.h

#include <QObject>
#ifdef Q_OS_WIN
#include <QWinEventNotifier>
#include <windows.h>
#else
#include <QSocketNotifier>
#endif
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
  //  QSocketNotifier *m_notifier;

#ifdef Q_OS_WIN
    QWinEventNotifier *m_notifier;
#else
    QSocketNotifier *m_notifier;
#endif


private slots:
    void readCommand();
};

#endif // CONSOLE_H
