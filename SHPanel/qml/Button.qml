import QtQuick 2.5

Rectangle {
    property var btnText: "Кнопка"
    signal clicked // этот сигнал вызывается ниже при нажании в MouseArea
    id: button
    border.width: 1
    border.color: "black"
    radius: 5
    color: mArea.pressed ? "#AAAAAA" : "#EEEEEE"
    MouseArea
    {
        id: mArea
        anchors.fill: parent
        onClicked: button.clicked() // собственно тут мы и вызываем сигнал clicked
    }
    Text
    {
        anchors.fill: parent
        text: btnText
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}
