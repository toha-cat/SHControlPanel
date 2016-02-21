import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    id: window
    visible: true
    width: 325
    height: 400

    property var currentView: "devices"

    function showLoginForm(){
        currentView = "login"
        loaderContent.source = "qrc:/qml/ViewLogin.qml"
    }

    function showDevicePage(){
        currentView = "devices"
        loaderContent.source = "qrc:/qml/ViewDevices.qml"
    }

    function showSettings(){
        currentView = "settings"
        loaderContent.source = "qrc:/qml/ViewSettings.qml"
    }

    function showRules(){
        currentView = "rules"
        loaderContent.source = "qrc:/qml/ViewRules.qml"
    }

    Loader{
        id: loaderContent
        source: "qrc:/qml/ViewDevices.qml"
        anchors.fill: parent
    }

}

