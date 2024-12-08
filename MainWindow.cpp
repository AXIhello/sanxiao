#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // 设置 UI
    mainMenuWidget = new MainMenuWidget(this,ui); // 创建主菜单
    gamePanelWidget = new GamePanelWidget(this); // 创建游戏面板

    // 初始先隐藏游戏面板
    gamePanelWidget->hide();

    setCentralWidget(mainMenuWidget); // 初始显示主菜单

    // 连接信号与槽
    connect(mainMenuWidget, &MainMenuWidget::startGame, this, [this]() {
        // 先隐藏主菜单
        mainMenuWidget->hide();
        // 显示游戏面板
        gamePanelWidget->show();
        setCentralWidget(gamePanelWidget);
        });
}

MainWindow::~MainWindow()
{
    delete ui; // 删除 ui 变量的内存
}