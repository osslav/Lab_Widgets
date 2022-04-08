#ifndef COUNTERWIDGET_H
#define COUNTERWIDGET_H

#include <QWidget>

class CounterWidget : public QWidget
{
    Q_OBJECT

public:
    CounterWidget(QWidget *parent = nullptr);
    ~CounterWidget();
};
#endif // COUNTERWIDGET_H
