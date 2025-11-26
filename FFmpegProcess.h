#ifndef FFMPEGPROCESS_H
#define FFMPEGPROCESS_H

#include <QObject>
#include <QProcess>
#include <QStringList>

class FFmpegProcess : public QObject {
    Q_OBJECT

public:
    explicit FFmpegProcess(QObject *parent = nullptr);
    ~FFmpegProcess();

    bool isRunning() const;
    void startRecording(const QStringList &arguments);
    void captureScreenshot(const QStringList &arguments);
    void stop();

signals:
    void started();
    void finished(int exitCode);
    void errorOccurred(const QString &error);

private slots:
    void onProcessFinished(int exitCode, QProcess::ExitStatus status);
    void onProcessError(QProcess::ProcessError error);

private:
    QProcess *m_process;
    QString m_ffmpegPath;
};

#endif
