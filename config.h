#ifndef CONFIG_H
#define CONFIG_H

#include <QWidget>
#include <QDebug>
#include <QSettings>
#include <QCoreApplication>
#include <QVariant>

class Config : public QSettings
{
    Q_OBJECT
public:
//    explicit Config(QWidget *parent = nullptr);

    /**
     * @brief Config    初始化配置文件
     * @param filename  可以制定配置文件路径，
     */
    Config(QString filename = "" ); //打开参数文件
    ~Config();

    /**
     * @brief SetInit
     * @param nodeName
     * @param keyName
     * @param valueName
     */
    void SetInit(QString nodeName, QString keyName, QVariant valueName);

    /**
     * @brief GetInit
     * @param nodeName
     * @param keyName
     * @param valueName
     * @return
     */
    QVariant GetInit(QString nodeName, QString keyName, QString valueName);

signals:

private:
    QString m_fileName;       //文件名
    QSettings *m_setting;     //QSettings对象
};

#endif // CONFIG_H
