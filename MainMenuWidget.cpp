#include "MainMenuWidget.h"
#include <QMessageBox>
#include <QVBoxLayout>

// 实现MainMenuWidget类的构造函数
MainMenuWidget::MainMenuWidget(QWidget* parent)
    : QWidget(parent)
{
    // 通过使用界面元素的名字（和xml中定义的对应）找到对应的按钮控件
    btnStart = findChild<QPushButton*>("pushButton");
    btnHelp = findChild<QPushButton*>("pushButton_2");
    btnAbout = findChild<QPushButton*>("pushButton_3");

    // 创建垂直布局并将按钮添加到布局中
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(btnStart);
    layout->addWidget(btnHelp);
    layout->addWidget(btnAbout);

    // 连接按钮点击信号到相应的槽函数
    connect(btnStart, &QPushButton::clicked, this, &MainMenuWidget::startGame);
    connect(btnHelp, &QPushButton::clicked, [this]() {
        QMessageBox::information(this, "help", "this is a help message.");
        });
    connect(btnAbout, &QPushButton::clicked, [this]() {
        QMessageBox::information(this, "about", "this is a about message.");
        });
}