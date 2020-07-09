#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TaschenrechnerV2.h"

class TaschenrechnerV2 : public QMainWindow
{
    Q_OBJECT

public:
    TaschenrechnerV2(QWidget *parent = Q_NULLPTR);
    
    void showInput(QString pstring);
    void showResult(QString pString);

    void buttonPressed1();
    void buttonPressed2();
    void buttonPressed3();
    void buttonPressed4();
    void buttonPressed5();
    void buttonPressed6();
    void buttonPressed7();
    void buttonPressed8();
    void buttonPressed9();
    void buttonPressed0();
    void buttonPressedPlus();
    void buttonPressedMinus();
    void buttonPressedTimes();
    void buttonPressedBy();
    void buttonPressedPower();
    void buttonPressedEnter();

private:
    Ui::TaschenrechnerV2Class ui;
};
