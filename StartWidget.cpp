#include "qcoreapplication.h"
#include "qmessagebox.h"
#include <StartWidget.h>

StartWidget::StartWidget(QWidget* parent)
    : QWidget(parent)
{
    // WINDOW
    setFixedSize(250, 250 * 0.6);

    // DIALOG
    _buttonDialog = new QPushButton("Login", this);
    _buttonDialog->setFont(QFont("Courier", 15));
    _buttonDialog->move(10, 10);
    QObject::connect(_buttonDialog, SIGNAL(clicked(bool)), this, SLOT(openLoginDialog()));

    // QUIT
    _buttonQuit = new QPushButton("Quit", this);
    _buttonQuit->setFont(QFont("Courier", 15));
    _buttonQuit->move(100, 10);
    QObject::connect(_buttonQuit, SIGNAL(clicked(bool)), qApp, SLOT(quit()));

    // LCD
    _lcd = new QLCDNumber(this);
    _lcd->setSegmentStyle(QLCDNumber::Flat);
    _lcd->move(10, 50);



    _slider = new QSlider(Qt::Horizontal, this);
    _slider->setGeometry(10, 80, 100, 30);
    _slider->setRange(250, 800);
    QObject::connect(_slider, SIGNAL(valueChanged(int)), _lcd, SLOT(display(int)));
    QObject::connect(_slider, SIGNAL(valueChanged(int)), this, SLOT(changeWidth(int)));
    QObject::connect(this, SIGNAL(alertMaxWidth()), this, SLOT(writeMaxWidth()));
}

StartWidget::~StartWidget() {}

void StartWidget::changeWidth(int value)
{
    setFixedWidth(value);
    setFixedHeight(value * 0.6);

    if(value >= 800)
    {
        emit alertMaxWidth();
    }
}

void StartWidget::openLoginDialog()
{
    int response = QMessageBox::information(this, "Login window", "Are you a <strong>member</strong> ?", QMessageBox::Yes | QMessageBox::No);
    if(response == QMessageBox::Yes)
        QMessageBox::information(this, "Login", "Enter tour login");
    else if(response == QMessageBox::No)
    {
        QMessageBox::warning(this, "Quit message", "Oww ! Quit the program now ;)");
        qApp->quit();
    }
}

void StartWidget::writeMaxWidth()
{
    qDebug("Max width !");
}
