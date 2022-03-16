#include "currencymodel.h"
#include <QVariant>

CurrencyModel::CurrencyModel(QWidget *parent)
    : QAbstractTableModel(parent){

}

//rowCount()和columnCount()用于返回行和列的数目
int CurrencyModel::rowCount(const QModelIndex &parent) const{
    return currencyMap.count();
}

int CurrencyModel::columnCount(const QModelIndex &parent) const{
    return currencyMap.count();
}

//headerData()用于返回列名
QVariant CurrencyModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if(role != Qt::DisplayRole){
        return QVariant();
    }
    return currencyAt(section);
}


QString CurrencyModel::currencyAt(int offset) const{
    return (currencyMap.begin()+offset).key();
}


//用于设置底层的实际数据
void CurrencyModel::setCurrencyMap(const QMap<QString, double> &map){
    beginResetModel();
    currencyMap = map;
    endResetModel();
}

QVariant CurrencyModel::data(const QModelIndex &index, int role) const{
    if(!index.isValid()){
        return QVariant();
    }

    if(role == Qt::TextAlignmentRole){
        return int(Qt::AlignRight | Qt::AlignVCenter);
    }
    else if(role == Qt::DisplayRole || role == Qt::EditRole){
        QString rowCurrency = currencyAt(index.row());
        QString columnCurrency = currencyAt(index.column());
        if(currencyMap.value(rowCurrency) == 0.0){
            return "####";
        }
        double amount = currencyMap.value(columnCurrency) / currencyMap.value(rowCurrency);
        return QString("%1").arg(amount, 0, 'f', 4);
    }
    return QVariant();
}

//只有行和列的索引不一致的时候，我们才允许修改
Qt::ItemFlags CurrencyModel::flags(const QModelIndex& index) const{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    if(index.row() != index.column()){
        flags |= Qt::ItemIsEditable;
    }
    return flags;
}



bool CurrencyModel::setData(const QModelIndex &index, const QVariant &value, int role){
    if(index.isValid() && index.row()!=index.column() && role == Qt::EditRole){
        QString columnCurrency = headerData(index.column(), Qt::Horizontal, Qt::DisplayRole).toString();
        QString rowCurrency = headerData(index.row(), Qt::Vertical, Qt::DisplayRole).toString();

        //value所修改的值为，需要乘以行向货币汇率才可得出列向货币汇率
        currencyMap.insert(columnCurrency, value.toDouble() * currencyMap.value(rowCurrency));
        return true;
    }
    return false;
}




