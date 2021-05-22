#ifndef GAMETIMEBOMB_H                               // GameTimeBomb.h
#define GAMETIMEBOMB_H

#include <QTimer>
#include <QTime>
#include <QRandomGenerator>
#include "console.h"



class GameTimeBomb: public QObject
{
    Q_OBJECT
    inline static constexpr const char* const provodki[] ={"krasniy", "orangeviy", "jeltiy", "zelyoniy", "goluboy", "siniy", "fioletoviy"};
    public:
    GameTimeBomb(Console * cons) {
        timer = new QTimer();
        timer->setSingleShot(true);
        QObject::connect(cons, SIGNAL (userInput(QString)), this,  SLOT(game_bomb(QString)));    //  запуск интерфейса
        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));    // запуск таймера
    }
    private slots:
    void slotTimerAlarm();
    void game_bomb(QString);
    void quit();
    private:
    QTimer *timer;
    int n;                              // число проводков
    const char *provodki_rand[sizeof(provodki)/sizeof(provodki[0])];       // массив случайных проводков
    int yes;
};


#endif // GAMETIMEBOMB_H

