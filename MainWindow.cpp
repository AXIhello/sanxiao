#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // ���� UI
    mainMenuWidget = new MainMenuWidget(this); // �������˵�
    gamePanelWidget = new GamePanelWidget(this); // ������Ϸ���

    // ��ʼ��������Ϸ��壬����һ��ʼ��ֻ��ʾ�˵�ҳ��
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