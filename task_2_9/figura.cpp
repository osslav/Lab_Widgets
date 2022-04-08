#include "figura.h"
#include <math.h>

void Figura::move(float Alpha,QPainter *Painter)            //функция движения фугуры(изменения угла наклона)
{
    dx=halfLength*cos(Alpha);                               //расчет вектора (dx, dy), задающего угол наклона через тригонометрические функции
    dy=halfLength*sin(Alpha);
    draw(Painter);                                          //отрисовка фигуры с новыми параметрами
}

void MyLine::draw(QPainter *Painter)                        //функция отрисовки линии, принимает объект для рисования
{
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy);                 //отрисовывает в нем линию с центром в (x, y), параллельную вектору (dx, dy)
}

void MyRect::draw(QPainter *Painter)                        //функция отрисовки прямоугольника, принимает объект для рисования
{
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);                 //отрисовка граней прямоугольника с центром в (x, y)
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy);                 //и диагональю, параллельной вектору (dx, dy) (другая диагональ перепендикулярна этому вектору)
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
