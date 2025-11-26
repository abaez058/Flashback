#include "FFmpegProcess.h"
#include <QDebug>

FFmpegProcess::FFmpegProcess(QObject *parent)
    : QObject(parent)
    , m_process(new QProcess(this))
    , m_ffmpegPath("ffmpeg")
{
    connect(m_process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, &FFmpegProcess::onProcessFinished);
    connect(m_process, &QProcess::errorOccurred, this, &FFmpegProcess::onProcessError);
}

FFmpegProcess::~FFmpegProcess() {
    if (m_process->state() == QProcess::Running) {
        m_process->kill();
        m_process->waitForFinished();
    }
}

bool FFmpegProcess::isRunning() const {
    return m_process->state() == QProcess::Running;
}

void FFmpegProcess::startRecording(const QStringList &arguments) {
    qDebug() << "FFmpeg command:" << m_ffmpegPath << arguments.join(" ");
    m_process->start(m_ffmpegPath, arguments);
    emit started();
}

void FFmpegProcess::captureScreenshot(const QStringList &arguments) {
    QProcess::execute(m_ffmpegPath, arguments);
}

void FFmpegProcess::stop() {
    if (m_process->state() == QProcess::Running) {
        m_process->write("q");
        m_process->waitForFinished(3000);
        if (m_process->state() == QProcess::Running) {
            m_process->kill();
        }
    }
}

void FFmpegProcess::onProcessFinished(int exitCode, QProcess::ExitStatus status) {
    qDebug() << "FFmpeg finished with exit code:" << exitCode;
    emit finished(exitCode);
}

void FFmpegProcess::onProcessError(QProcess::ProcessError error) {
    qDebug() << "FFmpeg error:" << error;
    emit errorOccurred("Process error occurred");
}
