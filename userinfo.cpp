#include "userinfo.h"

UserInfo::UserInfo(QString filePath)
{
    if(filePath.isEmpty())
    {
        m_filePath = QCoreApplication::applicationDirPath()+"/userinfo.ini";
        qDebug()<<m_filePath;
    }
    else
    {
        m_filePath = filePath;
    }
    m_setting = new QSettings(m_filePath, QSettings::IniFormat);    //在指定路径创建/读取配置文件
}

UserInfo::~UserInfo()
{
    delete m_setting;
    m_setting = nullptr;
}

void UserInfo::saveInfo(QString groupName, QString keyName, QVariant valueName)
{
    m_setting->beginGroup(groupName);
    m_setting->setValue(keyName, valueName);
    m_setting->endGroup();
}

userInfo UserInfo::loadInfo(QString groupName, QString userName, QString password)
{
    m_setting->beginGroup(groupName);

    m_variant = m_setting->value(userName);
    m_uif.userName = m_variant.toString();

    m_variant = m_setting->value(password);
    m_uif.passWord = m_variant.toString();

    qDebug()<<m_uif.userName<<m_uif.passWord;

    m_setting->endGroup();
    return m_uif;
}


