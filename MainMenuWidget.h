#ifndef MAINMENUWIDGET_H
#define MAINMENUWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include"ui_MainWindow.h"

class LoginWidget;  // ǰ��������¼������

class MainMenuWidget : public QWidget {
    Q_OBJECT

public:
    MainMenuWidget(QWidget* parent = nullptr, Ui::MainWindow* ui=nullptr);

signals:
    void startGame();

private:
    /*QPushButton* btnStart;
    QPushButton* btnHelp;
    QPushButton* btnAbout;*/
    Ui::MainWindow* mainui;
    LoginWidget* loginWidget;  // ���ڴ洢��¼����ָ��
};

#endif // MAINMENUWIDGET_H