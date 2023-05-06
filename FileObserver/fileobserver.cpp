#include <QFileInfo>
#include "fileobserver.h"


void FileObserver:: addFile(QString filename)
{
    QFileInfo file_info(filename);
    if (watched_files.contains(file_info.absoluteFilePath()))
    {
        emit logMessage(QString {} + file_info.absoluteFilePath() + " is already watched");
        return;
    }

    fileStatus file_status;
    file_status.size=file_info.size();
    file_status.exist=file_info.exists();
    file_status.last_modified=file_info.lastModified();

    watched_files.insert(file_info.absoluteFilePath(), file_status);
    emit logMessage(QString {} + "Now watch file: " + file_info.absoluteFilePath());

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

void FileObserver::fileMessage(QString str)
{
    std::cout<<str.toStdString()<<std::endl;
}

void FileObserver::checkFiles()
{
    QMap<QString, fileStatus>::iterator i;
    for (i = watched_files.begin(); i != watched_files.end(); ++i)
    {
        QFileInfo file_info(i.key());

        if (i.value().exist && !file_info.exists())
        {
            i.value().exist = file_info.exists();
            emit logMessage(QString {} + "file " + i.key() + " erased");
        }
        else if (!i.value().exist && file_info.exists())
        {
            i.value().exist = file_info.exists();
            emit logMessage(QString {} + "file " + i.key() + " created");
        }
        else if ((i.value().size != file_info.size()) && i.value().exist)
        {
            i.value().last_modified = file_info.lastModified();
            i.value().size = file_info.size();
            emit logMessage(QString {} + "file " + i.key() + " modified");
        }
    }
}
