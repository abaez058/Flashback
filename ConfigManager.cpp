#include "ConfigManager.h"

ConfigManager* ConfigManager::s_instance = nullptr;

ConfigManager::ConfigManager(QObject *parent)
    : QObject(parent)
    , m_settings(new QSettings(this))
{
}

ConfigManager* ConfigManager::instance() {
    if (!s_instance) {
        s_instance = new ConfigManager();
    }
    return s_instance;
}
