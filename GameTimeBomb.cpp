#include <QCoreApplication>                                                 // GameTimeBomb.cpp
#include <QSettings>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include "GameTimeBomb.h"
#include <QTimer>
#include "QTime"
#include <QRandomGenerator>

/*
переменная "состояние". цифра в которой обозначает в каком состоянии находится игра. наприппер #define IDLE 1
(простаивает. игры нет), GAME 2 (игра в процессе), OFF 3
(игра отключена) ну и внутри game_bomb() проверяешь if (state == OFF) return;. тоесть ты ничего
не делаешь если игра "отключена"
 */

#define IDLE 1
#define GAME 2
#define OFF 3
int state;

void GameTimeBomb::slotTimerAlarm()
{
    qDebug()<<"BOOM!!!BANG!!!";
    state = OFF;
}

void GameTimeBomb::game_bomb(QString qs)
{
    n = QRandomGenerator::global()->bounded(2, 8);
    if(qs.indexOf("!bomb")!=-1)
    {
        if (state == GAME) return;
        state = GAME;
        int SZ=7;
        int ind[SZ];

        for (int i = 0; i < SZ; i++)
        {
            ind[i]=  i;
        }

        for (int i = 0; i < SZ; i++)
        {
            int n1 =  QRandomGenerator::global()->bounded(0, n);
            std::swap(ind[i], ind[n1]);   // или int n2 =  rand()%SZ; std::swap(m[n1], m[n2]);
        }

        for (int i = 0; i < n; i++)
        {
             provodki_rand[i]=provodki[ind[i]];
        }

        yes =  QRandomGenerator::global()->bounded(0, n);
        qDebug()<<" otrej "<<provodki_rand[yes]<<endl;
        timer->start(10000);
        qDebug()<<"pered Vami bomba s taymerom ustanovlennym na 30 sec i "<<n<<" provodkov\n";
        for (int i=0; i<n; i++)
            qDebug()<< provodki_rand[i]<<" ";
    }
    if(qs==provodki_rand[yes])
    {
        qDebug()<<"WIN!";
        timer->stop();
        state = OFF;
    }
}


void GameTimeBomb::quit()
{
    qInfo() << "Good bye!";
}
