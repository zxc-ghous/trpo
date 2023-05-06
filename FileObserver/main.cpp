
#include <QCoreApplication>
#include <iostream>
#include "fileobserver.h"
#include <QTimer>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileObserver file_watcher;
    QTimer *timer = new QTimer();

    QObject::connect(&file_watcher,&FileObserver::logMessage,&FileObserver::fileMessage);
    QObject::connect(timer, &QTimer::timeout,&file_watcher,&FileObserver::checkFiles);

    file_watcher.addFile("F:\\my_datasets\\lab1Testing\\test1.txt");
    file_watcher.addFile("F:\\my_datasets\\lab1Testing\\test2.txt");
    file_watcher.addFile("F:\\my_datasets\\lab1Testing\\test3.txt");

//    QFileInfo test_info("F:\\my_datasets\\lab1Testing\\test3.txt");
//    qDebug()<<test_info.birthTime();

    timer->start(1000);
    return a.exec();
}

