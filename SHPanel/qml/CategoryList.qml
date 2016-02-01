import QtQuick 2.5
import QtQml.Models 2.2

ListView {

    delegate: Item {

        height: 7*mm
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
                text: model.text
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    viewListCategoryDev.hidden();
                    backend.selectCat(model.cid);
                }
            }
        }
    }
}
