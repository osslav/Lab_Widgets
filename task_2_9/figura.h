#ifndef FIGURA_H
#define FIGURA_H

#include <QPainter>

class Figura                                    //абстрактный класс, является интерфейсом для создания фигур
{
protected:
    int x,y;                                    //координаты расположения центра фигуры
    int halfLength;                             //половина от длины фигуры
    int dx,dy;                                  //координаты вектора, указывающего наклон фигуры (длина вектора = halfLength)

    virtual void draw(QPainter *Painter)=0;     //чистая виртуальная функция для отрисовки фигуры
public:
    Figura(int X,int Y,int Halflen):            //конструктор(определяет положение фигуры(x, y) и размер(halfLength - половина длины))
    x(X),y(Y),halfLength(Halflen) {}

    void move(float Alpha,QPainter *Painter);   //функция движения фигуры(изменения угла наклона)
};

class MyLine:public Figura                      //класс линии, использует класс Figura как интерфейс
{
protected:
    void draw(QPainter *Painter);               //объявление для определения чистой виртуальной функции draw из Figura
public:
    MyLine(int x,int y,int halflen):Figura(x,y,halflen){}       //конструктор(использует родительский конструктор)
};

//аналогично задается класс:
class MyRect:public Figura                      //класс прямоугольника, использует класс Figura как интерфейс
{
protected:
    void draw(QPainter *Painter);               //объявление для определения чистой виртуальной функции draw из Figura
public:
    MyRect(int x,int y,int halflen):Figura(x,y,halflen){}        //конструктор(использует родительский конструктор)
};

#endif // FIGURA_H
