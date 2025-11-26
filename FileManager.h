#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QString>

class FileManager : public QObject {
    Q_OBJECT

public:
    explicit FileManager(QObject *parent = nullptr);
    QString getOutputPath(bool isScreenshot);

private:
    QString m_videoDirectory;
    QString m_screenshotDirectory;
};

#endif
