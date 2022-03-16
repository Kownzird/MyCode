#ifndef SHOWTABLEFORM_H
#define SHOWTABLEFORM_H

#include <QWidget>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class ShowTableForm; }
QT_END_NAMESPACE

class ShowTableForm : public QWidget
{
    Q_OBJECT

public:
    ShowTableForm(QWidget *parent = nullptr);
    ~ShowTableForm();

private:
    Ui::ShowTableForm *ui;
    QStandardItemModel *mModel;
};
#endif // SHOWTABLEFORM_H
