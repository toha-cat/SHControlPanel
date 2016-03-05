import QtQuick 2.5

Item {
    //property var isCurrent: (currentIndex == model.index)

    function getAlteredState(){
        if(model.state == "on"){
            return "off";
        }
        else{
            return "on";
        }
    }

    function getStateImages(){
        if(model.state == "on"){
            return "qrc:/images/color/blind_up.png";
        }
        else{
            return "qrc:/images/color/blind_down.png";
        }
    }

    height: cellHeight
    width: cellWidth

    Rectangle {
        anchors.margins: 10*dp
        anchors.fill: parent
        border {
            color: "black"
            width: 1
        }
        radius: 10*dp
        color: "#eee"

        Image {
            id: img
            fillMode: Image.PreserveAspectFit
            source: getStateImages()
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            height: parent.height*7/10
        }

        Text {
            anchors.top: img.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            renderType: Text.NativeRendering
            text: model.name
            font.pointSize: 11*dp
            wrapMode: Text.WordWrap
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                backend.changeDevice(model.id, getAlteredState());
            }
        }
    }
}
