
#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H

#include <QObject>
#include <iostream>
#include <QFileInfo>
#include <QList>

class FileObserver: public QObject
{
    Q_OBJECT
public:
    FileObserver(){}
    ~FileObserver(){}
    void addFile (QString filename);
    QList<QString> watched_files;


signals:
    void logMessage (QString str);
public slots:
    void checkFiles ();
};



#endif // FILEOBSERVER_H

