#ifndef CUSTOMTEXTEDIT_H
#define CUSTOMTEXTEDIT_H

#include <QWidget>
#include <QTextEdit>

class CustomTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit CustomTextEdit(QWidget *parent = nullptr);

protected:
    bool event(QEvent *e);

};

#endif // CUSTOMTEXTEDIT_H
