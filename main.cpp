#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include <QDeclarativeProperty>
#include <QDebug>
#include <QObject>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeNetworkAccessManagerFactory>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/qdeclarative.h>
#include <QDeclarativeProperty>
#include <QtDeclarative/qdeclarativeextensionplugin.h>
#include <QMutex>
#include <QCoreApplication>
#include <QObject>
#include "qtdownload.h"
#include <apgcli.h> // RApaLsSession
#include <apgtask.h>
#include <avkon.mbg>
#include <aknnotewrappers.h>
#include <aknglobalnote.h>
#include <akndiscreetpopup.h>
#include <AknGlobalNote.h>
#include <AknCommonDialogs.h>
#include <AknCommonDialogsDynMem.h>


int main(int argc, char **argv)

{
    QApplication app(argc, argv);
    QDeclarativeView view;
    QtDownload qtDownload;
    view.rootContext()->setContextProperty("QtDownload", &qtDownload);
    view.setSource(QUrl("qrc:/qml/AllstarDownloadManager/main.qml"));
    view.window()->show();
    return app.exec();
}
