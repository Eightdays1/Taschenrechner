#include "TaschenrechnerV2.h"
#include <QtCore>
#include "windows.h"
#include "Controller.h"

TaschenrechnerV2::TaschenrechnerV2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    calculator::Controller c1;
    ui.debugLabel->setText(c1.calculate("20+3-50*8"));

}
