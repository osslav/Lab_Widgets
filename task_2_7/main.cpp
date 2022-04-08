#include "WidgetSquaring.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WidgetSquaring w;
    w.show();
    return a.exec();
}
