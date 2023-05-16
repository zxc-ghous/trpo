
#include <QCoreApplication>
#include <iostream>
#include "fileobserver.h"
#include <QTimer>
#ifdef Q_OS_WIN
//#ifdef Q_OS_UNIX
int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    FileObserver& file_watcher = FileObserver::instance();
    QTimer *timer = new QTimer();

    QObject::connect(&file_watcher,&FileObserver::logMessage,&FileObserver::fileMessage);
    QObject::connect(timer, &QTimer::timeout,&file_watcher,&FileObserver::fileChecker);

//    file_watcher.addFile("F:\\my_datasets\\lab1Testing\\test1.txt");
//    file_watcher.addFile("F:\\my_datasets\\lab1Testing\\test2.txt");
//    file_watcher.addFile("F:\\my_datasets\\lab1Testing\\test3.txt");

    file_watcher.setDirectory("F:\\my_datasets\\lab1Testing");

    QFileInfo info1("F:\\my_datasets\\lab1Testing\\test1.txt");
    qDebug()<<info1.absoluteFilePath();
    qDebug()<<info1.size();


    timer->start(1000);
    return a.exec();
}

#endif
