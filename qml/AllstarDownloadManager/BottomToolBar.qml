// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
Rectangle{
    smooth: true
    id: toolbar
    opacity: 0.8
    function show(){barsappear.start();}
    function hide(){barsdisappear.start();}
    SmoothedAnimation{
        id: barsappear
        targets: [toolbar]
        property: "anchors.bottomMargin"
        to: 0
    }
    SmoothedAnimation{
        id: barsdisappear
        targets: [toolbar]
        property: "anchors.bottomMargin"
        to: -60
    }
    implicitWidth: Math.max(50, screen.width)
    implicitHeight: (screen.width < screen.height)
        ? privateStyle.toolBarHeightPortrait
        : privateStyle.toolBarHeightLandscape
    anchors.right: parent.right
    anchors.left: parent.left
    color: "black"
    anchors.bottom: parent.bottom
    anchors.bottomMargin: -60
}
