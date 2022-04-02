import QtQuick 2.9
import QtQuick.Window 2.2

// 根元素
Window {
    // 命名根元素
    //声明属性：<name>: <value>
    //id 看起来同其它属性没有什么区别，但是，我们不能使用id反查出具体的值。例如，aElement.id是不允许的
    id:root
    visible: true
    width: 200
    height: 300
    title: qsTr("QML Program")

    // 声明一个嵌套元素（根元素的子元素）
    Image {
        id: rocket
        x: (parent.width - width)/2; y:60
        source: "./asset/rocket.png"
    }

    Text {
        y:rocket.y + rocket.height + 20 // 使用 id 引用元素
        width: root.width
        horizontalAlignment: Text.AlignHCenter
        text: "Rocket"
    }



    Text {
        // (1) 标识符
        id: thisLabel
        // (2) x、y 坐标
        x: 24; y: 16
        // (3) 绑定
        height: 2 * width
        // (4) 自定义属性
        property int times: 24
        // (5) 属性别名
//        property alias otherTimes: times
        // (6) 文本和值
        text: "Greetings " + times
        // (7) 字体属性组
        font.family: "Ubuntu"
        font.pixelSize: 24
        // (8) 附加属性 KeyNavigation
        KeyNavigation.tab: otherLabel
        // (9) 属性值改变的信号处理回调
        onHeightChanged: console.log('height:', height)
        // 接收键盘事件需要设置 focus
        focus: true
        // 根据 focus 值改变颜色
        color: focus?"red":"black"
    }

    //每一个属性都可以发出信号，因而都可以关联信号处理函数。这个处理函数将在属性值变化时调用。
    //这种值变化的信号槽命名为 on + 属性名 + Changed，其中属性名要首字母大写。
    Text {
        id: label
        x: 24; y: 48
        // 自定义属性，表示空格按下的次数
        property int spacePresses: 0
        text: "Space pressed: " + spacePresses + " times"
        // (1) 文本变化的响应函数
        onTextChanged: console.log("text changed to:", text)
        // 接收键盘事件，需要设置 focus 属性
        focus: true
        // (2) 调用 JavaScript 函数
        Keys.onSpacePressed: {
            increment()
        }
        // 按下 Esc 键清空文本
        Keys.onEscapePressed: {
            label.text = ''
        }
        // (3) 一个 JavaScript 函数
        function increment() {
            spacePresses = spacePresses + 1
        }
    }

}

