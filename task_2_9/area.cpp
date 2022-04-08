#include "area.h"

Area::Area(QWidget *parent):QWidget(parent)         //конструктор виджета
{
    setFixedSize(QSize(300,200));                   //установка зафиксированного размера виджета
                                                    //создание фигур
    myline=new MyLine(80, 100, 50);
    myrect=new MyRect(220, 100, 50);
                                                    //инициаллизация начального угла поворота фигур
    alpha=0;
}

void Area::showEvent(QShowEvent *)                  //обработчик события когда виджет стал виден
{
    myTimer=startTimer(50);                         //создание таймера
}

void Area::paintEvent(QPaintEvent *)
{
    QPainter painter(this);                         //создание объекта рисования
    painter.setPen(Qt::red);                        //назначение ему красного цвета
    myline->move(alpha,&painter);                   //движение линии(и отрисовка внутри этой функции)
    myrect->move(alpha*(-0.5),&painter);            //движение прямоугольника(и отрисовка внутри этой функции)
}

void Area::timerEvent(QTimerEvent *event)           //обработчик события срабатывания таймера
{
    if (event->timerId() == myTimer)                // если тамер наш
    {
        alpha += 0.2;                               //изменение угла
        update();                                   // обновить внешний вид
    }
    else
        QWidget::timerEvent(event);                 // иначе передать для стандартной обработки
}

void Area::hideEvent(QHideEvent *)                  //обработчик события когда виджет стал скрыт
{
    killTimer(myTimer);                             //уничножение таймера
}

Area::~Area()                                       //деструктор виджета
{
    delete myline;                                  //удаление линии и прямоугольника
    delete myrect;
}
