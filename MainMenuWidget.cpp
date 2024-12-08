#include "MainMenuWidget.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include "LoginWidget.h"  // ������¼����ͷ�ļ�

MainMenuWidget::MainMenuWidget(QWidget* parent)
    : QWidget(parent)
{
    btnStart = findChild<QPushButton*>("pushButton");
    btnHelp = findChild<QPushButton*>("pushButton_2");
    btnAbout = findChild<QPushButton*>("pushButton_3");

    // ������ֱ���ֲ�����ť��ӵ�������
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(btnStart);
    layout->addWidget(btnHelp);
    layout->addWidget(btnAbout);

    // ���Ӱ�ť����źŵ���Ӧ�Ĳۺ���
    connect(btnStart, &QPushButton::clicked, this, [this]() {
        // ������¼����ʵ��
        loginWidget = new LoginWidget(this);
        // ���ӵ�¼�ɹ��źŵ����Ϳ�ʼ��Ϸ�ź�
        connect(loginWidget, &LoginWidget::loginSuccess, this, &MainMenuWidget::startGame);
        // ��ʾ��¼����
        loginWidget->show();
        });
    connect(btnHelp, &QPushButton::clicked, [this]() {
        QMessageBox::information(this, "help", "this is help information.");
        });
    connect(btnAbout, &QPushButton::clicked, [this]() {
        QMessageBox::information(this, "About", "this is about information.");
        });
}