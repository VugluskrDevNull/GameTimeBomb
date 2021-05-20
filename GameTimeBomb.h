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
        n = QRandomGenerator::global()->bounded(2, 8);

        timer = new QTimer();
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
        static char *provodki_rand;       // массив случайных проводков  // передать с параметром в game bomb
        int yes =  QRandomGenerator::global()->bounded(0, n);                // передать с параметром в game bomb
};


#endif // GAMETIMEBOMB_H

