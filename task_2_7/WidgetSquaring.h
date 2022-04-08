#ifndef WIDGETSQUARING_H
#define WIDGETSQUARING_H

#include <QWidget>                                  //подключение необходимых библиотек
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QValidator>

QT_BEGIN_NAMESPACE                                  //пространство имен для реализуемого виджета
namespace Ui { class WidgetSquaring; }
QT_END_NAMESPACE

class WidgetSquaring : public QWidget               //виджет для вычисления квадрата числа
{                                                   //сделан наследником QWidget, поскольку наследование от QMainWindow здесь не требуется(его доп возможности не используются)
    Q_OBJECT                                        //макрос для подключения сигналов и слотов к классу

public:
    WidgetSquaring(QWidget *parent = nullptr);      //конструктор
    ~WidgetSquaring() {}                            //деструктор

public slots:                                       //слоты:
    void reset();                                   //слот для очитки виджета и подготовки его к новому вычислению
    void calculate();                               //слот для вычисления

private:
    QFrame *frame;                                  //рамка(используется на виджете, требуется по заданию)

    QLabel *inputTitle;                             //заголовок над строкой для ввода
    QLineEdit *inputEdit;                           //строка ввода

    QLabel *outputTitle;                            //заголовок над строкой вывода
    QLineEdit *outputEdit;                          //строка вывода

    QPushButton *nextButton;                        //кнопка для очистки виджета от предыдущей операции
    QPushButton *exitButton;                        //кнопка закрытия виджета

    double squaring(double input);                  //функция возведения в квадрат числа
};

class StrValidator:public QValidator                // класс компонента проверки ввода
{
    public:
    StrValidator(QObject *parent):QValidator(parent){}

    virtual State validate(QString &str,int &pos)const      //определение виртуальной функции проверки ввода
    {
        return Acceptable;                          // метод всегда принимает вводимую строку
    }
};

#endif
