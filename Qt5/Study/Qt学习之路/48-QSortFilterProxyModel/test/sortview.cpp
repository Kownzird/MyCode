#include "sortview.h"
#include <QStringListModel>
#include <QSortFilterProxyModel>
#include <QListView>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QDebug>

SortView::SortView()
{
    model = new QStringListModel(QColor::colorNames(), this);

    modelProxy = new QSortFilterProxyModel(this);
    modelProxy->setSourceModel(model);
    //只对第一列进行过滤
    modelProxy->setFilterKeyColumn(0);

    view = new QListView(this);
    view->setModel(modelProxy);

    QLineEdit *filterInput = new QLineEdit;
    QLabel *filterLabel = new QLabel(tr("Filter"));
    QHBoxLayout *filterLayout = new QHBoxLayout;
    filterLayout->addWidget(filterLabel);
    filterLayout->addWidget(filterInput);

    syntaxBox = new QComboBox;
    syntaxBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    //正则表达式的几种类型
    syntaxBox->addItem(tr("Regular expression"), QRegExp::RegExp);
    syntaxBox->addItem(tr("Wildcard"), QRegExp::Wildcard);
    syntaxBox->addItem(tr("Fixed String"), QRegExp::FixedString);
    QLabel *syntaxLabel = new QLabel(tr("Syntax"));
    QHBoxLayout *syntaxLayout = new QHBoxLayout;
    syntaxLayout->addWidget(syntaxLabel);
    syntaxLayout->addWidget(syntaxBox);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(view);
    layout->addLayout(filterLayout);
    layout->addLayout(syntaxLayout);

    connect(filterInput, &QLineEdit::textChanged, this, &SortView::filterChange);

}

void SortView::filterChange(const QString& text)
{
    QRegExp::PatternSyntax syntax = QRegExp::PatternSyntax(syntaxBox->itemData(syntaxBox->currentIndex()).toInt());
    QRegExp regExp(text, Qt::CaseInsensitive, syntax);
    modelProxy->setFilterRegExp(regExp);
}



