import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id:root
    visible: true
    width: 200
    height: 200
    title: qsTr("Hello World")

    Rectangle {
        width: root.width
        height: root.height
        color: "linen"

//        TextInput {
//            id:input1
//            x:8; y:8
//            width: 96; height: 20
//            focus: true
//            text:"Text Input 1"
//            KeyNavigation.tab: input2
//            KeyNavigation.down: input2
//        }

//        TextInput {
//            id:input2
//            x:8; y:36
//            width: 96; height: 20
//            focus: true
//            text:"Text Input 2"
//            KeyNavigation.tab: input1
//            KeyNavigation.up: input1
//        }

        LineEdit {
            id:input1
            x:8; y:8
            width: 110; height: 20
            focus: true
            text: "Text Input 1"
            KeyNavigation.tab: input2
        }

        LineEdit {
            id:input2
            x:8; y:36
            width: 110; height: 20
            focus: true
            text:"Text Input 2"
            KeyNavigation.tab: input3
        }

        LinesEdit {
            id:input3
            x:8; y:64
            width: 110; height: 100
            focus: true
            text:"Text Input 3"
            KeyNavigation.up: input2
        }


    }
}
