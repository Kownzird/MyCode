#ifndef PROCESS_H
#define PROCESS_H

#include <QWidget>

class Process : public QWidget
{
    Q_OBJECT

public:
    Process(QWidget *parent = nullptr);
    ~Process();
};
#endif // PROCESS_H
