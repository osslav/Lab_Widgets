#include "WidgetSquaring.h"                                                         //подключение объвления класса и необходимых библиотек
#include <QBoxLayout>
#include <QMessageBox>
#include <QTextCodec>

WidgetSquaring::WidgetSquaring(QWidget *parent)                                     //конструктор реализуемого виджета(с указанием родительского виджета)
    : QWidget(parent)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));        //установка кодека для локализации виджета на русский язык

    setWindowTitle("Возведение в квадрат");                                         //установка заголовка окна с виджетом

    frame = new QFrame(this);                                                       //создание рамки
    frame->setFrameShadow(QFrame::Raised);                                          //установка ее внешнего вида как в скриншоте в задании
    frame->setFrameShape(QFrame::Panel);

    inputTitle = new QLabel("Введите число:", this);                                //создание заголовка над строкой ввода
    inputEdit = new QLineEdit("",this);                                             //создание строки ввода

    outputTitle = new QLabel("Результат:", this);                                   //создание заголовка над строкой вывода
    outputEdit = new QLineEdit("",this);                                            //создание строки вывода

    nextButton = new QPushButton("Следующее", this);                                //создание кнопки для очистки виджета от предыдущей операции
    exitButton = new QPushButton("Выход", this);                                    //создание кнопки для закрытия виджета

    QVBoxLayout *vLayoutForNumbers = new QVBoxLayout(frame);                        //создаем в рамке вертикальную разметку
    vLayoutForNumbers->addWidget(inputTitle);                                       //и помещаем в нее строки ввода и вывода и их заголовки
    vLayoutForNumbers->addWidget(inputEdit);
    vLayoutForNumbers->addWidget(outputTitle);
    vLayoutForNumbers->addWidget(outputEdit);
    vLayoutForNumbers->addStretch();                                                //добавляем растягиваемое пространство
                                                                                    //(чтобы виджеты не съезжали при масштабировании окна)

    QVBoxLayout *vLayoutForButtons = new QVBoxLayout();                             //аналогично создаем вертикальную разметку с кнопками
    vLayoutForButtons->addWidget(nextButton);
    vLayoutForButtons->addWidget(exitButton);
    vLayoutForButtons->addStretch();

    QHBoxLayout *hLayoutGeneral = new QHBoxLayout(this);                            //создаем горизонтальную разметку в реализуемом виджете
    hLayoutGeneral->addWidget(frame);                                               //помещаем туда рамку(в которой строки для ввода-вывода)
    hLayoutGeneral->addLayout(vLayoutForButtons);                                   //помещаем туда разметку с кнопками

    reset();                                                                        //вызываем слот reset для подготовки виджета к вводу

    connect(exitButton,SIGNAL(clicked(bool)), this,SLOT(close()));                  //поключение кнопки "выход" к слоту закрытия виджета
    connect(nextButton,SIGNAL(clicked(bool)), this,SLOT(reset()));                  //кнопка "следующее" подключается к слоту очистки виджета и подготовки ео к следующему вводу
    connect(inputEdit,SIGNAL(returnPressed()), this,SLOT(calculate()));             //нажатие клавиши "enter" в строке ввода подключается в вычислению результата
}

void WidgetSquaring::reset()                                                        //слот для очитки виджета и подготовки его к новому вычислению
{
    nextButton->setEnabled(false);                                                  //отключаем кнопку "следующее"
    nextButton->setDefault(false);                                                  //делаем ее кнопкой НЕ по умолчанию(то есть клавиша "enter" не задействует ее)

    inputEdit->clear();                                                             //очищаем строку ввода
    inputEdit->setEnabled(true);                                                    //подключаем ее(делаем доступной для ввода)

    outputTitle->setVisible(false);                                                 //скрываем заголовок над строкой вывода

    outputEdit->setVisible(false);                                                  //скрываем строку вывода
    outputEdit->setEnabled(false);                                                  //делаем строку вывода недоступной

    inputEdit->setFocus();                                                          //фокус устанавливается на строку ввода
}

double WidgetSquaring::squaring(double input)                                       //функция вычисления квадрата числа
{
    return input*input;                                                             //возвращаем квадрат числа
}

void WidgetSquaring::calculate()                                                    //слот для вычисления
{
    bool isNumberFoundCorrect = true;                                               //создаем флаг - корректен ли ввод?
    double resultNumber, inputNumber;                                               //переменные для ввода и результата вычислений
    QString str=inputEdit->text();                                                  //копируем текст из строки ввода в строку QString
    inputNumber = str.toDouble(&isNumberFoundCorrect);                              //конвертация строки в число(с проверкой коректности строки для этого)
    if (isNumberFoundCorrect)                                                       //если ввод корректен то
    {
        resultNumber = squaring(inputNumber);                                       //вычисляем квадрат числа
        str.setNum(resultNumber);                                                   //записываем число в строку
        outputEdit->setText(str);                                                   //строку с числом записываем в строку вывода в виджете
        inputEdit->setEnabled(false);                                               //отключаем строку ввода
        outputTitle->setVisible(true);                                              //теперь видны строка ввода и ее заголовок
        outputEdit->setVisible(true);
        nextButton->setDefault(true);                                               //кнопка "следующее" доступна и становится кнопкой по умолчанию
        nextButton->setEnabled(true);
        nextButton->setFocus();                                                     //фокус устанавливается на кнопку "следующее"
    }
    else
        if (!str.isEmpty())                                                         //иначе и если строка ввода не пуста
        {
            QMessageBox msgBox(QMessageBox::Information, "Возведение в квадрат", "Ошибка! В строке ввода найдены некорретные симолы", QMessageBox::Ok);         //создаем окно с ошибкой
            msgBox.exec();                                                                                                                                      //выводим окно с ошибкой
        }
}
