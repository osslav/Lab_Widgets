#include "timerpaintwidget.h"
#include <QTextCodec>
#include <QBoxLayout>

TimerPaintWidget::TimerPaintWidget(QWidget *parent)                             //конструктор виджета
    : QWidget(parent)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));    //установка кодека для локализации на русском
    this->setWindowTitle("Обработка событий");                                  //установка заголовка окна
    area = new Area(this);                                                      //создание виджета Area на текущем виджете
    exitButton = new QPushButton("Завершить",this );                            //создание кнопки на текущем виджете
    QVBoxLayout *layout = new QVBoxLayout(this);                                //создание вертикальной разметки на текущем виджете

    layout->addWidget(area);                                                    //помещение на вертикальную разметку зону с фигурами и кнопку
    layout->addWidget(exitButton);

    connect(exitButton, SIGNAL(clicked(bool)),this,SLOT(close()));              //подключение сигнала нажатия кнопки к слоту закрытия окна
}


