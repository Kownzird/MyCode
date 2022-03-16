#ifndef LABEL_H
#define LABEL_H

#include <QWidget>

class Label : public QWidget
{
    Q_OBJECT

public:
    Label(QWidget *parent = nullptr);
    ~Label();

    bool eventFilter(QObject *obj, QEvent *event);

protected:
    void mousePressEvent(QMouseEvent *event);
    bool event(QEvent *event);
};
#endif // LABEL_H
