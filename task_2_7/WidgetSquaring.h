#ifndef WIDGETSQUARING_H
#define WIDGETSQUARING_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class WidgetSquaring; }
QT_END_NAMESPACE

class WidgetSquaring : public QWidget
{
    Q_OBJECT

public:
    WidgetSquaring(QWidget *parent = nullptr);
    ~WidgetSquaring() {}

public slots:
    void reset();

private:
    QFrame *frame;

    QLabel *inputTitle;
    QLineEdit *inputEdit;

    QLabel *outputTitle;
    QLineEdit *outputEdit;

    QPushButton *nextButton;
    QPushButton *exitButton;

};
#endif // MAINWINDOW_H
