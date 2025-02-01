#include <Form.h>
#include <QApplication>

Form::Form(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(300, 200);

    _name = new QLineEdit(this);
    _email = new QLineEdit(this);
    _password = new QLineEdit(this);
    _submitButton = new QPushButton("Submit", this);
    _loginForm = new QFormLayout(this);

    _loginForm->addRow("Name : ", _name);
    _loginForm->addRow("Email : ", _email);
    _loginForm->addRow("Password : ", _password);
    _loginForm->addWidget(_submitButton);

    QObject::connect(_submitButton, SIGNAL(clicked(bool)), this, SLOT(submitForm()));

}

void Form::submitForm()
{
    qApp->quit();
}

