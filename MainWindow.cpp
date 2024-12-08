#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), gamePanelWidget(nullptr), loginWidget(nullptr)
{
    ui->setupUi(this);

    // 初始化游戏面板，但不显示
    gamePanelWidget = new GamePanelWidget(this);
    gamePanelWidget->hide();

    // 连接主菜单按钮的信号与槽
    connect(ui->btnStart, &QPushButton::clicked, this, &MainWindow::onStartButtonClicked);
    connect(ui->btnHelp, &QPushButton::clicked, this, &MainWindow::onHelpButtonClicked);
    connect(ui->btnAbout, &QPushButton::clicked, this, &MainWindow::onAboutButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 开始按钮点击槽函数
void MainWindow::onStartButtonClicked()
{
    // 显示登录界面
    loginWidget = new LoginWidget(this);
    loginWidget->show();

    // 连接登录成功信号
    connect(loginWidget, &LoginWidget::loginSuccess, this, &MainWindow::onLoginSuccess);
}

// 登录成功后调用此函数
void MainWindow::onLoginSuccess()
{
    loginWidget->close();
    delete loginWidget;
    loginWidget = nullptr;

    // 显示游戏面板
    gamePanelWidget->show();
    setCentralWidget(gamePanelWidget);
}

// 帮助按钮点击槽函数
void MainWindow::onHelpButtonClicked()
{
    QMessageBox::information(this, "Help", "This is help information.");
}

// 关于按钮点击槽函数
void MainWindow::onAboutButtonClicked()
{
    QMessageBox::information(this, "About", "This is about information.");
}
