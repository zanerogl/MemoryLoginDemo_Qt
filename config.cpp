#include "config.h"

Config::Config(QString filename)
{
    if(filename.isEmpty())
    {
        m_fileName = QCoreApplication::applicationDirPath()+"/Config.ini";
        qDebug()<<m_fileName;
    }
    else
    {
        m_fileName = filename;
    }
    m_setting = new QSettings(m_fileName, QSettings::IniFormat);
}

Config::~Config()
{
    delete m_setting;
    m_setting = NULL;
}

void Config::SetInit(QString nodeName, QString keyName, QVariant valueName)
{
    m_setting->setValue(QString("/%1/%2").arg(nodeName).arg(keyName), valueName);
}

QVariant Config::GetInit(QString nodeName, QString userName, QString userPaswd)
{
    QVariant name = m_setting->value(QString("/%1/%2").arg(nodeName).arg(userName));
    QVariant paswd = m_setting->value(QString("/%1/%2").arg(nodeName).arg(userPaswd));
    QString ret = QString("%1\n%2").arg(name.toString()).arg(paswd.toString());
    return ret;
}

