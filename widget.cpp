#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include <typeinfo>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    loadConfig();
    loadUserInfo();



    connect(ui->LoginBtn, &QPushButton::clicked, this, &Widget::saveUserInfo);
    connect(ui->LoginBtn, &QPushButton::clicked, this, &Widget::saveConfig);
    connect(ui->QuitBtn, &QPushButton::clicked, this, &Widget::close);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::saveConfig()
{
    QSettings setting("Project", "LoginTest");
    setting.beginGroup("Config");
    setting.setValue("rememberPwd", ui->remberPwdcheckBox->isChecked());
    setting.setValue("autoLogin", ui->autoLogincheckBox->isChecked());
}

void Widget::loadConfig()
{
    QSettings setting("Project", "LoginTest");
    setting.beginGroup("Config");
    bool rePwd = setting.value("rememberPwd").toBool();
    bool autLg = setting.value("autoLogin").toBool();
    if( rePwd)
    {
        ui->remberPwdcheckBox->setCheckState(Qt::Checked);
    }
    if(autLg)
    {
        ui->autoLogincheckBox->setCheckState(Qt::Checked);
    }
}

void Widget::loadUserInfo()
{
    QSettings setting("Project", "LoginTest");
    setting.beginGroup("UserInfo");

    userName = setting.value("userName").toString();
    userPassword = setting.value("userPassword").toString();

    ui->usernameLineEdit->setText(userName);
    ui->passwordLineEdit->setText(userPassword);

}

void Widget::saveUserInfo()
{
    QSettings setting("Project", "LoginTest");
    setting.beginGroup("UserInfo");
    setting.setValue("userName", ui->usernameLineEdit->text());

    if(ui->remberPwdcheckBox->isChecked())  //记住密码是否勾选
    {
        setting.setValue("userPassword", ui->passwordLineEdit->text());
    }

//    saveConfig();
}

void Widget::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    saveConfig();
    return QWidget::closeEvent(event);
}
