#include "projectlistwidget.h"
#include <QMouseEvent>
#include <QApplication>
#include <QMimeData>
#include <QDrag>


ProjectListWidget::ProjectListWidget(QWidget *parent) : QListWidget(parent){
    setAcceptDrops(true);
}


//记录鼠标点击当前位置
void ProjectListWidget::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        startPos = event->pos();
    }
    QListWidget::mousePressEvent(event);
}


void ProjectListWidget::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() & Qt::LeftButton){
        int distance = (event->pos() - startPos).manhattanLength();
        if(distance >= QApplication::startDragDistance()){
            performDrag();
        }
    }
    QListWidget::mouseMoveEvent(event);
}

void ProjectListWidget::performDrag(){
    QListWidgetItem *item = currentItem();
    if(item){
        QMimeData *mimeData = new QMimeData;
        mimeData->setText(item->text());

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setPixmap(QPixmap(":/images/person.png"));

        //QDrag::exec()会阻塞拖动的操作，直到用户完成操作或者取消操作
        if(drag->exec(Qt::MoveAction) == Qt::MoveAction){
            delete item;
        }
    }
}


void ProjectListWidget::dragEnterEvent(QDragEnterEvent *event){
    event->acceptProposedAction();
}


void ProjectListWidget::dragMoveEvent(QDragMoveEvent *event){
    ProjectListWidget *source = qobject_cast<ProjectListWidget*>(event->source());
    //判断事件的来源（source）,不能是自己
    if(source && source!=this){
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }

}

void ProjectListWidget::dropEvent(QDropEvent *event){
    ProjectListWidget *source = qobject_cast<ProjectListWidget*>(event->source());
    if(source && source!=this){
        addItem(event->mimeData()->text());
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}


