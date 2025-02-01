#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QMessageBox>

class Form : public QWidget
{
    Q_OBJECT

public:
    Form(QWidget *parent = nullptr);

public slots:
    void submitForm();

private:
    QLineEdit *_name, *_email, *_password;
    QPushButton *_submitButton;
    QFormLayout *_loginForm;
};
