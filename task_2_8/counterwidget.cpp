#include "counterwidget.h"

void CounterLine::addOne()
{
    QString textInLine = text();
    int numberInLine = textInLine.toInt();

    if (numberInLine !=0 && numberInLine % 5 == 0)
        emit multipleFiveSignal();

    numberInLine++;
    textInLine.setNum(numberInLine);
    setText(textInLine);
}

CounterWidget::CounterWidget(QWidget *parent)
    : QWidget(parent)
{
}

CounterWidget::~CounterWidget()
{
}

