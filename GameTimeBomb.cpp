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

void GameTimeBomb::slotTimerAlarm()
{
    qDebug()<<"BOOM!!!BANG!!!";
}

void GameTimeBomb::game_bomb(QString qs)
{
    qDebug()<<"enter !bomb\n";                                       // debug
    int n = QRandomGenerator::global()->bounded(2, 8);  // число проводков
    const char *provodki_rand[n];                      // массив случайных проводков
    int yes =  QRandomGenerator::global()->bounded(0, n);
    if(qs.indexOf("!bomb"))
    {
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

        for (int i = 0; i < SZ; i++)
        {
             provodki_rand[i]=provodki[ind[i]];
        }

        qDebug()<<" otrej "<<provodki_rand[yes]<<endl;
        timer->singleShot(10000, this, SLOT(slotTimerAlarm()));
        qDebug()<<"pered Vami bomba s taymerom ustanovlennym na 30 sec i "<<n<<" provodkov\n";
        for (int i=0; i<n; i++)
            qDebug()<< provodki_rand[i]<<" ";
        qDebug()<<endl;
    }
    if(qs==provodki_rand[yes])
        qDebug()<<"WIN!";
    else
    {
        if(qs==provodki_rand[yes])
            qDebug()<<"WIN!";
    }
        timer->stop();
}

void GameTimeBomb::quit()
{
    qInfo() << "Good bye!";
}
