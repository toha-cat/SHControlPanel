import QtQuick 2.5

Rectangle {

    TextEdit{
        id: textEditor
        anchors.fill:parent
        width:parent.width; height:parent.height
        color:"midnightblue"
        focus: true

        wrapMode: TextEdit.Wrap

        onCursorRectangleChanged: flickArea.ensureVisible(cursorRectangle)
    }
}
