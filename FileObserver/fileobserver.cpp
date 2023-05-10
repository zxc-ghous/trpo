#include <QFileInfo>
#include "fileobserver.h"


void FileObserver:: addFile(QString filepath)
{
    QFileInfo file_info(filepath);
    if (watched_files.contains(file_info.absoluteFilePath()))
    {
        emit logMessage(QString {} + file_info.absoluteFilePath() + " is already observed");
        return;
    }

    fileStatus file_status;
    file_status.size=file_info.size();
    file_status.exist=file_info.exists();
    file_status.last_modified=file_info.lastModified();

    watched_files.insert(file_info.absoluteFilePath(), file_status);
    emit logMessage(QString {} + "Now observe file: " + file_info.absoluteFilePath());

}

void FileObserver:: removeFile(QString filepath)
{
    QFileInfo file_info(filepath);
    watched_files.remove(file_info.absoluteFilePath());
    emit logMessage(QString {} + file_info.absoluteFilePath() + " is no longer observed");
}

void FileObserver:: setDirectory(QString directory)
{
    QDir dir(directory);
    QStringList files = dir.entryList(QDir::Files);
    for (auto& i : files  )
    {
        addFile(dir.absoluteFilePath(i));
    }
}

void FileObserver:: updateStatus(QString key, QFileInfo file_info)
{
    watched_files[key].exist = file_info.exists();
    watched_files[key].size = file_info.size();
    watched_files[key].last_modified = file_info.lastModified();
}

void FileObserver:: printWatchedFiles ()
{
    QMap<QString, fileStatus>::iterator i;
    for (i = watched_files.begin(); i != watched_files.end(); ++i)
    {
        emit logMessage(i.key());
    }
}

void FileObserver::fileMessage(QString str)
{
    qDebug()<<str;
}

void FileObserver::fileChecker()
{
    QMap<QString, fileStatus>::iterator i;
    for (i = watched_files.begin(); i != watched_files.end(); ++i)
    {
        QFileInfo file_info(i.key());

        if (i.value().exist && !file_info.exists())
        {
            updateStatus(i.key(), file_info);
            emit logMessage(QString {} + "file " + i.key() + " erased");
        }
        else if (!i.value().exist && file_info.exists())
        {
            updateStatus(i.key(), file_info);
            emit logMessage(QString {} + "file " + i.key() + " created");
        }
        else if ((i.value().size != file_info.size()) && i.value().exist)
        {
            updateStatus(i.key(), file_info);
            emit logMessage(QString {} + "file " + i.key() + " modified");
        }
    }
}
