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
    passwordEdit->setEchoMode(QLineEdit::Password);  // ������������ģʽ
    btnLogin = new QPushButton("login", this);

    // ������ֱ���ֲ���ӿؼ�
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("username��"));
    layout->addWidget(usernameEdit);
    layout->addWidget(new QLabel("password��"));
    layout->addWidget(passwordEdit);
    layout->addWidget(btnLogin);

    // ���ӵ�¼��ť����źŵ���֤��¼��Ϣ�Ĳۺ���
    connect(btnLogin, &QPushButton::clicked, this, [this]() {
        //QString username = usernameEdit->text();
        //QString password = passwordEdit->text();
        //// ����������ʵ�ʵ���֤�߼������������ݿ��Ԥ��ֵ�Ƚ�
        //if (username == "admin" && password == "123456") {  // ��ʾ����֤
        //    emit loginSuccess();
        //    close();  // ��¼�ɹ���رյ�¼����
        //}
        //else {
        //    QMessageBox::warning(this, "��¼ʧ��", "�û������������");
        //}
        });
}