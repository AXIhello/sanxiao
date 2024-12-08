#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include "GamePanelWidget.h"
#include "LoginWidget.h"
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void onStartButtonClicked();
    void onHelpButtonClicked();
    void onAboutButtonClicked();
    void onLoginSuccess();

private:
    Ui::MainWindow* ui;
    GamePanelWidget* gamePanelWidget;
    LoginWidget* loginWidget;
};

#endif // MAINWINDOW_H
