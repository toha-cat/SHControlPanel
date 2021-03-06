import QtQuick 2.5

Rectangle{
    property var barHeight: 42*dp
    property var title: "Main"

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
        id: btnCategory
        anchors.left: parent.left
        ico: "qrc:/images/color/menu.png"
        onClick: {
            viewListCategoryDev.show();
        }
    }

    Text{
        id: barTitle
        text: title
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: btnCategory.right
        anchors.right: btnRules.left
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        renderType: Text.NativeRendering
    }

    BarButton{
        id: btnRules
        anchors.right: btnSetting.left
        ico: "qrc:/images/color/puzzle.png"
        onClick: {
            window.showRules();
        }
    }

    BarButton{
        id: btnSetting
        anchors.right: parent.right
        ico: "qrc:/images/color/settings.png"
        onClick: {
            window.showSettings();
        }
    }
}
