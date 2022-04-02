import QtQuick 2.9
import QtQuick.Window 2.2


//定位器主要有 Row、Column、Grid和Flow等
Window {
    id:root
    visible: true
    width: 252
    height: 252
    title: qsTr("Hello World")

//    GreenRectangle {
//        x: 10
//        y: 10
//        width: 100
//        height: 100
//        BlueRectangle {
//            //锚点的优先级要高于宽度属性设置
//            width: 25
//            height: 25
//            anchors.fill: parent
//            anchors.margins: 8
//        }
//    }

//    GreenRectangle {
//        x:10
//        y:10
//        width: 100
//        height: 100
//        BlueRectangle{
//            width: 48
//            y:8
//            anchors.left: parent.left
//            anchors.leftMargin: 8
//        }
//    }

//    GreenRectangle {
//        x:10
//        y:10
//        width: 100
//        height: 100
//        BlueRectangle{
//            width: 48
//            y:8
//            anchors.left: parent.right
//        }
//    }


//    GreenRectangle {
//        x:10
//        y:10
//        width: 100
//        height: 100
//        BlueRectangle{
//            id:blue1
//            width: 48; height: 24
//            y:8
//            anchors.horizontalCenter: parent.horizontalCenter
//        }

//        BlueRectangle{
//            id:blue2
//            width: 72; height: 24
//            anchors.top: blue1.bottom
//            anchors.topMargin: 4
//            anchors.horizontalCenter: parent.horizontalCenter
//        }
//    }


//    GreenRectangle {
//        x:10
//        y:10
//        width: 100
//        height: 100
//        BlueRectangle {
//            width: 48
//            //将蓝色矩形的中心固定在父组件的中心
//            //不能再移动蓝色块
//            anchors.centerIn: parent
//        }
//    }


    GreenRectangle {
        x:10
        y:10
        width: 100
        height: 100
        BlueRectangle {
            width: 48
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.horizontalCenterOffset: -12
            anchors.verticalCenter: parent.verticalCenter
        }
    }

}
