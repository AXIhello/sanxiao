#include "MainMenuWidget.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include "LoginWidget.h"  // ������¼����ͷ�ļ�
#include "GamePanelWidget.h"  // ������Ϸ������ͷ�ļ�
#include"ui_MainWindow.h"
#include"MainWindow.h"

MainMenuWidget::MainMenuWidget(QWidget* parent, Ui::MainWindow* ui)
    : QWidget(parent),mainui(ui)
{
    //// ������ʼ��Ϸ��ť
    //btnStart = new QPushButton("start game", this);
    //btnStart->setGeometry(QRect(300, 240, 131, 61));
    ////// ������ʽ���������ԣ�����ʡ�Ծ�����ʽ���ô���

    //// ����������ť
    //btnHelp = new QPushButton("help", this);
    //btnHelp->setGeometry(QRect(300, 330, 131, 51));

    ////// �������ڰ�ť
    //btnAbout = new QPushButton("about", this);
    //btnAbout->setGeometry(QRect(290, 430, 141, 51));

    ////// ������ֱ���ֲ�����ť��ӵ�������
    //QVBoxLayout* layout = new QVBoxLayout(this);
    //layout->addWidget(btnStart);
    //layout->addWidget(btnHelp);
    //layout->addWidget(btnAbout);


    // ���Ӱ�ť����źŵ���Ӧ�Ĳۺ���
    connect(mainui->btnStart, &QPushButton::clicked, this, [this]() {
        // ������¼����ʵ��
        LoginWidget* login = new LoginWidget(this);
        // ���ӵ�¼�ɹ��źŵ����Ϳ�ʼ��Ϸ�ź�
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