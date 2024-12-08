#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class LoginWidget : public QDialog {
    Q_OBJECT

public:
    explicit LoginWidget(QWidget* parent = nullptr);

signals:
    void loginSuccess(); // 登录成功的信号

private slots:
    void onLoginClicked();
    void onRegisterClicked();

private:
    QLineEdit* usernameEdit;
    QLineEdit* passwordEdit;
    QPushButton* btnLogin;
    QPushButton* btnregister;
};

#endif // LOGINWIDGET_H