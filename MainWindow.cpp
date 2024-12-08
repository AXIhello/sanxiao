#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // ���� UI
    mainMenuWidget = new MainMenuWidget(this,ui); // �������˵�
    gamePanelWidget = new GamePanelWidget(this); // ������Ϸ���

    // ��ʼ��������Ϸ���
    gamePanelWidget->hide();

    setCentralWidget(mainMenuWidget); // ��ʼ��ʾ���˵�

    // �����ź����
    connect(mainMenuWidget, &MainMenuWidget::startGame, this, [this]() {
        // ���������˵�
        mainMenuWidget->hide();
        // ��ʾ��Ϸ���
        gamePanelWidget->show();
        setCentralWidget(gamePanelWidget);
        });
}

MainWindow::~MainWindow()
{
    delete ui; // ɾ�� ui �������ڴ�
}