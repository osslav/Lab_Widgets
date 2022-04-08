#ifndef TIMERPAINTWIDGET_H
#define TIMERPAINTWIDGET_H

#include <QWidget>

class TimerPaintWidget : public QWidget
{
    Q_OBJECT

public:
    TimerPaintWidget(QWidget *parent = nullptr);
    ~TimerPaintWidget();
};
#endif // TIMERPAINTWIDGET_H
