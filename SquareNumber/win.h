
#ifndef WIN_H
#define WIN_H
#include <QObject>
#include <QtGui>
#include <QTextCodec>
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
class Win:public QWidget
{
    Q_OBJECT
protected:
    QTextCodec *codec;
    QFrame *frame; // рамка
    QLabel *inputLabel; // метка ввода
    QLineEdit *inputEdit; // строчный редактор ввода
    QLabel *outputLabel; // метка вывода
    QLineEdit *outputEdit; // строчный редактор вывода
    QPushButton *nextButton; // кнопка Следующее
    QPushButton *exitButton; // кнопка Выход
public:
    Win(QWidget *parent = 0); // конструктор
public slots:
    void begin(); // метод начальной настройки интерфейса
    void calc(); // метод реализации вычислений
};

class StrValidator:public QValidator // класс компонента проверки ввода
{
public:
    StrValidator(QObject *parent):QValidator(parent){}
    virtual State validate(QString &str,int &pos)const
    {
        return Acceptable; // метод всегда принимает вводимую строку
    }
};
#endif // WIN_H

