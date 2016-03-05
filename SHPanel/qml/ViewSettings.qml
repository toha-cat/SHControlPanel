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

    Rectangle{
        id: settingForm
        anchors.top: titleBar.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: 20*dp
        anchors.leftMargin: parent.width * 0.1
        anchors.rightMargin: parent.width * 0.1

        Button
        {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: serverInputBox.bottom
            anchors.topMargin: 30*dp
            height: 40*dp
            btnText: "Вийти"
            onClicked:
            {
                window.showLoginForm();
            }
        }
    }
}
