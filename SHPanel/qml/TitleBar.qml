import QtQuick 2.5

Rectangle{
    property var barHeight: 42*dp
    property var title: "Main"
    signal back

    id: titleBar
    height: barHeight
    width: parent.width
    anchors.top: parent
    color: "#fff"

    Rectangle{
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: 2
        z: 2
        color: "skyblue"
    }

    BarButton{
        id: btnBack
        anchors.left: parent.left
        ico: "qrc:/images/color/back.png"
        onClick: {
            titleBar.back();
        }
    }

    Text{
        id: barTitle
        text: title
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: btnBack.right
        anchors.right: parent.right
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        renderType: Text.NativeRendering
    }
}
