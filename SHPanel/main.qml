import QtQuick 2.5
import QtQuick.Window 2.2
import QtQml.Models 2.2

Window {
    visible: true
/*
    MainForm {
        anchors.fill: parent
    }
*/

    ListControls{
        id: viewList
        model: dataModel
    }

}

