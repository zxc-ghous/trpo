
#include <QCoreApplication>
#include <iostream>
#include "fileobserver.h"
#include <QTimer>

//TODO: когда файл создается вызывается модификация
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileObserver file_watcher;
    QTimer *timer = new QTimer();

    QObject::connect(&file_watcher,&FileObserver::logMessage,&FileObserver::fileMessage);
    QObject::connect(timer, &QTimer::timeout,&file_watcher,&FileObserver::checkFiles);

//    file_watcher.addFile("F:\\my_datasets\\lab1Testing\\test1.txt");
//    file_watcher.addFile("F:\\my_datasets\\lab1Testing\\test2.txt");
//    file_watcher.addFile("F:\\my_datasets\\lab1Testing\\test3.txt");

    file_watcher.setDirectory("F:\\my_datasets\\lab1Testing");
    file_watcher.getWatchedFiles();

    timer->start(1000);
    return a.exec();
}

