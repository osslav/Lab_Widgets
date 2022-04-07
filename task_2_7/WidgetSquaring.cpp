#include "WidgetSquaring.h"
#include <QBoxLayout>

WidgetSquaring::WidgetSquaring(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Squaring a number");

    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Box);//Panel);

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
}

WidgetSquaring::~WidgetSquaring()
{

}

