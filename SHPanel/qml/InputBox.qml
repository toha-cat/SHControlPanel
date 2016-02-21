import QtQuick 2.5

Rectangle
{
    id: loginInputBox
    border.width: 1
    border.color: "black"
    height: 40*dp
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.top: loginLabel.bottom
    TextInput
    {
        id: loginInput
        anchors.fill: parent
        anchors.margins: 10*dp
        font.pointSize: 14*dp
    }
}
