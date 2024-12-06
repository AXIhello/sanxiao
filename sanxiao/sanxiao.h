#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_sanxiao.h"

class sanxiao : public QMainWindow
{
    Q_OBJECT

public:
    sanxiao(QWidget *parent = nullptr);
    ~sanxiao();

private:
    Ui::sanxiaoClass ui;
};
