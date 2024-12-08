#ifndef MAINMENUWIDGET_H
#define MAINMENUWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include"ui_MainWindow.h"

class LoginWidget;  // 前置声明登录界面类

class MainMenuWidget : public QWidget {
    Q_OBJECT

public:
    MainMenuWidget(QWidget* parent = nullptr, Ui::MainWindow* ui=nullptr);

signals:
    void startGame();

private:
    /*QPushButton* btnStart;
    QPushButton* btnHelp;
    QPushButton* btnAbout;*/
    Ui::MainWindow* mainui;
    LoginWidget* loginWidget;  // 用于存储登录界面指针
};

#endif // MAINMENUWIDGET_H