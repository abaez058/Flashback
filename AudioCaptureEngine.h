#ifndef AUDIOCAPTUREENGINE_H
#define AUDIOCAPTUREENGINE_H

#include <QObject>
#include <QStringList>

class AudioCaptureEngine : public QObject {
    Q_OBJECT

public:
    explicit AudioCaptureEngine(QObject *parent = nullptr);
    QStringList getAudioArgs();

private:
    bool m_enabled;
};

#endif
