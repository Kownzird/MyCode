import QtQuick 2.9
import QtQuick.Window 2.2


//定位器主要有 Row、Column、Grid和Flow等
Window {
    id:root
    visible: true
    width: 252
    height: 252
    title: qsTr("Hello World")

    Rectangle {
        id:rect
        width: root.width
        height: root.height
        color: "black"

//        Column {
//            id:row
//            anchors.centerIn: parent
//            spacing: 8
//            RedRectangle{}
//            GreenRectangle{width: 96}
//            BlueRectangle{}
//        }

//        Row {
//            id:column
//            anchors.centerIn: parent
//            spacing: 8
//            RedRectangle{}
//            GreenRectangle{}
//            BlueRectangle{}
//        }


//        Grid {
//            id:grid
//            rows:2
//            anchors.centerIn: parent
//            spacing: 8
//            RedRectangle{}
//            GreenRectangle{}
//            BlueRectangle{}
//            YellowRectangle{}
//        }

        //Flow 会将其子元素以流的形式显示出来
        //Column和Row极其类似。不同之处在于，添加到Flow里面的元素，
        //当Flow的宽度或高度不足时，这些元素会自动换行
//        Flow {
//            anchors.centerIn: parent
//            anchors.margins: 20
//            spacing: 20
//            flow:Flow.LeftToRight
//            RedRectangle{}
//            GreenRectangle{}
//            BlueRectangle{}
//            YellowRectangle{}
//        }

        property variant colorArray: ["#00bde3", "#67c111", "#ea7025"]
        Grid {
            anchors.centerIn: parent
            anchors.margins: 8
            spacing: 4
            Repeater {
                model:16
                Rectangle {
                    width: 56; height: 56

                    //radom()返回[0.0,1.0)之间的小数，不包含1
                    property int colorIndex: Math.floor(Math.random()*3)
                    color: rect.colorArray[colorIndex]
                    border.color: Qt.lighter(color)
                    Text{
                        anchors.centerIn: parent
                        color: "black"
                        text:"cell" + index
                    }
                }
            }
        }
    }
}
