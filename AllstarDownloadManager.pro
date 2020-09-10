# Add more folders to ship with the application, here
folder_01.source = qml/AllstarDownloadManager
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

symbian:TARGET.UID3 = 0xE0324342
TARGET.EPOCHEAPSIZE = 0x90000 0x9000000
LIBS +=  -lefsrv \
               -lavkon\
               -lhal \
               -lapparc\
               -lcommondialogs\
               -leiksrv \
               -lcone\
                 -leikcore\

symbian {
RSS_RULES += "hidden = KAppIsHidden;"

    TARGET.CAPABILITY += NetworkServices

    my_deployment.pkg_prerules += vendorinfo

    DEPLOYMENT += my_deployment

    vendorinfo += "%{\"Allstar Software\"}" ":\"Allstar Software\""
}


CONFIG += qt-components

QT += network
QT += webkit
 CONFIG += mobility
MOBILITY += publishsubscribe

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    qtdownload.cpp

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

RESOURCES += \
    res.qrc

HEADERS += \
    qtdownload.h
