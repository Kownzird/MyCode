#include "workthread.h"

WorkThread::WorkThread(QObject *parent) : QThread(parent)
{

}


void WorkThread::run(){
    for(int i = 0; i < 1000000000; i++);
    emit done();
}
