#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TaschenrechnerV2.h"

class TaschenrechnerV2 : public QMainWindow
{
    Q_OBJECT

public:
    TaschenrechnerV2(QWidget *parent = Q_NULLPTR);

    showInput(std::string pString);
    showResult(std::string pString);

private:
    Ui::TaschenrechnerV2Class ui;
};
