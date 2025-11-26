#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QPushButton>
#include <QLabel>

class CaptureManager;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onRecordButtonClicked();
    void onScreenshotButtonClicked();
    void onCaptureStateChanged(int state);
    void onRecordingProgress(int seconds);
    void onRecordingStopped(const QString &filePath);
    void onScreenshotCaptured(const QString &filePath);

private:
    void setupUI();
    void updateUIForState(int state);

    CaptureManager *m_captureManager;
    QSystemTrayIcon *m_trayIcon;
    
    QPushButton *m_recordButton;
    QPushButton *m_screenshotButton;
    QLabel *m_statusLabel;
    QLabel *m_timeLabel;
};

#endif
