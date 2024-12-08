#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "GamePanelWidget.h"
#include "MainMenuWidget.h"
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    Ui::MainWindow* getUi() const { return ui; }

private:
    Ui::MainWindow* ui; // ÉùÃ÷ ui ±äÁ¿
    MainMenuWidget* mainMenuWidget;
    GamePanelWidget* gamePanelWidget;
};

#endif // MAINWINDOW_H