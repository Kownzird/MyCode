import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id:root
    visible: true
    width: 200
    height: 200

//    Rectangle {
//        id:rect
//        width: root.width
//        height: root.height
//        color: "lightsteelblue"
//        border{
//            color: "#FF0000"
//            width: 4
//        }
//        radius: 8
//    }

//    Rectangle {
//        id:rect
//        width:root.width
//        height: root.height

//        //gradient要求一个Gradient对象。
//        //该对象需要一个GradientStop的列表。
//        gradient: Gradient {
//            GradientStop {position: 0.0; color: "red"}
//            GradientStop {position: 0.33; color: "yellow"}
//            GradientStop {position: 1.0; color:"green"}
//        }
//        border.color: "slategray"
//    }

//    Text {
//        id: text
//        text: qsTr("The quick brown fox")
//        color: "#303030"
//        font.family: "Century"
//        font.pixelSize: 28
//    }

    //horizontalAlignment和verticalAlignment属性指定对齐方式
//    Text{
//        id:text
//        width: 160
//        height: 120
//        text: "A very very long text"

//        //省略
//        elide: Text.ElideMiddle

//        style: Text.Sunken
//        styleColor: '#FF4444'
//        verticalAlignment: Text.AlignTop
//        font {
//            pixelSize: 24
//        }
//    }

    Image {
        id: img1
        x:10
        y:10
//        source: "./asset/rocket.png"
        source: "file:///D:/4-TestCode/Qt/test/test/asset/rocket.png"

        //等比例切割
        fillMode: Image.PreserveAspectCrop
        clip: true
    }

    Image {
        id: img2
        x:110
        y:10
        source: "https://openweathermap.org/img/w/01d.png"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit()
        }
    }
}

