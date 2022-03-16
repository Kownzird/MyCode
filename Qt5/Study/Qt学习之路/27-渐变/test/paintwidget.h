#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>

class PaintWidget : public QWidget
{
    Q_OBJECT

public:
    PaintWidget(QWidget *parent = nullptr);
    ~PaintWidget();

protected:
    void paintEvent(QPaintEvent *event);
};
#endif // PAINTWIDGET_H
