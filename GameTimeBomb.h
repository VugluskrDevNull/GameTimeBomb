#ifndef GAMETIMEBOMB_H                               // GameTimeBomb.h
#define GAMETIMEBOMB_H

#include <QTimer>
#include <QTime>
#include "console.h"

class GameTimeBomb: public QObject
{
    Q_OBJECT;
    static constexpr char * const provodki[] ={"krasniy", "orangeviy", "jeltiy", "zelyoniy", "goluboy", "siniy", "fioletoviy"};
    public:
    GameTimeBomb(Console * cons) {
        timer = new QTimer();
        QObject::connect(cons, SIGNAL (userInput(QString)), this,  SLOT(game_bomb(QString)));    //  запуск интерфейса
        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));    // запуск таймера
    }
    private slots:
    void slotTimerAlarm();
    void game_bomb(QString);
    private:
        QTimer *timer;
    };


#endif // GAMETIMEBOMB_H

