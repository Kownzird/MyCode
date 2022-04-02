import QtQuick 2.0

Rectangle {
    id:root

    //为了不对外暴露Text元素，我们给了它的text属性一个别名。
    property alias text: label.text
    signal clicked

    width: 116; height: 26
    color: "lightsteelblue"
    border.color: "slategray"

    Text {
        id:label
        anchors.centerIn: parent
        text:"Start"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            root.clicked()
        }
    }
}
