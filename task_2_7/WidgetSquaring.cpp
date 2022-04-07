#include "WidgetSquaring.h"
#include <QBoxLayout>
#include <QMessageBox>

WidgetSquaring::WidgetSquaring(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Squaring a number");

    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);

    inputTitle = new QLabel("Enter number:", this);
    inputEdit = new QLineEdit("",this);

    outputTitle = new QLabel("Result:", this);
    outputEdit = new QLineEdit("",this);

    nextButton = new QPushButton("Next", this);
    exitButton = new QPushButton("Exit", this);

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
            QMessageBox msgBox(QMessageBox::Information, "Squaring a number", "Invalid value entered.", QMessageBox::Ok);
            msgBox.exec();
        }
}
