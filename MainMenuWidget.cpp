#include "MainMenuWidget.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include "LoginWidget.h"  // 包含登录界面头文件
#include "GamePanelWidget.h"  // 包含游戏面板界面头文件
#include"ui_MainWindow.h"
#include"MainWindow.h"

MainMenuWidget::MainMenuWidget(QWidget* parent, Ui::MainWindow* ui)
    : QWidget(parent),mainui(ui)
{
    //// 创建开始游戏按钮
    //btnStart = new QPushButton("start game", this);
    //btnStart->setGeometry(QRect(300, 240, 131, 61));
    ////// 设置样式等其他属性，这里省略具体样式设置代码

    //// 创建帮助按钮
    //btnHelp = new QPushButton("help", this);
    //btnHelp->setGeometry(QRect(300, 330, 131, 51));

    ////// 创建关于按钮
    //btnAbout = new QPushButton("about", this);
    //btnAbout->setGeometry(QRect(290, 430, 141, 51));

    ////// 创建垂直布局并将按钮添加到布局中
    //QVBoxLayout* layout = new QVBoxLayout(this);
    //layout->addWidget(btnStart);
    //layout->addWidget(btnHelp);
    //layout->addWidget(btnAbout);


    // 连接按钮点击信号到相应的槽函数
    connect(mainui->btnStart, &QPushButton::clicked, this, [this]() {
        // 创建登录界面实例
        LoginWidget* login = new LoginWidget(this);
        // 连接登录成功信号到发送开始游戏信号
        login->show();
        /*connect(loginWidget, &LoginWidget::loginSuccess, this, &MainMenuWidget::startGame);*/
       
       
       
        });
    connect(mainui->btnHelp, &QPushButton::clicked, [this]() {
        QMessageBox::information(this, "help", "this is help information.");
        });
    connect(mainui->btnAbout, &QPushButton::clicked, [this]() {
        QMessageBox::information(this, "About", "this is about information.");
        });
}