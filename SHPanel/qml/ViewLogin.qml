import QtQuick 2.5
Rectangle{
    color: "#4D90FE"

    Rectangle {
        id: loginForm
        anchors.fill: parent
        anchors.leftMargin: parent.width * 0.1
        anchors.rightMargin: parent.width * 0.1
        color: "#4D90FE"

        Text
        {
            id: loginLabel
            height: 20*dp
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.topMargin: 40*dp
            font.pixelSize: 16*dp
            text: 'Логин'
        }
        Rectangle
        {
            id: loginInputBox
            border.width: 1
            border.color: "black"
            height: 40*dp
            radius: 5
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: loginLabel.bottom
            TextInput
            {
                id: loginInput
                anchors.fill: parent
                anchors.margins: 10*dp
                font.pixelSize: 18*dp
            }
        }
        Text
        {
            id: passwordLabel
            height: 20*dp
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: loginInputBox.bottom
            anchors.topMargin: 20*dp
            font.pixelSize: 16*dp
            text: 'Пароль'
        }
        Rectangle
        {
            id: passwordInputBox
            border.width: 1
            border.color: "black"
            height: 40*dp
            radius: 5
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: passwordLabel.bottom
            TextInput
            {
                id: passwordInput
                anchors.fill: parent
                anchors.margins: 10*dp
                font.pixelSize: 18*dp
            }
        }
        Text
        {
            id: serverLabel
            height: 20*dp
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: passwordInputBox.bottom
            anchors.topMargin: 20*dp
            font.pixelSize: 16*dp
            text: 'Адрес сервера'
        }
        Rectangle
        {
            id: serverInputBox
            border.width: 1
            border.color: "black"
            height: 40*dp
            radius: 5
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: serverLabel.bottom
            TextInput
            {
                id: serverInput
                anchors.fill: parent
                anchors.margins: 10*dp
                font.pixelSize: 18*dp
            }
        }

        Button
        {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: serverInputBox.bottom
            anchors.topMargin: 30*dp
            height: 40*dp
            btnText: "Вход"
            onClicked:
            {
                console.log("clicked") // вывод отладочной информации
            }
        }

    }
}
