#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), gamePanelWidget(nullptr), loginWidget(nullptr)
{
    ui->setupUi(this);

    // ��ʼ����Ϸ��壬������ʾ
    gamePanelWidget = new GamePanelWidget(this);
    gamePanelWidget->hide();

    // �������˵���ť���ź����
    connect(ui->btnStart, &QPushButton::clicked, this, &MainWindow::onStartButtonClicked);
    connect(ui->btnHelp, &QPushButton::clicked, this, &MainWindow::onHelpButtonClicked);
    connect(ui->btnAbout, &QPushButton::clicked, this, &MainWindow::onAboutButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ��ʼ��ť����ۺ���
void MainWindow::onStartButtonClicked()
{
    // ��ʾ��¼����
    loginWidget = new LoginWidget(this);
    loginWidget->show();

    // ���ӵ�¼�ɹ��ź�
    connect(loginWidget, &LoginWidget::loginSuccess, this, &MainWindow::onLoginSuccess);
}

// ��¼�ɹ�����ô˺���
void MainWindow::onLoginSuccess()
{
    loginWidget->close();
    delete loginWidget;
    loginWidget = nullptr;

    // ��ʾ��Ϸ���
    gamePanelWidget->show();
    setCentralWidget(gamePanelWidget);
}

// ������ť����ۺ���
void MainWindow::onHelpButtonClicked()
{
    QMessageBox::information(this, "Help", "This is help information.");
}

// ���ڰ�ť����ۺ���
void MainWindow::onAboutButtonClicked()
{
    QMessageBox::information(this, "About", "This is about information.");
}
