#ifndef COUNTERWIDGET_H
#define COUNTERWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class CounterLine:public QLineEdit
{
    Q_OBJECT
public:
    CounterLine(const QString & contents, QWidget *parent=0):
    QLineEdit(contents,parent){}

signals:
    void multipleFiveSignal();

public slots:
    void addOne();

};

class CounterWidget : public QWidget
{
    Q_OBJECT

public:
    CounterWidget(QWidget *parent = nullptr);

private:
    QLabel *labelCount,*labelCountByFive;
    CounterLine *lineCount,*lineCountByFive;
    QPushButton *addOneButton;
    QPushButton *exitButton;
};
#endif // COUNTERWIDGET_H
