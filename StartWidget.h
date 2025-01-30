#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>

class StartWidget : public QWidget
{
    Q_OBJECT

public:
    StartWidget(QWidget *parent = nullptr);
    ~StartWidget();

signals:
    void alertMaxWidth();

public slots:
    void changeWidth(int value);
    void openLoginDialog();
    void writeMaxWidth();

private:
    QPushButton *_buttonQuit, *_buttonDialog;
    QLCDNumber *_lcd;
    QSlider *_slider;

};
