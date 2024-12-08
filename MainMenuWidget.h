#ifndef MAINMENUWIDGET_H
#define MAINMENUWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class MainMenuWidget : public QWidget {
    Q_OBJECT

public:
    MainMenuWidget(QWidget* parent = nullptr);

signals:
    void startGame(); // 自定义信号，用于通知游戏开始

private:
    QPushButton* btnStart;
    QPushButton* btnHelp;
    QPushButton* btnAbout;
};

#endif // MAINMENUWIDGET_H