#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>
#include <QSettings>
#include <QString>
#include <QtCore>

struct userInfo
{
    QString userName;
    QString passWord;
};

class UserInfo : public QSettings
{
    Q_OBJECT
public:

    /**
     * @brief UserInfo  创建用户配置文件
     * @param filename  配置文件路径，未指定则在应用程序同级目录下
     */
    UserInfo(QString filename = "");
    ~UserInfo();

    /**
     * @brief saveInfo  保存用户信息
     * @param groupName 组名：UserInfo
     * @param keyname   类名：UserName Password
     * @param valueName 内容
     */
    void saveInfo(QString groupName, QString keyName, QVariant valueName);

    /**
     * @brief loadInfo  加载用户信息
     * @param groupName 组名：UserInfo
     * @param UserName  用户名
     * @param Password  密码
     * @return userInfo 返回一个用户信息结构体：用户名和秘密
     */
    userInfo loadInfo(QString groupName, QString userName, QString password);

signals:

private:
    QString m_filePath;     //配置文件路径
    QSettings *m_setting;

    QVariant m_variant;     //加载用户信息

    userInfo m_uif;         //用户信息结构体

};

#endif // USERINFO_H
