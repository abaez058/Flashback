#include "MainWindow.h"
#include "CaptureManager.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QMenu>
#include <QStyle>  

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_captureManager(new CaptureManager(this))
    , m_trayIcon(new QSystemTrayIcon(this))
{
    setupUI();
    
    connect(m_captureManager, &CaptureManager::stateChanged, 
            this, &MainWindow::onCaptureStateChanged);
    connect(m_captureManager, &CaptureManager::recordingProgress, 
            this, &MainWindow::onRecordingProgress);
    connect(m_captureManager, &CaptureManager::recordingStopped, 
            this, &MainWindow::onRecordingStopped);
    connect(m_captureManager, &CaptureManager::screenshotCaptured, 
            this, &MainWindow::onScreenshotCaptured);
    
    m_trayIcon->setIcon(style()->standardIcon(QStyle::SP_ComputerIcon));
    m_trayIcon->setToolTip("FLASHBACK");
    m_trayIcon->show();
}

MainWindow::~MainWindow() {
}

void MainWindow::setupUI() {
    setWindowTitle("FLASHBACK - Screen Recorder");
    resize(400, 300);
    
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    
    QLabel *titleLabel = new QLabel("FLASHBACK", this);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(24);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);
    
    m_statusLabel = new QLabel("Ready", this);
    m_statusLabel->setAlignment(Qt::AlignCenter);
    
    m_timeLabel = new QLabel("00:00:00", this);
    QFont timeFont = m_timeLabel->font();
    timeFont.setPointSize(20);
    m_timeLabel->setFont(timeFont);
    m_timeLabel->setAlignment(Qt::AlignCenter);
    
    m_recordButton = new QPushButton("Start Recording", this);
    m_recordButton->setMinimumHeight(50);
    connect(m_recordButton, &QPushButton::clicked, this, &MainWindow::onRecordButtonClicked);
    
    m_screenshotButton = new QPushButton("Take Screenshot", this);
    m_screenshotButton->setMinimumHeight(50);
    connect(m_screenshotButton, &QPushButton::clicked, this, &MainWindow::onScreenshotButtonClicked);
    
    mainLayout->addWidget(titleLabel);
    mainLayout->addSpacing(20);
    mainLayout->addWidget(m_statusLabel);
    mainLayout->addWidget(m_timeLabel);
    mainLayout->addSpacing(20);
    mainLayout->addWidget(m_recordButton);
    mainLayout->addWidget(m_screenshotButton);
    mainLayout->addStretch();
}

void MainWindow::onRecordButtonClicked() {
    if (m_captureManager->state() == CaptureManager::Idle) {
        m_captureManager->startRecording();
    } else {
        m_captureManager->stopRecording();
    }
}

void MainWindow::onScreenshotButtonClicked() {
    m_captureManager->captureScreenshot();
}

void MainWindow::onCaptureStateChanged(int state) {
    updateUIForState(state);
}

void MainWindow::onRecordingProgress(int seconds) {
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int secs = seconds % 60;
    
    m_timeLabel->setText(QString("%1:%2:%3")
        .arg(hours, 2, 10, QChar('0'))
        .arg(minutes, 2, 10, QChar('0'))
        .arg(secs, 2, 10, QChar('0')));
}

void MainWindow::onRecordingStopped(const QString &filePath) {
    m_trayIcon->showMessage("Recording Saved", 
        "Video saved to:\n" + filePath,
        QSystemTrayIcon::Information, 3000);
}

void MainWindow::onScreenshotCaptured(const QString &filePath) {
    m_trayIcon->showMessage("Screenshot Captured", 
        "Screenshot saved to:\n" + filePath,
        QSystemTrayIcon::Information, 3000);
}

void MainWindow::updateUIForState(int state) {
    switch (state) {
        case CaptureManager::Idle:
            m_statusLabel->setText("Ready");
            m_recordButton->setText("Start Recording");
            m_screenshotButton->setEnabled(true);
            m_timeLabel->setText("00:00:00");
            break;
        case CaptureManager::Recording:
            m_statusLabel->setText("Recording...");
            m_recordButton->setText("Stop Recording");
            m_screenshotButton->setEnabled(false);
            break;
        case CaptureManager::Processing:
            m_statusLabel->setText("Processing...");
            m_recordButton->setEnabled(false);
            m_screenshotButton->setEnabled(false);
            break;
    }
}
