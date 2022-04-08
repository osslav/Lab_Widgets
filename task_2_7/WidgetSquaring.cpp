#include "WidgetSquaring.h"
#include <QBoxLayout>
#include <QMessageBox>
#include <QTextCodec>

WidgetSquaring::WidgetSquaring(QWidget *parent)
    : QWidget(parent)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));

    setWindowTitle("Возведение в квадрат");

    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);

    inputTitle = new QLabel("Введите число:", this);
    inputEdit = new QLineEdit("",this);

    outputTitle = new QLabel("Результат:", this);
    outputEdit = new QLineEdit("",this);

    nextButton = new QPushButton("Следующее", this);
    exitButton = new QPushButton("Выход", this);

    QVBoxLayout *vLayoutForNumbers = new QVBoxLayout(frame);
    vLayoutForNumbers->addWidget(inputTitle);
    vLayoutForNumbers->addWidget(inputEdit);
    vLayoutForNumbers->addWidget(outputTitle);
    vLayoutForNumbers->addWidget(outputEdit);
    vLayoutForNumbers->addStretch();

    QVBoxLayout *vLayoutForButtons = new QVBoxLayout();
    vLayoutForButtons->addWidget(nextButton);
    vLayoutForButtons->addWidget(exitButton);
    vLayoutForButtons->addStretch();

    QHBoxLayout *hLayoutGeneral = new QHBoxLayout(this);
    hLayoutGeneral->addWidget(frame);
    hLayoutGeneral->addLayout(vLayoutForButtons);

    reset();

    connect(exitButton,SIGNAL(clicked(bool)), this,SLOT(close()));
    connect(nextButton,SIGNAL(clicked(bool)), this,SLOT(reset()));
    connect(inputEdit,SIGNAL(returnPressed()), this,SLOT(calculate()));
}

void WidgetSquaring::reset()
{
    nextButton->setEnabled(false);
    nextButton->setDefault(false);

    inputEdit->clear();
    inputEdit->setEnabled(true);

    outputTitle->setVisible(false);

    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);

    inputEdit->setFocus();
}

double WidgetSquaring::squaring(double input)
{
    return input*input;
}

void WidgetSquaring::calculate()
{
    bool isNumberFoundCorrect = true;
    double resultNumber, inputNumber;
    QString str=inputEdit->text();
    inputNumber = str.toDouble(&isNumberFoundCorrect);
    if (isNumberFoundCorrect)
    {
        resultNumber = squaring(inputNumber);
        str.setNum(resultNumber);
        outputEdit->setText(str);
        inputEdit->setEnabled(false);
        outputTitle->setVisible(true);
        outputEdit->setVisible(true);
        nextButton->setDefault(true);
        nextButton->setEnabled(true);
        nextButton->setFocus();
    }
    else
        if (!str.isEmpty())
        {
            QMessageBox msgBox(QMessageBox::Information, "Возведение в квадрат", "Ошибка! В строке ввода найдены некорретные симолы", QMessageBox::Ok);
            msgBox.exec();
        }
}
