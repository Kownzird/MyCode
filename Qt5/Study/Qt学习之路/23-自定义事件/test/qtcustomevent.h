#ifndef QTCUSTOMEVENT_H
#define QTCUSTOMEVENT_H

#include <QMainWindow>

class QtCustomEvent : public QMainWindow
{
    Q_OBJECT
public:
    QtCustomEvent(QApplication *pApp, QWidget *parent = nullptr);

protected:
    void customEvent(QEvent *event);
    bool event(QEvent *event);

private:
    QApplication *m_pApp;

};

#endif // QTCUSTOMEVENT_H
