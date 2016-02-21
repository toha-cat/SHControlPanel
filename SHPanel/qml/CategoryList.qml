import QtQuick 2.5

ListView {

    header: Rectangle {
        height: 42*dp
        width: parent.width

        Rectangle {
            anchors.fill: parent
            color: "#ddd"

            Rectangle{
                anchors.bottom: parent.bottom
                width: parent.width
                height: 1
                color: "#000"
            }

            Text {
                anchors.centerIn: parent
                renderType: Text.NativeRendering
                text: "Все устройства"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    viewListCategoryDev.hidden();
                    backend.selectCat(0);
                    mainMenuBar.title = "Все устройства";
                }
            }
        }
    }

    delegate: Item {

        height: 10*mm
        width: parent.width

        Rectangle {
            anchors.fill: parent
            color: "#ddd"

            Rectangle{
                anchors.bottom: parent.bottom
                width: parent.width
                height: 1
                color: "#000"
            }
            Rectangle{
                anchors.top: parent.top
                width: parent.width
                height: 1
                color: "#fff"
            }

            Text {
                anchors.centerIn: parent
                renderType: Text.NativeRendering
                text: model.name
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    viewListCategoryDev.hidden();
                    backend.selectCat(model.cid);
                    mainMenuBar.title = model.name;
                }
            }
        }
    }
}
