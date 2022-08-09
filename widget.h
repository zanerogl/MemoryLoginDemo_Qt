#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCore>
#include <QSettings>
#include <QDebug>
#include "config.h"
#include "userinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

private:
    Ui::Widget *ui;

    /**
     * @brief saveConfig    保存配置文件和用户信息
     */
    void saveConfig();

    /**
     * @brief loadConfig    加载配置文件和用户信息
     */
    void loadConfig();

    /**
     * @brief closeEvent    关闭事件，关闭事件触发时保存数据
     * @param event
     */
    void closeEvent(QCloseEvent *event) override;

    /**
     * @brief memoryLogin   记忆登陆，用户点击Login后保存用户名，根据是否勾选记住秘密保存密码
     */
    void memoryLogin();

    QString userName;
    QString userPassword;

    Config *m_config;

    UserInfo *m_userInfo;

};
#endif // WIDGET_H
