#ifndef SCREENCAPTUREENGINE_H
#define SCREENCAPTUREENGINE_H

#include <QObject>
#include <QStringList>

class ScreenCaptureEngine : public QObject {
    Q_OBJECT

public:
    explicit ScreenCaptureEngine(QObject *parent = nullptr);

    QStringList buildRecordingArgs(const QString &outputPath);
    QStringList buildScreenshotArgs(const QString &outputPath);

private:
    int m_frameRate;
    int m_videoQuality;
};

#endif
