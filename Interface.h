#ifndef INTERFACE_H
#define INTERFACE_H

#include <QString>
#include <QObject>

class Interface : public QObject
{
    Q_OBJECT;
public:
    void run();                           // cosole
    void send(QString);
    void write ();
signals:
    void quit();
    void userInput(QString);

private slots:                             // GB
void slotTimerAlarm();
void game_bomb(QString);
// void quit();                         ???
};

#endif // INTERFACE_H
