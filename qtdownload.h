//Copyright (C) 2020 Allstar Software (Paul Wallace)


#include <QObject>
#include <QString>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QValueSpaceSubscriber>
#include <QValueSpacePublisher.h>
#include <QUrl>
QTM_USE_NAMESPACE

class QtDownload : public QObject {
    Q_OBJECT

public:
 explicit QtDownload();
    Q_INVOKABLE void set();
    Q_INVOKABLE void cancel();
    Q_INVOKABLE void openFile();
    Q_INVOKABLE void remove();


private:
    QNetworkAccessManager* manager;
    QNetworkReply *pNetworkReply;
    QString target;
    QUrl source;

    QValueSpaceSubscriber* dataer;
Q_SIGNALS:
    void showPopup();
signals:
    Q_INVOKABLE void done(QString);
    Q_INVOKABLE void downloadStatus(float currentStatus);
    Q_INVOKABLE void error();


public slots:
    Q_INVOKABLE void download();
    void downloadFinished(QNetworkReply* data);
    void downloadProgress(qint64 recieved, qint64 total);
    void onError(QNetworkReply::NetworkError code);
};
