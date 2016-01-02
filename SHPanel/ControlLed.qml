import QtQuick 2.0

Item {
    property var isCurrent: (currentIndex == model.index)

    height: cellHeight
    width: cellWidth

    Rectangle {
        anchors.margins: 5
        anchors.fill: parent
        //color: model.color
        border {
            color: "black"
            width: 1
        }

        Text {
            anchors.centerIn: parent
            renderType: Text.NativeRendering
            text: "%1%2".arg(model.modelData.name).arg(isCurrent ? " *" : "")
        }

        MouseArea {
            anchors.fill: parent
            //onClicked: currentIndex = model.index
        }
    }
}
