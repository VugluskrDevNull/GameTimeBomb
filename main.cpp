#include <QCoreApplication>
#include <QSettings>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include "GameTimeBomb.cpp"
#include <QTimer>
#include "QTime"

int main(int argc, char** argv)
{

    QCoreApplication app(argc, argv);
    Console *cons = new Console();
    GameTimeBomb *pg = new GameTimeBomb(cons);
    cons->run();

    QObject::connect(cons, SIGNAL(quit()), &app, SLOT(quit()));
    QObject::connect(cons, SIGNAL(quit()), pg, SLOT(quit()));
    return app.exec();
}


