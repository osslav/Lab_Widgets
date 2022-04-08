#include "counterwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CounterWidget w;
    w.show();
    return a.exec();
}
