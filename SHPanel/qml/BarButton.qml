import QtQuick 2.5

Rectangle{
    signal click()
    property string ico: ""

    id: barBtn
    anchors.top: parent.top
    anchors.bottom: parent.bottom
    width: parent.height
    color: mArea.pressed ? "skyblue" : parent.color

    Image {
        id: icoCategory
        source: ico
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        anchors.margins: 5*dp
    }
    MouseArea{
        id: mArea
        anchors.fill: parent
        onClicked: {
            barBtn.click();
        }
    }
}
