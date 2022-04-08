#ifndef TIMERPAINTWIDGET_H
#define TIMERPAINTWIDGET_H

#include <QWidget>
#include "area.h"
#include <QPushButton>

class TimerPaintWidget : public QWidget             //виджет, содержащий виджет Area
{
    Q_OBJECT                                        //подключение к классу сигналов и слотов

public:
    TimerPaintWidget(QWidget *parent = nullptr);

protected:
    Area * area;                                    // область отображения рисунка
    QPushButton * exitButton;                       //кнопка закрытия виджета
};
#endif // TIMERPAINTWIDGET_H
