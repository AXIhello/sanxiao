#include "LoginWidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

LoginWidget::LoginWidget(QWidget* parent)
    : QDialog(parent), usernameEdit(new QLineEdit(this)), passwordEdit(new QLineEdit(this)),
    btnLogin(new QPushButton("Login", this)), btnregister(new QPushButton("Register", this)) {
    setWindowTitle("Login"); // ���ô��ڱ���

    passwordEdit->setEchoMode(QLineEdit::Password);  // ������������ģʽ

    // ������ֱ���ֲ���ӿؼ�
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Username:"));
    layout->addWidget(usernameEdit);
    layout->addWidget(new QLabel("Password:"));
    layout->addWidget(passwordEdit);
    layout->addWidget(btnLogin);
    layout->addWidget(btnregister);

    // ���ô��ڵ���С�ߴ�
    this->setMinimumSize(300, 200);

    // ���ӵ�¼��ť����źŵ���֤��¼��Ϣ�Ĳۺ���
    connect(btnLogin, &QPushButton::clicked, this, &LoginWidget::onLoginClicked);
    connect(btnregister, &QPushButton::clicked, this, &LoginWidget::onRegisterClicked);
}

void LoginWidget::onLoginClicked() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();
    // ����������ʵ�ʵ���֤�߼������������ݿ��Ԥ��ֵ�Ƚ�
    if (username == "admin" && password == "123456") {  // ��ʾ����֤
        emit loginSuccess();
        this->accept();  // �رնԻ���
    }
    else {
        QMessageBox::warning(this, "Login Failed", "Username or password is incorrect");
    }
}

void LoginWidget::onRegisterClicked() {
    // TODO: ʵ��ע���߼�
}