import QtQuick 2.5

Rectangle{
    property var barHeight: 30
    property var title: "Main"

    height: barHeight
    width: parent.width
    anchors.top: parent
    color: "#ff0000"

    Rectangle{
        id: btnCategory
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: parent.height
        color: parent.color
        Text {
            text: qsTr("C")
            font.bold: true
            font.pointSize: 14
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                //parent.color = "#00ff00"
                //TODO: функция вызова списка категорий
                //viewListCategoryDev.visible = true;
                viewListCategoryDev.show();
            }
        }
    }

    Text{
        id: barTitle
        text: title
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: btnCategory.right
        anchors.right: btnMenu.left
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Rectangle{
        id: btnMenu
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: parent.height
        color: parent.color
        Text {
            color: "#000000"
            text: qsTr("M")
            font.bold: true
            font.pointSize: 14
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                parent.color = "#00ff00"
                //TODO: функция вызова menu
            }
        }
    }
}
