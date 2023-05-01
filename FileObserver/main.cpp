
#include <QCoreApplication>
#include <iostream>
#include "fileobserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileObserver& file_watcher = FileObserver::instance();
    file_watcher.set(100);
    file_watcher.print();
    return a.exec();
}
