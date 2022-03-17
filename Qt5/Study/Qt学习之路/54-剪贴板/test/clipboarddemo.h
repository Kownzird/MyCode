#ifndef CLIPBOARDDEMO_H
#define CLIPBOARDDEMO_H

#include <QWidget>

class ClipboardDemo : public QWidget
{
    Q_OBJECT

public:
    ClipboardDemo(QWidget *parent = nullptr);

private slots:
    void setClipboardContent();
    void getClipboardContent();
};
#endif // CLIPBOARDDEMO_H
