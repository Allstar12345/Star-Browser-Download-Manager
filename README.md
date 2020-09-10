# Star-Browser-Download-Manager-
This is the external download manager which is part of Star Browser for Symbian OS

This is a required part of Star Browser for Symbian, known in App as External Download Manager




Remove the following from StarBrowser.pro if you do not want the external download manager:


DEPLOYMENT += addFiles
addFiles.pkg_postrules += "\"DownloadManager\StarBrowserDownloadManager_reg.rsc\" - \"!:\private\10003a3f\import\apps\StarBrowserDownloadManager_reg.rsc\""
addFiles.pkg_postrules += "\"DownloadManager\StarBrowserDownloadManager.exe\" - \"!:\sys\bin\StarBrowserDownloadManager.exe\""
addFiles.pkg_postrules += "\"DownloadManager\StarBrowserDownloadManager.rsc\" - \"!:/resource/apps/StarBrowserDownloadManager.rsc\""
#addFiles.pkg_postrules += "\"DownloadManager\StarBrowserDownloadManager.mif\" - \"!:/resource/apps/StarBrowserDownloadManager.mif\""