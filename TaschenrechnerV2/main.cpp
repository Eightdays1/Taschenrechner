#include "TaschenrechnerV2.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TaschenrechnerV2 w;
    w.setWindowIcon(QIcon(":/TaschenrechnerV2/Image1.bmp"));
    w.show();
    return a.exec();
}
