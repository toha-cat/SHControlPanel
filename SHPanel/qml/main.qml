import QtQuick 2.5
import QtQuick.Window 2.2
import QtQml.Models 2.2

Window {
    visible: true
    width: 220
    height: 250

    Rectangle{
        id: viewListDevice
        anchors.fill: parent
        z: 1

        MenuBar{
            id: mainMenuBar
            anchors.top: parent.top
            color: "skyblue"
            title: "Main page"
        }

        ListControls{
            id: viewList
            model: deviceModel
            anchors.top: mainMenuBar.bottom
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
        }
    }

    Rectangle{
        id: viewListCategoryDev
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        z: 2
        visible: true
        color: "#00ffffff"
        state:"hidden"
        width: parent.width;

        function show(){
            state = "visibled";
        }
        function hidden(){
            state = "hidden";
        }

        states: [
            State {
                name: "hidden"
                PropertyChanges { target: viewListCategoryDev; x: -width}
            },

            State {
                name: "visibled"
                PropertyChanges { target: viewListCategoryDev; x: 0}
            }
        ]

        transitions: Transition {
            NumberAnimation { properties: "x"; duration: 500; easing.type: Easing.OutQuad }
        }

        Rectangle{
            id: boxCategoryDev
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            color: "#ddd"
            width: parent.width*2/3

            CategoryList{
                id: listCategoryDev
                anchors.fill: parent
                model: catDeviceModel
            }
        }
        Rectangle{
            id: bgCategoryDev
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            width: parent.width/3
            color: "#00ffffff"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    viewListCategoryDev.hidden();
                }
            }
        }
    }
}

