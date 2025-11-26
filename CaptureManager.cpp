#include "CaptureManager.h"
#include "FFmpegProcess.h"
#include "ScreenCaptureEngine.h"
#include "AudioCaptureEngine.h"
#include "FileManager.h"
#include <QDebug>

CaptureManager::CaptureManager(QObject *parent)
    : QObject(parent)
    , m_state(Idle)
    , m_ffmpegProcess(new FFmpegProcess(this))
    , m_screenEngine(new ScreenCaptureEngine(this))
    , m_audioEngine(new AudioCaptureEngine(this))
    , m_fileManager(new FileManager(this))
    , m_recordingTimer(new QTimer(this))
{
    connect(m_ffmpegProcess, &FFmpegProcess::finished, this, &CaptureManager::onFFmpegFinished);
    connect(m_recordingTimer, &QTimer::timeout, this, &CaptureManager::updateRecordingTime);
    
    m_recordingTimer->setInterval(1000);
}

CaptureManager::~CaptureManager() {
    if (m_state == Recording) {
        stopRecording();
    }
}

void CaptureManager::startRecording() {
    if (m_state != Idle) {
        qDebug() << "Cannot start recording: not in Idle state";
        return;
    }

    m_currentOutputPath = m_fileManager->getOutputPath(false);
    QStringList args = m_screenEngine->buildRecordingArgs(m_currentOutputPath);
    args.append(m_audioEngine->getAudioArgs());

    qDebug() << "Starting recording to:" << m_currentOutputPath;
    m_ffmpegProcess->startRecording(args);
    
    setState(Recording);
    m_recordingStartTime = QDateTime::currentDateTime();
    m_recordingTimer->start();
    
    emit recordingStarted(m_currentOutputPath);
}

void CaptureManager::stopRecording() {
    if (m_state != Recording) {
        return;
    }

    qDebug() << "Stopping recording";
    m_recordingTimer->stop();
    m_ffmpegProcess->stop();
    setState(Processing);
}

void CaptureManager::captureScreenshot() {
    if (m_state == Recording) {
        qDebug() << "Cannot take screenshot while recording";
        return;
    }

    QString outputPath = m_fileManager->getOutputPath(true);
    QStringList args = m_screenEngine->buildScreenshotArgs(outputPath);

    qDebug() << "Capturing screenshot to:" << outputPath;
    m_ffmpegProcess->captureScreenshot(args);
    
    emit screenshotCaptured(outputPath);
}

void CaptureManager::onFFmpegFinished(int exitCode) {
    if (m_state == Processing) {
        setState(Idle);
        
        if (exitCode == 0) {
            emit recordingStopped(m_currentOutputPath);
        } else {
            emit captureError("FFmpeg process failed");
        }
    }
}

void CaptureManager::updateRecordingTime() {
    int seconds = m_recordingStartTime.secsTo(QDateTime::currentDateTime());
    emit recordingProgress(seconds);
}

void CaptureManager::setState(CaptureState newState) {
    if (m_state != newState) {
        m_state = newState;
        emit stateChanged(newState);
    }
}
