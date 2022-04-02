import QtQuick 2.0

Rectangle {
    width: 48
    height: 48
    color: "blue"
    border.color: Qt.lighter(color)

    MouseArea {
        //拖动目标是parent。
        //我们的拖动对象是MouseArea的父组件，也就是BlueRectangle组件
        anchors.fill: parent
        drag.target: parent
    }
}
