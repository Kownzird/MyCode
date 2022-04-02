import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id:root
    visible: true
    width: 200
    height: 200

    Button {
        id:button
        x:20; y:20
//        text: "Start"
        onClicked: {
            status.text = "Button clicked!"
            text = "Clicked"
        }
    }

    Text {
        id:status
        x:20; y:70
        width: 116; height: 26
        text:"Waiting..."
        horizontalAlignment: Text.AlignHCenter
    }

}

