#ifndef WIDGETSQUARING_H
#define WIDGETSQUARING_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class WidgetSquaring; }
QT_END_NAMESPACE

class WidgetSquaring : public QWidget
{
    Q_OBJECT

public:
    WidgetSquaring(QWidget *parent = nullptr);
    ~WidgetSquaring();

private:

};
#endif // MAINWINDOW_H
