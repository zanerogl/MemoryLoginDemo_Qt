#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCore>
#include <QSettings>
#include <QDebug>

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
     * @brief saveConfig    保存配置文件
     */
    void saveConfig();

    /**
     * @brief loadConfig    加载配置文件
     */
    void loadConfig();

    /**
     * @brief addUserInfo   根据记住密码按钮是否勾选添加用户密码
     */
    void saveUserInfo();

    /**
     * @brief loadUserInfo   加载上次登录用户的用户名
     */
    void loadUserInfo();

    /**
     * @brief closeEvent    关闭事件，关闭事件触发时保存数据
     * @param event
     */
    void closeEvent(QCloseEvent *event) override;

    QString userName;
    QString userPassword;

};
#endif // WIDGET_H
