#include "MainMenuWidget.h"
#include <QMessageBox>
#include <QVBoxLayout>

// ʵ��MainMenuWidget��Ĺ��캯��
MainMenuWidget::MainMenuWidget(QWidget* parent)
    : QWidget(parent)
{
    // ͨ��ʹ�ý���Ԫ�ص����֣���xml�ж���Ķ�Ӧ���ҵ���Ӧ�İ�ť�ؼ�
    btnStart = findChild<QPushButton*>("pushButton");
    btnHelp = findChild<QPushButton*>("pushButton_2");
    btnAbout = findChild<QPushButton*>("pushButton_3");

    // ������ֱ���ֲ�����ť��ӵ�������
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(btnStart);
    layout->addWidget(btnHelp);
    layout->addWidget(btnAbout);

    // ���Ӱ�ť����źŵ���Ӧ�Ĳۺ���
    connect(btnStart, &QPushButton::clicked, this, &MainMenuWidget::startGame);
    connect(btnHelp, &QPushButton::clicked, [this]() {
        QMessageBox::information(this, "help", "this is a help message.");
        });
    connect(btnAbout, &QPushButton::clicked, [this]() {
        QMessageBox::information(this, "about", "this is a about message.");
        });
}