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
    void startGame(); // �Զ����źţ�����֪ͨ��Ϸ��ʼ

private:
    QPushButton* btnStart;
    QPushButton* btnHelp;
    QPushButton* btnAbout;
};

#endif // MAINMENUWIDGET_H