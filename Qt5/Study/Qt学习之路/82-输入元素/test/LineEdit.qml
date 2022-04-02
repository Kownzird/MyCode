import QtQuick 2.0


//当FocusScope接收到焦点时，会将焦点转发给最后一个设置了focus:true的子对象。
FocusScope {
    width: 96
    height: input.height + 8

    property alias text: input.text
    property alias input: input

    //增加一个rectangle用作背景色和边框
    Rectangle {
        anchors.fill:parent
        color:"lightsteelblue"
        border.color: "gray"
    }

    TextInput {
        id:input
        anchors.fill: parent
        anchors.margins: 4
        focus: true
    }
}
