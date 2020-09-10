/**
Copyright (C) 2020 Allstar Software (Paul Wallace)
*/
import QtQuick 1.1
import com.nokia.symbian 1.1

Page {
    id: mainPage
    property bool completed: false
    property bool error: false
    QtObject { id: page; property Component __comp: null;
        function createComponent (qmlfile){
            __comp = Qt.createComponent(qmlfile)
            __comp.createObject(mainPage)} }
    Component.onCompleted: {toolbar.show(); QtDownload.set();
        QtDownload.download();}
   BottomToolBar{id: toolbar

       ToolButton{iconSource: "toolbar-back"
           onClicked:{completed?  Qt.quit(): page.createComponent("CloseWarningDialog.qml")


           }
       }
       ToolButton{anchors.centerIn: parent
           flat: true
           anchors.verticalCenter: parent.verticalCenter
           text:"Open"
           visible: false
           id: openbutton
           onClicked:{QtDownload.openFile(); Qt.quit();}
       }
       ToolButton{anchors.right: parent.right
           flat: true
          anchors.verticalCenter: parent.verticalCenter
           text: completed? "Delete":"Cancel"
           id: cancel
           onClicked:{
               if(completed===true){QtDownload.remove(); openbutton.visible=false; cancel.visible=false; status.text="File Deleted"}
               else{QtDownload.cancel();status.text="Download Cancelled"; openbutton.visible=false; cancel.visible=false;indicator.running=false;
               }
}

       }
   }

   Timer{id: closeTimer; interval:5000; onTriggered :{Qt.quit()}}
  Connections{
      target: QtDownload
onDownloadStatus:{
 bar.value=currentStatus;
 indicator.running=true
 indicator.visible=true
status.text ="Downloading.."

}
onDone:{
   indicator.running=false
   status.text= "Download Completed"
   indicator.visible=false;
   openbutton.visible=true;
   completed=true;
   if(error===true){   indicator.running=false
       status.text= "An Error Occured"
       indicator.visible=false;
       openbutton.visible=false;}

}
onError:{
   error=true;
}
  }

  BusyIndicator{
  visible: false
  anchors.horizontalCenter: parent.horizontalCenter
  anchors.verticalCenter: parent.verticalCenter
  anchors.verticalCenterOffset: -100
  height: 85
  width: 85
  id: indicator
  }
ProgressBar{
maximumValue: 1
minimumValue: 0
anchors.centerIn: parent
id: bar
}

Text {
   id: status
   text:"Connecting.."
   color: "white"
   anchors.horizontalCenter: parent.horizontalCenter
   anchors.verticalCenter: parent.verticalCenter
   anchors.verticalCenterOffset: 80}

}
