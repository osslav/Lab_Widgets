#include "timerpaintwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimerPaintWidget w;
    w.show();
    return a.exec();
}
