#pragma once
#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class LoginWidget : public QWidget {
    Q_OBJECT

public:
    LoginWidget(QWidget* parent = nullptr);

signals:
    void loginSuccess();  // µÇÂ¼³É¹¦ÐÅºÅ

private:
    QLineEdit* usernameEdit;
    QLineEdit* passwordEdit;
    QPushButton* btnLogin;
};

#endif // LOGINWIDGET_H