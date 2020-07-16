#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TaschenrechnerV2.h"
#include <QWidget>
#include <QtGui>

class TaschenrechnerV2 : public QMainWindow
{
    Q_OBJECT

public:
    TaschenrechnerV2(QWidget *parent = Q_NULLPTR);
    
    //output
    void showInput(QString pstring);
    void showResult(QString pString);

protected:
    void keyReleaseEvent(QKeyEvent*);

private slots:
    //input
    void buttonPressed0();
    void buttonPressed1();
    void buttonPressed2();
    void buttonPressed3();
    void buttonPressed4();
    void buttonPressed5();
    void buttonPressed6();
    void buttonPressed7();
    void buttonPressed8();
    void buttonPressed9();
    void buttonPressedPlus();
    void buttonPressedMinus();
    void buttonPressedTimes();
    void buttonPressedBy();
    void buttonPressedPower();
    void buttonPressedBracketOpen();
    void buttonPressedBracketClose();
    void buttonPressedEnter();
    void buttonPressedClear();
    void buttonPressedDeleteLastNum();
    void buttonPressedDot();
    void buttonPressedHistory();
    void buttonPressedAns();
    void buttonPressedChangeSign();

private:
    Ui::TaschenrechnerV2Class ui;
};
