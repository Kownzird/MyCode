#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QLabel;
class QListWidget;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QLabel *label;
    QListWidget *listWidget;
};
#endif // WIDGET_H
