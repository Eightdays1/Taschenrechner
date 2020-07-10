#include "TaschenrechnerV2.h"
#include <QtCore>
#include "windows.h"
#include "Controller.h"

std::string sInputString;
calculator::Controller controller;

TaschenrechnerV2::TaschenrechnerV2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    controller = calculator::Controller(this);
    ui.debugLabel->setText(controller.calculate("2/0"));

}

//Output-Slots

void TaschenrechnerV2::showInput(QString pString) {
    //Ausgabe Input-Feld
}

void TaschenrechnerV2::showResult(QString pString) {
    //Ausgabe Output-Feld
    ui.debugLabel->setText(pString);
}

//Input-Slots

void TaschenrechnerV2::buttonPressed1()
{
    controller.registerInput("1");
}

void TaschenrechnerV2::buttonPressed2()
{
    controller.registerInput("2");
}

void TaschenrechnerV2::buttonPressed3()
{
    controller.registerInput("3");
}

void TaschenrechnerV2::buttonPressed4()
{
    controller.registerInput("4");
}

void TaschenrechnerV2::buttonPressed5()
{
    controller.registerInput("5");
}

void TaschenrechnerV2::buttonPressed6()
{
    controller.registerInput("6");
}

void TaschenrechnerV2::buttonPressed7()
{
    controller.registerInput("7");
}

void TaschenrechnerV2::buttonPressed8()
{
    controller.registerInput("8");
}

void TaschenrechnerV2::buttonPressed9()
{
    controller.registerInput("9");
}

void TaschenrechnerV2::buttonPressed0()
{
    controller.registerInput("0");
}

void TaschenrechnerV2::buttonPressedPlus()
{
    controller.registerInput("+");
}

void TaschenrechnerV2::buttonPressedMinus()
{
    controller.registerInput("-");
}

void TaschenrechnerV2::buttonPressedTimes()
{
    controller.registerInput("*");
}

void TaschenrechnerV2::buttonPressedBy()
{
    controller.registerInput("/");
}

void TaschenrechnerV2::buttonPressedPower()
{
    controller.registerInput("^");
}

void TaschenrechnerV2::buttonPressedEnter()
{
    controller.registerInput("enter");
}
