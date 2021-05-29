#include <QCoreApplication>
#include <QSettings>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include "GameTimeBomb.cpp"
//#include "libircbot.cpp"
#include <QTimer>
#include "QTime"

int main(int argc, char** argv)
{

    QCoreApplication app(argc, argv);

  //  Bot *botptr = new Bot;
  //  if (!(botptr->connect()))
  //      return  1;

    qDebug()<<"enter !bomb\n";
    Console *cons = new Console();
    GameTimeBomb *pg = new GameTimeBomb(cons);
    Interface *iface;
   //  pg->game_bomb("!bomb");
   //  pg->game_bomb("krasniy");
    cons->run();
    QObject::connect(cons, SIGNAL (userInput(QString)), pg,  SLOT(game_bomb(QString)));    //  запуск интерфейса
    QObject::connect(cons, SIGNAL(quit()), &app, SLOT(quit()));
    QObject::connect(cons, SIGNAL(quit()), pg, SLOT(quit()));
    return app.exec();
}


