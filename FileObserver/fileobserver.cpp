#include <QFileInfo>
#include "fileobserver.h"


void FileObserver:: addFile(QString filename)
{
    QFileInfo file_info(filename);
    if (watched_files.contains(file_info.absoluteFilePath()))
    {
         emit FileObserver::logMessage(QString {} + file_info.absoluteFilePath() + " is already being watched.\n");
        return;
    }
    watched_files.append(file_info.absoluteFilePath());
    emit FileObserver::logMessage(QString {} + "Added a file to watch: " + file_info.absoluteFilePath());

}

void FileObserver::checkFiles()
{
    std::cout<<"slot active"<<std::endl;
}
