#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QTableWidget;
class QItemSelectionModel;
class QItemSelection;
class QModelIndex;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void updateSelection(const QItemSelection& selected, const QItemSelection& deselected);
    void changeCurrent(const QModelIndex& current, const QModelIndex& previous);

private:
    QTableWidget *tableWidget;
    QItemSelectionModel *selectionModel;
};
#endif // WIDGET_H
