//Copyright (C) 2020 Allstar Software (Paul Wallace)


#include "qtdownload.h"
#include <QCoreApplication>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QDebug>
#include <QFileInfo>
#include <akndiscreetpopup.h>
#include <AknGlobalNote.h>
#include <QtGui/QDesktopServices>
#include <QValueSpaceSubscriber.h>
#include <QValueSpacePublisher.h>
#include <QUrl>
#include <QDebug>
#include <QFile>
#include <QtGui/QDesktopServices>

//#include "nativesymbiandlg.hrh"
//#include <StarBrowser_0E0324339.rsg>

QtDownload::QtDownload(){
    dataer = new QValueSpaceSubscriber ("/Allstar/downloadManager", this);
}
bool cancelled;

void QtDownload::onError(QNetworkReply::NetworkError code){
   qDebug() << "Request failed with code " << code;
   if(code==5){}
   else{
   TRAP_IGNORE(CAknDiscreetPopup::ShowGlobalPopupL((_L("An Error Occured")),((TPtrC16(reinterpret_cast<const TText*>(QString(code).constData())))) ,KAknsIIDNone, KNullDesC));
   }
   emit error();

}


void QtDownload::remove(){
QFile* file = new QFile;
file->remove(target);

}

void QtDownload::openFile() {
QDesktopServices* opener = new QDesktopServices;
opener->openUrl("file:///" + target);
}

void QtDownload::set() {

   this->source = dataer->value("/src").toString();
   this->target = dataer->value("/target").toString();
}

void QtDownload::cancel()
{
    cancelled= true;
    pNetworkReply->abort();
}
void QtDownload::downloadFinished(QNetworkReply *data) {
    qDebug() << "finished";
    QFile localFile(QFileInfo(target).absoluteFilePath());
    if (!localFile.open(QIODevice::WriteOnly))
        return;
    const QByteArray sdata = data->readAll();
    localFile.write(sdata);
    qDebug() << sdata;
    qDebug() << "bla";
    qDebug() << target;
    localFile.close();
    emit done(target);
    if(cancelled==false){ TRAP_IGNORE(CAknDiscreetPopup::ShowGlobalPopupL((_L("Download Completed")), ((TPtrC16(reinterpret_cast<const TText*>(QString(target).constData())))) ,KAknsIIDNone, KNullDesC));}
    else {TRAP_IGNORE(CAknDiscreetPopup::ShowGlobalPopupL((_L("Download Cancelled")),(_L("")),KAknsIIDNone, KNullDesC));}

}
void QtDownload::download() {
    pNetworkReply = 0;
    manager = 0;
    cancelled=false;
    QUrl url(source);
    QNetworkRequest request(url);
    manager = new QNetworkAccessManager(this);
    pNetworkReply = manager->get(request);
    QObject::connect(pNetworkReply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downloadProgress(qint64,qint64)));
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(downloadFinished(QNetworkReply*)));
    connect(pNetworkReply, SIGNAL(error(QNetworkReply::NetworkError)),SLOT(onError(QNetworkReply::NetworkError)));
    qDebug() << "Download Started";
    qDebug() << url;
    TRAP_IGNORE(CAknDiscreetPopup::ShowGlobalPopupL((_L("Download Started")), ((TPtrC16(reinterpret_cast<const TText*>(QString(target).constData())))) ,KAknsIIDNone, KNullDesC));
}



void QtDownload::downloadProgress(qint64 recieved, qint64 total) {
    qDebug() << (float)recieved/(float)total;
    emit downloadStatus((float)recieved/(float)total);
    qDebug() << (double(recieved)/total) * 100 << "%";

}
