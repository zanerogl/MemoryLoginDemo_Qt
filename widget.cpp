#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include <typeinfo>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_userInfo = new UserInfo;

    loadConfig();

    connect(ui->LoginBtn, &QPushButton::clicked, this, &Widget::saveConfig);
    connect(ui->QuitBtn, &QPushButton::clicked, this, &Widget::close);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::saveConfig()
{
    /*保存窗口配置*/
    QSettings setting(QString(QCoreApplication::applicationDirPath()+"/config.ini"), QSettings::IniFormat);
    setting.beginGroup("Config");
    setting.setValue("rememberPwd", ui->remberPwdcheckBox->isChecked());
    setting.setValue("autoLogin", ui->autoLogincheckBox->isChecked());

    /*记忆登陆，保存用户信息*/
    memoryLogin();
}

void Widget::loadConfig()
{
    QSettings setting(QString(QCoreApplication::applicationDirPath()+"/config.ini"), QSettings::IniFormat);
    setting.beginGroup("Config");

    bool rePwd = setting.value("rememberPwd").toBool();
    bool autLg = setting.value("autoLogin").toBool();
    if(rePwd)  //记住密码勾选则加载用户密码
    {
        ui->remberPwdcheckBox->setCheckState(Qt::Checked);
        QString password;
        password = m_userInfo->loadInfo("UserInfo", "UserName", "Password").passWord;
        ui->passwordLineEdit->setText(password);
        qDebug()<<"59"<<password;
    }
    if(autLg)   //自动登陆勾选则自动登陆
    {
        ui->autoLogincheckBox->setCheckState(Qt::Checked);
    }

    /*加载用户名*/
    QString userName;
    userName = m_userInfo->loadInfo("UserInfo", "UserName", "Password").userName;
    ui->usernameLineEdit->setText(userName);
    qDebug()<<"69"<<userName;

}

void Widget::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    saveConfig();
    return QWidget::closeEvent(event);
}

void Widget::memoryLogin()
{
    m_userInfo->saveInfo("UserInfo", "UserName", ui->usernameLineEdit->text());

    if(ui->remberPwdcheckBox->isChecked())
    {
        m_userInfo->saveInfo("UserInfo", "Password",ui->passwordLineEdit->text());
    }
}







