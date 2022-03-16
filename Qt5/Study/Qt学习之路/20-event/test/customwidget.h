#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>


class CustomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CustomWidget(QWidget *parent = nullptr);

protected:
    bool event(QEvent *e);

};

#endif // CUSTOMWIDGET_H
