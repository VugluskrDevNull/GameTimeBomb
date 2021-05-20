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
     qDebug()<<"game_bomb\n";                                      // debug

    qDebug()<<"qs 1 "<<qs<<"\n";                                      // debug
    qDebug()<<"qs.indexOf() 1" << qs.indexOf("!bomb")<<"\n";            // debug
    n = QRandomGenerator::global()->bounded(2, 8);
    if(qs.indexOf("!bomb")!=-1)
    {
        qDebug()<<"qs 2 "<<qs<<"\n";                                      // debug
        qDebug()<<"qs.indexOf() 2" << qs.indexOf("!bomb")<<"\n";            // debug
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
        timer->singleShot(30000, this, SLOT(slotTimerAlarm()));
        qDebug()<<"pered Vami bomba s taymerom ustanovlennym na 30 sec i "<<n<<" provodkov\n";
        for (int i=0; i<n; i++)
            qDebug()<< provodki_rand[i]<<" ";
        qDebug()<<endl;
    }
    qDebug()<<"qs 3 "<<qs<<"\n";                                      // debug
    qDebug()<<"qs.indexOf() 3" << qs.indexOf("!bomb")<<"\n";            // debug
    if(qs==provodki_rand[yes])
        qDebug()<<"WIN!";
    else if (qs.indexOf("krasniy")!=-1 || qs.indexOf("orangeviy")!=-1 || qs.indexOf("jeltiy")!=-1 || qs.indexOf("zelyoniy")!=-1 || qs.indexOf("goluboy")!=-1 || qs.indexOf("siniy")!=-1 || qs.indexOf("fioletoviy")!=-1)
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
