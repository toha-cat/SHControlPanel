import QtQuick 2.5

Rectangle{

    TitleBar{
        id: titleBar
        anchors.top: parent.top
        title: "Налаштування"
        onBack: {
            window.showDevicePage();
        }
    }
}
