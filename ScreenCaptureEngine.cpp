#include "ScreenCaptureEngine.h"

ScreenCaptureEngine::ScreenCaptureEngine(QObject *parent)
    : QObject(parent)
    , m_frameRate(30)
    , m_videoQuality(23)
{
}

QStringList ScreenCaptureEngine::buildRecordingArgs(const QString &outputPath) {
    QStringList args;
    args << "-f" << "gdigrab"
         << "-framerate" << QString::number(m_frameRate)
         << "-i" << "desktop"
         << "-c:v" << "libx264"
         << "-preset" << "ultrafast"
         << "-crf" << QString::number(m_videoQuality)
         << "-y"
         << outputPath;
    return args;
}

QStringList ScreenCaptureEngine::buildScreenshotArgs(const QString &outputPath) {
    QStringList args;
    args << "-f" << "gdigrab"
         << "-i" << "desktop"
         << "-frames:v" << "1"
         << "-y"
         << outputPath;
    return args;
}
