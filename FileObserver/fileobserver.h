
#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H

#include <QObject>
#include <iostream>
class FileObserver: public QObject
{
    Q_OBJECT
public:
    static FileObserver& instance()
    {
        static FileObserver instance;
        return instance;
    }
    void set(int d_) {d=d_;}
    void print() {std::cout<<d<<std::endl;}
private:
    int d;
    FileObserver(){}
    FileObserver(const FileObserver& root) = delete;
    FileObserver& operator=(const FileObserver&) = delete;
};



#endif // FILEOBSERVER_H

