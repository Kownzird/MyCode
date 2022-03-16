#ifndef CUSTOMEVENT_H
#define CUSTOMEVENT_H

#include <QWidget>
#include <QEvent>


//自定义事件ID
//自定义事件ID范围是从QEvent::User(1000)到QEvent::MaxUser(65535)
//可以通过在前一次自定义事件ID的基础上加一的方式定义所有的自定义事件ID
const int CustomEventBaseID = QEvent::User;
const int ChangeNumberEventID = CustomEventBaseID + 1;

const QEvent::Type MyEventType = (QEvent::Type)QEvent::registerEventType(ChangeNumberEventID);

//自定义Qt事件派生类
class ChangeNumberEvent : public QEvent
{
public:
    ChangeNumberEvent(QObject* parent,int number); //数据和对象可以通过构造函数的参数进行传递，如此处就可以传入一个整数，
    int m_nNumber;                                  //事件接收方通过访问事件的成员变量m_nNumber就可以获取到这个整数
};

#endif // CUSTOMEVENT_H






