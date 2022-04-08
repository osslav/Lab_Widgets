#include "figura.h"
#include <math.h>

void Figura::move(float Alpha,QPainter *Painter)            //функция движения фугуры(изменения угла наклона)
{
    dx=halfLength*cos(Alpha);                               //расчет вектора (dx, dy), задающего угол наклона через тригонометрические функции
    dy=halfLength*sin(Alpha);
    draw(Painter);                                          //отрисовка фигуры с новыми параметрами
}
