#include "TaschenrechnerV2.h"
#include <QtCore>
#include "windows.h"
#include "Controller.h"

TaschenrechnerV2::TaschenrechnerV2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    calculator::Controller c1 = calculator::Controller(this);

    ui.debugLabel->setText(c1.calculate("20+3-50*8"));

}

void TaschenrechnerV2::showInput(std::string pString) {

}

void TaschenrechnerV2::showResult(std::string pString) {

}