#include "counterwidget.h"
#include <QTextCodec>
#include <QBoxLayout>

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
     QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));

     this->setWindowTitle("Счетчик");
     labelCount = new QLabel("Cчет по 1",this);
     labelCountByFive = new QLabel("Cчет по 5",this);
     lineCount = new CounterLine("0",this);
     lineCountByFive = new CounterLine("0",this);

     addOneButton=new QPushButton("+1",this);
     exitButton=new QPushButton("Выход",this);

     QHBoxLayout *hLayoutTitles = new QHBoxLayout();
     hLayoutTitles->addWidget(labelCount);
     hLayoutTitles->addWidget(labelCountByFive);

     QHBoxLayout *hLayoutOutputLines = new QHBoxLayout();
     hLayoutOutputLines->addWidget(lineCount);
     hLayoutOutputLines->addWidget(lineCountByFive);

     QHBoxLayout *hLayoutButtons = new QHBoxLayout();
     hLayoutButtons->addWidget(addOneButton);
     hLayoutButtons->addWidget(exitButton);

     QVBoxLayout *mainLayout = new QVBoxLayout(this);
     mainLayout->addLayout(hLayoutTitles);
     mainLayout->addLayout(hLayoutOutputLines);
     mainLayout->addLayout(hLayoutButtons);
     mainLayout->addStretch();
}



