#ifndef COUNTERWIDGET_H
#define COUNTERWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class CounterLine:public QLineEdit                              //класс виджета строки счетчика(наследуется от QLineEdit)
{
    Q_OBJECT                                                    //макрос подключения сигналов и слотов к классу
public:
    CounterLine(const QString & contents, QWidget *parent=0):   //конструктор(с вызовом конструктора родительского класса)
    QLineEdit(contents,parent){}

signals:
    void multipleFiveSignal();                                  //сигнал, срабатывает когда счетчик хранит число кратное 5

public slots:
    void addOne();                                              //слот, добавляющий 1 к счетчику

};

class CounterWidget : public QWidget                            //класс виджета для счетчика
{
    Q_OBJECT                                                    //макрос подключения сигналов и слотов к классу

public:
    CounterWidget(QWidget *parent = nullptr);                   //конструктор создания виджета

private:
    QLabel *labelCount,*labelCountByFive;                       //заголовки над счетчиками
    CounterLine *lineCount,*lineCountByFive;                    //счетчики
    QPushButton *addOneButton;                                  //кнопка добавления 1 к счетчику
    QPushButton *exitButton;                                    //кнопка выхода
};
#endif // COUNTERWIDGET_H
