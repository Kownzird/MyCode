import QtQuick 2.0

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

    TextEdit {
        id:input
        anchors.fill: parent
        anchors.margins: 4
        focus: true
    }
}
