#include "MainMenuWidget.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include "LoginWidget.h"  // 包含登录界面头文件

MainMenuWidget::MainMenuWidget(QWidget* parent)
    : QWidget(parent)
{
    btnStart = findChild<QPushButton*>("pushButton");
    btnHelp = findChild<QPushButton*>("pushButton_2");
    btnAbout = findChild<QPushButton*>("pushButton_3");

    // 创建垂直布局并将按钮添加到布局中
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(btnStart);
    layout->addWidget(btnHelp);
    layout->addWidget(btnAbout);

    // 连接按钮点击信号到相应的槽函数
    connect(btnStart, &QPushButton::clicked, this, [this]() {
        // 创建登录界面实例
        loginWidget = new LoginWidget(this);
        // 连接登录成功信号到发送开始游戏信号
        connect(loginWidget, &LoginWidget::loginSuccess, this, &MainMenuWidget::startGame);
        // 显示登录界面
        loginWidget->show();
        });
    connect(btnHelp, &QPushButton::clicked, [this]() {
        QMessageBox::information(this, "help", "this is help information.");
        });
    connect(btnAbout, &QPushButton::clicked, [this]() {
        QMessageBox::information(this, "About", "this is about information.");
        });
}