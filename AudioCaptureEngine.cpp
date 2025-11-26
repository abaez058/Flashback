#include "AudioCaptureEngine.h"

AudioCaptureEngine::AudioCaptureEngine(QObject *parent)
    : QObject(parent)
    , m_enabled(false)
{
}

QStringList AudioCaptureEngine::getAudioArgs() {
    if (!m_enabled) {
        return QStringList() << "-an";
    }
    return QStringList();
}
