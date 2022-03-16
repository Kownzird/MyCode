#include "customevent.h"

ChangeNumberEvent::ChangeNumberEvent(QObject* parent,int number)
    :QEvent(MyEventType)
    , m_nNumber(number)
{

}
