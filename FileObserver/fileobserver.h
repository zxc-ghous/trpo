
#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H

#include <QObject>
#include <iostream>
#include <QFileInfo>
#include <QDateTime>
#include <QDir>
#include <QStringList>

class FileObserver: public QObject
{
    Q_OBJECT
public:
    FileObserver(){}
    ~FileObserver(){}
    void addFile (QString filename);
    void setDirectory (QString directory);
    void getWatchedFiles ();
private:
    struct fileStatus
    {
        unsigned int size;
        bool exist;
        QDateTime last_modified;
    };
    void updateStatus(QString key, QFileInfo file_info);
    QMap<QString, fileStatus> watched_files;

signals:
    void logMessage (QString str);
public slots:
    void fileMessage (QString str);
    void checkFiles();
};



#endif // FILEOBSERVER_H

