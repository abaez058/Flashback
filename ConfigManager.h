#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <QObject>
#include <QSettings>

class ConfigManager : public QObject {
    Q_OBJECT

public:
    static ConfigManager* instance();

private:
    explicit ConfigManager(QObject *parent = nullptr);
    static ConfigManager *s_instance;
    QSettings *m_settings;
};

#endif
