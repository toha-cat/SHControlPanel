import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    id: window
    visible: true
    width: 325
    height: 400

    property var currentView: "devices"

    function showLoginForm()
    {
        currentView = "login"
        loaderContent.source = "qrc:/qml/ViewLogin.qml"
    }

    function showDevicePage()
    {
        currentView = "devices"
        loaderContent.source = "qrc:/qml/ViewDevices.qml"
    }

    function showSettings()
    {
        currentView = "settings"
        loaderContent.source = "qrc:/qml/ViewSettings.qml"
    }

    function showRules()
    {
        currentView = "rules"
        loaderContent.source = "qrc:/qml/ViewRules.qml"
    }

    function showMessage(mess)
    {
        alertMesage.text = mess;
        alertMesageBox.state = "visibled";
    }

    function hideMessage()
    {
        alertMesageBox.state = "hidden";
    }

    Loader{
        id: loaderContent
        source: "qrc:/qml/ViewDevices.qml"
        anchors.fill: parent
        z: 1
    }

    Rectangle{
        id: alertMesageBox
        anchors.left: parent.left
        anchors.right: parent.right

        height: 50*dp
        color: "#FF5555"
        state:"hidden"
        z: 2

        states: [
            State {
                name: "hidden"
                PropertyChanges { target: alertMesageBox; y: parent.height+height}
            },

            State {
                name: "visibled"
                PropertyChanges { target: alertMesageBox; y: parent.height-height}
            }
        ]

        transitions: Transition {
            NumberAnimation { properties: "y"; duration: 500; easing.type: Easing.OutQuad }
        }

        Text {
            id: alertMesage
            anchors.fill: parent
            anchors.margins: 7*dp
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 11*dp
            wrapMode: Text.WordWrap
            renderType: Text.NativeRendering
            text: qsTr("test")
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                hideMessage();
            }
        }
    }
}

