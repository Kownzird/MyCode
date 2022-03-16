#ifndef PROJECTLISTWIDGET_H
#define PROJECTLISTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QListWidget>

class ProjectListWidget : public QListWidget
{
    Q_OBJECT
public:
    ProjectListWidget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void dragEnterEvent(QDragEnterEvent* event);
    void dragMoveEvent(QDragMoveEvent* event);
    void dropEvent(QDropEvent *event);

private:
    void performDrag();
    QPoint startPos;

};

#endif // PROJECTLISTWIDGET_H
