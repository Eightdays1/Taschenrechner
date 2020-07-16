#include "TaschenrechnerV2.h"
#include <QtCore>
#include <QKeyEvent>
#include <QApplication>
#include "windows.h"
#include "Controller.h"

std::string sInputString;
calculator::Controller controller;

TaschenrechnerV2::TaschenrechnerV2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    controller = calculator::Controller(this);
    ui.resultLabel->setText("0");
    ui.inputLabel->setText("0");
    connect(ui.pushButton_number0, SIGNAL(released()), this, SLOT(buttonPressed0()));
    connect(ui.pushButton_number1, SIGNAL(released()), this, SLOT(buttonPressed1()));
    connect(ui.pushButton_number2, SIGNAL(released()), this, SLOT(buttonPressed2()));
    connect(ui.pushButton_number3, SIGNAL(released()), this, SLOT(buttonPressed3()));
    connect(ui.pushButton_number4, SIGNAL(released()), this, SLOT(buttonPressed4()));
    connect(ui.pushButton_number5, SIGNAL(released()), this, SLOT(buttonPressed5()));
    connect(ui.pushButton_number6, SIGNAL(released()), this, SLOT(buttonPressed6()));
    connect(ui.pushButton_number7, SIGNAL(released()), this, SLOT(buttonPressed7()));
    connect(ui.pushButton_number8, SIGNAL(released()), this, SLOT(buttonPressed8()));
    connect(ui.pushButton_number9, SIGNAL(released()), this, SLOT(buttonPressed9()));
    connect(ui.pushButton_plus, SIGNAL(released()), this, SLOT(buttonPressedPlus()));
    connect(ui.pushButton_minus, SIGNAL(released()), this, SLOT(buttonPressedMinus()));
    connect(ui.pushButton_by, SIGNAL(released()), this, SLOT(buttonPressedBy()));
    connect(ui.pushButton_times, SIGNAL(released()), this, SLOT(buttonPressedTimes()));
    connect(ui.pushButton_power, SIGNAL(released()), this, SLOT(buttonPressedPower()));
    connect(ui.pushButton_bracketOpen, SIGNAL(released()), this, SLOT(buttonPressedBracketOpen()));
    connect(ui.pushButton_bracketClose, SIGNAL(released()), this, SLOT(buttonPressedBracketClose()));
    connect(ui.pushButton_enter, SIGNAL(released()), this, SLOT(buttonPressedEnter()));
    connect(ui.pushButton_clear, SIGNAL(released()), this, SLOT(buttonPressedClear()));
    connect(ui.pushButton_deleteNum, SIGNAL(released()), this, SLOT(buttonPressedDeleteLastNum()));
    connect(ui.pushButton_dot, SIGNAL(released()), this, SLOT(buttonPressedDot()));
    connect(ui.pushButton_history, SIGNAL(released()), this, SLOT(buttonPressedHistory()));
    connect(ui.pushButton_ans, SIGNAL(released()), this, SLOT(buttonPressedAns()));
    connect(ui.pushButton_changeNum, SIGNAL(released()), this, SLOT(buttonPressedChangeSign()));
}

//KeyEvent if key is released

void TaschenrechnerV2::keyReleaseEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_0) buttonPressed0();
    else if (event->key() == Qt::Key_1) buttonPressed1();
    else if (event->key() == Qt::Key_2) buttonPressed2();
    else if (event->key() == Qt::Key_3) buttonPressed3();
    else if (event->key() == Qt::Key_4) buttonPressed4();
    else if (event->key() == Qt::Key_5) buttonPressed5();
    else if (event->key() == Qt::Key_6) buttonPressed6();
    else if (event->key() == Qt::Key_7) buttonPressed7();
    else if (event->key() == Qt::Key_8) buttonPressed8();
    else if (event->key() == Qt::Key_9) buttonPressed9();
    else if (event->key() == Qt::Key_Plus) buttonPressedPlus();
    else if (event->key() == Qt::Key_Minus) buttonPressedMinus();
    else if (event->key() == Qt::Key_ParenLeft) buttonPressedBracketOpen();
    else if (event->key() == Qt::Key_ParenRight) buttonPressedBracketClose();
    else if (event->key() == Qt::Key_Asterisk) buttonPressedTimes();
    else if (event->key() == Qt::Key_Slash) buttonPressedBy();
    else if (event->key() == Qt::Key_Enter) buttonPressedEnter();
    else if (event->key() == Qt::Key_AsciiCircum) buttonPressedPower();
    else if (event->key() == Qt::Key_Period) buttonPressedDot();
    else if (event->key() == Qt::Key_Comma) buttonPressedDot();
    else if (event->key() == Qt::Key_Backspace) buttonPressedDeleteLastNum();
    else if (event->key() == Qt::Key_Delete) buttonPressedClear();
}

//Output-Slots

void TaschenrechnerV2::showInput(QString pString) {
    //Ausgabe Input-Feld
    ui.inputLabel->setText(pString);
}

void TaschenrechnerV2::showResult(QString pString) {
    //Ausgabe Output-Feld
    ui.resultLabel->setText(pString);
}

//Input-Slots

void TaschenrechnerV2::buttonPressed0()
{
    controller.registerInput("0");
}

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

void TaschenrechnerV2::buttonPressedBracketOpen()
{
    controller.registerInput("(");
}

void TaschenrechnerV2::buttonPressedBracketClose()
{
    controller.registerInput(")");
}

void TaschenrechnerV2::buttonPressedEnter()
{
    controller.registerInput("enter");
}

void TaschenrechnerV2::buttonPressedClear()
{
    controller.registerInput("clear");
}

void TaschenrechnerV2::buttonPressedDeleteLastNum()
{
    controller.registerInput("deleteLastNum");
}

void TaschenrechnerV2::buttonPressedDot()
{
    controller.registerInput(".");
}

void TaschenrechnerV2::buttonPressedHistory()
{
    controller.registerInput("history");
}

void TaschenrechnerV2::buttonPressedAns()
{
    controller.registerInput("ans");
}

void TaschenrechnerV2::buttonPressedChangeSign() {
    controller.registerInput("X");
}

