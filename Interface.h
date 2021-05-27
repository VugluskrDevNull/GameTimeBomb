#ifndef INTERFACE_H
#define INTERFACE_H

#include <QString>
#include <QObject>

class Interface : public QObject
{
    Q_OBJECT;
public:
    void run();                           // console
    virtual   void send(QString)=0;
    virtual   void write ()=0;
signals:
    void quit();
    void userInput(QString);
};

#endif // INTERFACE_H
