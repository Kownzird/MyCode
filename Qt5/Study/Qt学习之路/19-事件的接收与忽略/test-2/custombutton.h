#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QWidget>
#include <QPushButton>

class CustomButton : public QPushButton
{
    Q_OBJECT
public:
    CustomButton(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event);

};



class CustomButtonEx : public CustomButton
{
    Q_OBJECT
public:
    CustomButtonEx(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event);

};


class CustomWidget : public QWidget
{
    Q_OBJECT
public:
    CustomWidget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // CUSTOMBUTTON_H
