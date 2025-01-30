#include <QApplication>
#include <StartWidget.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    StartWidget m;
    m.show();

    return app.exec();
}
