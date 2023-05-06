
#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H

#include <QObject>
#include <iostream>
#include <QFileInfo>
#include <QList>
#include <QDateTime>

class FileObserver: public QObject
{
    Q_OBJECT
public:
    FileObserver(){}
    ~FileObserver(){}
    void addFile (QString filename);
private:
    struct fileStatus
    {
        unsigned int size;
        bool exist;
        QDateTime last_modified;
        QDateTime birth_time;
    };
    QMap<QString, fileStatus> watched_files;

signals:
    void logMessage (QString str);
public slots:
    void fileMessage (QString str);
    void checkFiles();
};



#endif // FILEOBSERVER_H

