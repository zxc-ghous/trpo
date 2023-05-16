
#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H


#include <QObject>
#include <iostream>
#include <QFileInfo>
#include <QDateTime>
#include <QDir>
#include <QMap>
#include <QStringList>

class FileObserver: public QObject
{
    Q_OBJECT
public:
    FileObserver(){}
    ~FileObserver(){}
    static FileObserver& instance()
    {
        static FileObserver instance;
        return instance;
    }
    void addFile (QString filepath);
    void removeFile (QString filepath);
    void setDirectory (QString directory);
    void printWatchedFiles ();
private:
    struct fileStatus
    {
        unsigned int size;
        bool exist;
        QDateTime last_modified;
    };
    void updateStatus(QString key, QFileInfo file_info);
    QMap<QString, fileStatus> watched_files;
    FileObserver(const FileObserver& root) = delete;
    FileObserver& operator=(const FileObserver&) = delete;

signals:
    void logMessage (QString str);
public slots:
    void fileMessage (QString str);
    void fileChecker();
};



#endif // FILEOBSERVER_H

