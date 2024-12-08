#include "LoginWidget.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
LoginWidget::LoginWidget(QWidget* parent)
    : QWidget(parent)
{
    usernameEdit = new QLineEdit(this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);  // 设置密码输入模式
    btnLogin = new QPushButton("login", this);

    // 创建垂直布局并添加控件
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("username："));
    layout->addWidget(usernameEdit);
    layout->addWidget(new QLabel("password："));
    layout->addWidget(passwordEdit);
    layout->addWidget(btnLogin);

    // 连接登录按钮点击信号到验证登录信息的槽函数
    connect(btnLogin, &QPushButton::clicked, this, [this]() {
        //QString username = usernameEdit->text();
        //QString password = passwordEdit->text();
        //// 这里可以添加实际的验证逻辑，比如与数据库或预设值比较
        //if (username == "admin" && password == "123456") {  // 简单示例验证
        //    emit loginSuccess();
        //    close();  // 登录成功后关闭登录界面
        //}
        //else {
        //    QMessageBox::warning(this, "登录失败", "用户名或密码错误");
        //}
        });
}