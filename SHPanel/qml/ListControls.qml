import QtQuick 2.5

GridView {
    anchors.margins: 10
    cellHeight: 150*dp
    cellWidth: cellHeight
    clip: true

    delegate: Loader {
        source: model.modelData.type + ".qml"
    }
}
