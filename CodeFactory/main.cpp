
#include <QCoreApplication>
#include "AbstractFactory.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug()<<"working";

    return a.exec();
}
