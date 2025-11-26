#ifndef CAPTUREMANAGER_H
#define CAPTUREMANAGER_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QTimer>

class FFmpegProcess;
class ScreenCaptureEngine;
class AudioCaptureEngine;
class FileManager;

class CaptureManager : public QObject {
    Q_OBJECT

public:
    enum CaptureState {
        Idle,
        Recording,
        Processing
    };

    explicit CaptureManager(QObject *parent = nullptr);
    ~CaptureManager();

    CaptureState state() const { return m_state; }
    
public slots:
    void startRecording();
    void stopRecording();
    void captureScreenshot();

signals:
    void stateChanged(CaptureState newState);
    void recordingStarted(const QString &outputPath);
    void recordingProgress(int seconds);
    void recordingStopped(const QString &filePath);
    void screenshotCaptured(const QString &filePath);
    void captureError(const QString &error);

private slots:
    void onFFmpegFinished(int exitCode);
    void updateRecordingTime();

private:
    void setState(CaptureState newState);

    CaptureState m_state;
    FFmpegProcess *m_ffmpegProcess;
    ScreenCaptureEngine *m_screenEngine;
    AudioCaptureEngine *m_audioEngine;
    FileManager *m_fileManager;
    QTimer *m_recordingTimer;
    QDateTime m_recordingStartTime;
    QString m_currentOutputPath;
};

#endif
