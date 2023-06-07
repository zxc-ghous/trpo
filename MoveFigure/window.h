
#ifndef WINDOW_H
#define WINDOW_H
#include <QtGui>
#include "area.h"
#include <QWidget>
#include <QTextCodec>
#include <QPushButton>
#include <QVBoxLayout>
class Window : public QWidget
{
protected:
    QTextCodec *codec;
    Area * area; // область отображения рисунка
    QPushButton * btn;
public:
    Window();
};

#endif // WINDOW_H
