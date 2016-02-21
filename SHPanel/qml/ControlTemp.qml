import QtQuick 2.5

Item {
    //property var isCurrent: (currentIndex == model.index)

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

        Row {
            id: stateBox
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            height: parent.height*7/10

            Text {
                id: temperatura
                text: model.state
                height: parent.height;
                width: parent.width / 2

                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                renderType: Text.NativeRendering
                font.pointSize: 28*dp
                wrapMode: Text.WordWrap

            }

            Image {
                id: temprIco
                fillMode: Image.PreserveAspectFit
                source: "qrc:/images/color/thermometer.png"
                height: parent.height
                width: parent.width / 2
            }
        }

        Text {
            anchors.top: stateBox.bottom
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

            }
        }
    }
}
