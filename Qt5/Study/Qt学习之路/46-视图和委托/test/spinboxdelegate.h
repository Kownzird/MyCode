#ifndef SPINBOXDELEGATE_H
#define SPINBOXDELEGATE_H

#include <QObject>
#include <QWidget>
#include <QStyledItemDelegate>

class SpinBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    SpinBoxDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent){}

    //返回一个组件。该组件会被作为用户编辑数据时所使用的编辑器，从模型中接受数据，返回用户修改的数据。
    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    //提供上述组件在显示时所需要的默认值。
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    //确保上述组件作为编辑器时能够完整地显示出来。
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

    //返回给模型用户修改过的数据。
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

signals:




};

#endif // SPINBOXDELEGATE_H
