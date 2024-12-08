#ifndef MAINMENUWIDGET_H
#define MAINMENUWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class LoginWidget;  // ǰ��������¼������

class MainMenuWidget : public QWidget {
    Q_OBJECT

public:
    MainMenuWidget(QWidget* parent = nullptr);

signals:
    void startGame();

private:
    QPushButton* btnStart;
    QPushButton* btnHelp;
    QPushButton* btnAbout;
    LoginWidget* loginWidget;  // ���ڴ洢��¼����ָ��
};

#endif // MAINMENUWIDGET_H