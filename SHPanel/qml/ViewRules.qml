import QtQuick 2.5

Rectangle{

    TitleBar{
        id: titleBar
        anchors.top: parent.top
        title: "Правила автоматізації"
        onBack: {
            window.showDevicePage();
        }
    }

    ListView {
        anchors.top: titleBar.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        clip: true
        model: rulesModel

        delegate: Item {

            height: 40*dp
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

                Rectangle{
                    id: btnState
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.left: bottom.left
                    anchors.margins: 5*dp
                    width: 40*dp
                    color: parent.color
                    Rectangle{
                        anchors.top: parent.top
                        anchors.right: parent.right
                        width: 1
                        height: parent.height
                        color: "#999"
                    }
                    Image {
                        id: btnStateIco
                        anchors.fill: parent
                        fillMode: Image.PreserveAspectFit
                        source: model.state ? "qrc:/images/color/checked.png" : "qrc:/images/color/cancel.png"
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            if(model.state == 1){
                                backend.changeRuleState(model.rId, 0);
                            }
                            else{
                                backend.changeRuleState(model.rId, 1);
                            }
                        }
                    }
                }

                Rectangle{
                    id: btnEdit
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    anchors.margins: 5*dp
                    width: 40*dp
                    color: parent.color

                    Rectangle{
                        anchors.top: parent.top
                        anchors.left: parent.left
                        width: 1
                        height: parent.height
                        color: "#999"
                    }
                    Image {
                        id: btnEditIco
                        anchors.fill: parent
                        fillMode: Image.PreserveAspectFit
                        source: "qrc:/images/color/edit.png"
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {

                        }
                    }
                }

                Text {
                    anchors.left: btnState.right
                    anchors.right: btnEdit.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.margins: 5*dp
                    renderType: Text.NativeRendering
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    text: model.name
                }
            }
        }
    }
}
