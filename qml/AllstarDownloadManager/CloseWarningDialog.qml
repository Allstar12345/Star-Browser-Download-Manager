/**
Copyright (C) 2020 Allstar Software (Paul Wallace)
*/
import QtQuick 1.1
import com.nokia.symbian 1.1

CommonDialog{
id: root
titleText: "Warning"
property bool __isClosing: false
Component.onCompleted: {open();}
onStatusChanged: {
    if (status === DialogStatus.Closing) __isClosing = true
    else if (status === DialogStatus.Closed && __isClosing)root.destroy()
}
buttonTexts: ["Continue", "Cancel"]
content: Label{
  id: text;   text: "Warning, download will be cancelled!";anchors.centerIn: parent
}
onButtonClicked: {

    if(index===0){QtDownload.cancel(); Qt.quit();}

    if (index === 1){close();}

}

}
