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

#endif // FIGURA_H
