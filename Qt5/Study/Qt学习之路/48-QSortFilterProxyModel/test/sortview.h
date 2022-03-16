#ifndef SORTVIEW_H
#define SORTVIEW_H

#include <QWidget>

class QListView;
class QStringListModel;
class QSortFilterProxyModel;
class QComboBox;

class SortView : public QWidget
{
    Q_OBJECT

public:
    SortView();

private:
    QListView *view;
    QStringListModel *model;
    QSortFilterProxyModel *modelProxy;
    QComboBox *syntaxBox;

private slots:
    void filterChange(const QString& text);
};
#endif // SORTVIEW_H
