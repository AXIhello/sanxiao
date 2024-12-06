#include "sanxiao.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sanxiao w;
    w.show();
    return a.exec();
}
