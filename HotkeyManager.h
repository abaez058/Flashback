#ifndef HOTKEYMANAGER_H
#define HOTKEYMANAGER_H

#include <QObject>

class HotkeyManager : public QObject {
    Q_OBJECT

public:
    enum HotkeyAction {
        StartStopRecording,
        CaptureScreenshot
    };

    explicit HotkeyManager(QObject *parent = nullptr);

signals:
    void hotkeyPressed(HotkeyAction action);
};

#endif
