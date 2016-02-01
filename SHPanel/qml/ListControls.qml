import QtQuick 2.5

GridView {

    anchors.margins: 10
    //anchors.fill: parent
    cellHeight: 100
    cellWidth: cellHeight
    clip: true


    highlight: Rectangle {
        color: "skyblue"
    }

    function getDelegate(){
        delegate = (model.type==1) ? Qt.createComponent("ControlLed.qml") : Qt.createComponent("TestBtn.qml");
        return delegate
    }

    delegate: Loader {
        source: model.modelData.type + ".qml"
        //parent: this
    }

/*
    delegate: Item {
        property var view: GridView.view
        property var isCurrent: GridView.isCurrentItem

        height: view.cellHeight
        width: view.cellWidth

        Rectangle {
            anchors.margins: 5
            anchors.fill: parent
            color: model.color
            border {
                color: "black"
                width: 1
            }

            Text {
                anchors.centerIn: parent
                renderType: Text.NativeRendering
                //text: "%1%2".arg(model.text).arg(isCurrent ? " *" : "")

                function getText(){
                    if(isCurrent){
                        return "%1%2".arg(model.text).arg(" *")
                    }
                    else{
                        return "%1%2".arg(model.text).arg("")
                    }
                }
                text: getText()
            }

            MouseArea {
                anchors.fill: parent
                onClicked: view.currentIndex = model.index
            }
        }
    }
    */
}

