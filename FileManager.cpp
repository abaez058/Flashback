#include "FileManager.h"
#include <QStandardPaths>
#include <QDir>
#include <QDateTime>

FileManager::FileManager(QObject *parent)
    : QObject(parent)
{
    QString videosPath = QStandardPaths::writableLocation(QStandardPaths::MoviesLocation);
    m_videoDirectory = videosPath + "/FLASHBACK/Videos";
    m_screenshotDirectory = videosPath + "/FLASHBACK/Screenshots";
    
    QDir().mkpath(m_videoDirectory);
    QDir().mkpath(m_screenshotDirectory);
}

QString FileManager::getOutputPath(bool isScreenshot) {
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd_HH-mm-ss");
    QString dir = isScreenshot ? m_screenshotDirectory : m_videoDirectory;
    QString ext = isScreenshot ? ".png" : ".mp4";
    
    return dir + "/capture_" + timestamp + ext;
}
