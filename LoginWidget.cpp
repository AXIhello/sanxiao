#include "LoginWidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

LoginWidget::LoginWidget(QWidget* parent)
    : QDialog(parent), usernameEdit(new QLineEdit(this)), passwordEdit(new QLineEdit(this)),
    btnLogin(new QPushButton("Login", this)), btnregister(new QPushButton("Register", this)) {
    setWindowTitle("Login"); // 设置窗口标题

    passwordEdit->setEchoMode(QLineEdit::Password);  // 设置密码输入模式

    // 创建垂直布局并添加控件
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Username:"));
    layout->addWidget(usernameEdit);
    layout->addWidget(new QLabel("Password:"));
    layout->addWidget(passwordEdit);
    layout->addWidget(btnLogin);
    layout->addWidget(btnregister);

    // 设置窗口的最小尺寸
    this->setMinimumSize(300, 200);

    // 连接登录按钮点击信号到验证登录信息的槽函数
    connect(btnLogin, &QPushButton::clicked, this, &LoginWidget::onLoginClicked);
    connect(btnregister, &QPushButton::clicked, this, &LoginWidget::onRegisterClicked);
}

void LoginWidget::onLoginClicked() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();
    // 这里可以添加实际的验证逻辑，比如与数据库或预设值比较
    if (username == "admin" && password == "123456") {  // 简单示例验证
        emit loginSuccess();
        this->accept();  // 关闭对话框
    }
    else {
        QMessageBox::warning(this, "Login Failed", "Username or password is incorrect");
    }
}

void LoginWidget::onRegisterClicked() {
    // TODO: 实现注册逻辑
}