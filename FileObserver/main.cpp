
#include <QCoreApplication>
#include <iostream>
#include "fileobserver.h"
#include <QFileInfo>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileObserver file_watcher;
    file_watcher.addFile("C:\\Users\\sskil\\Pictures\\mem.png");
    file_watcher.addFile("C:\\Users\\sskil\\Pictures\\mem.png");
    return a.exec();
}

