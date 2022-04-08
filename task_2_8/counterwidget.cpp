#include "counterwidget.h"
#include <QTextCodec>
#include <QBoxLayout>

void CounterLine::addOne()                                          //слот, добавляющий 1 к счетчику
{
    QString textInLine = text();                                    //считываем текст из счетчика
    int numberInLine = textInLine.toInt();                          //конвертация текста в число(проверки нет, т к пользователь ничего не вводит туда)

    if (numberInLine !=0 && numberInLine % 5 == 0)                  //если число счетчика кратно 5, то вызывается соответсвующий сигнал
        emit multipleFiveSignal();

    numberInLine++;                                                 //добавляем 1 к числу из счетчика
    textInLine.setNum(numberInLine);                                //конвертируем это число обратно в строку
    setText(textInLine);                                            //записываем строку в счетчик
}

CounterWidget::CounterWidget(QWidget *parent)                       //конструктор создания виджета(получает родительский виджет, если он есть)
    : QWidget(parent)
{
     QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));       //установка кодека для русификации виджета

     this->setWindowTitle("Счетчик");                               //установка заголовка виджета
     labelCount = new QLabel("Cчет по 1",this);                     //создание заголовка над счетчиком, считающим по 1
     labelCountByFive = new QLabel("Cчет по 5",this);               //создание заголовка над счетчиком, считающим по 5
     lineCount = new CounterLine("0",this);                         //создание 2-х счетчиков - для счета по 1 и по 5
     lineCountByFive = new CounterLine("0",this);

     addOneButton=new QPushButton("+1",this);                       //создание кнопки для добавления 1
     exitButton=new QPushButton("Выход",this);                      //создание кнопки для выхода

     QHBoxLayout *hLayoutTitles = new QHBoxLayout();                //создание разметки для заголовков и помещение их туда
     hLayoutTitles->addWidget(labelCount);
     hLayoutTitles->addWidget(labelCountByFive);

     QHBoxLayout *hLayoutOutputLines = new QHBoxLayout();           //создание разметки для счетчиков и помещение их туда
     hLayoutOutputLines->addWidget(lineCount);
     hLayoutOutputLines->addWidget(lineCountByFive);

     QHBoxLayout *hLayoutButtons = new QHBoxLayout();               //создание разметки для кнопок и помещение их туда
     hLayoutButtons->addWidget(addOneButton);
     hLayoutButtons->addWidget(exitButton);

     QVBoxLayout *mainLayout = new QVBoxLayout(this);               //создание главной разметки для виджета и помещение туда всех созданных ранее разметок с объектами
     mainLayout->addLayout(hLayoutTitles);
     mainLayout->addLayout(hLayoutOutputLines);
     mainLayout->addLayout(hLayoutButtons);
     mainLayout->addStretch();                                      //добавление отступа в главный виджет для корректного отображения при масштабировании окна

     //подключение сигнала с нажатия кнопки к счетчику, считающему по 1 эти нажатия
     connect(addOneButton,SIGNAL(clicked(bool)), lineCount,SLOT(addOne()));
     //подключение сигнала счетчика(сигнал срабатывает каждое 5 увеличение этого счетчика) к счетчику, считающему каждое 5 нажатие кнопки
     connect(lineCount,SIGNAL(multipleFiveSignal()), lineCountByFive,SLOT(addOne()));
     //подключение кнопки "выход" к слоту закрытия виджета
     connect(exitButton,SIGNAL(clicked(bool)), this,SLOT(close()));
}



