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
    else if(role == Qt::DisplayRole){
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




