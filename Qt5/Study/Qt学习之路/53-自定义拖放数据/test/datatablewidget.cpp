#include "datatablewidget.h"
#include <QMouseEvent>
#include <QApplication>
#include <QMimeData>
#include <QDrag>
#include <QDebug>

DataTableWidget::DataTableWidget(QWidget *parent)
    : QTableWidget(parent)
{
    setAcceptDrops(true);
    setSelectionMode(ContiguousSelection); //选择模式设置为连续

    setColumnCount(3);
    setRowCount(5);
}


void DataTableWidget::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        startPos = event->pos();
    }
    QTableWidget::mousePressEvent(event);
}


void DataTableWidget::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() & Qt::LeftButton){
        int distance = (event->pos() - startPos).manhattanLength();
        if(distance >= QApplication::startDragDistance()){
            performDrag();
        }
    }
}


void DataTableWidget::dragEnterEvent(QDragEnterEvent *event){
    DataTableWidget *source = qobject_cast<DataTableWidget*>(event->source());
    if(source && source!=this){
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}


void DataTableWidget::dragMoveEvent(QDragMoveEvent *event){
    DataTableWidget *source = qobject_cast<DataTableWidget*>(event->source());
    if(source && source!=this){
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void DataTableWidget::dropEvent(QDropEvent *event){
    if(event->mimeData()->hasFormat("text/csv")){
        QByteArray csvData = event->mimeData()->data("text/csv");

        qDebug() << "dropEvent csvData:" << csvData;
        QString csvText = QString::fromUtf8(csvData);
        qDebug() << "dropEvent csvText:" << csvText;
        fromCsv(csvText);
        event->acceptProposedAction();
    }
}

void DataTableWidget::performDrag(){
    //获取选择的文本
    QString selectionString = selectionText();
    if(selectionString.isEmpty()){
        return;
    }
    qDebug() << "performDrag selectionString:" << selectionString;

    QMimeData *mimeData = new QMimeData;
    mimeData->setHtml(toHtml(selectionString));
    mimeData->setData("text/csv", toCsv(selectionString).toUtf8());

    QDrag *drag = new  QDrag(this);
    drag->setMimeData(mimeData);

    //当执行的是移动时，将已选区域清除
    if(drag->exec(Qt::CopyAction | Qt::MoveAction) == Qt::MoveAction){
        selectionModel()->clearSelection();
    }
    qDebug() << "Finish performDrag";
}


QString DataTableWidget::selectionText() const{
    QString selectionString;
    QString headerString;
    QAbstractItemModel *itemmodel = model();
    QTableWidgetSelectionRange selection = selectedRanges().at(0);

    for(int row = selection.topRow(), firstRow = row; row <= selection.bottomRow(); row++){
        for(int col = selection.leftColumn(); col <= selection.rightColumn(); col++){
            if(row == firstRow){
                headerString.append(horizontalHeaderItem(col)->text()).append("\t");
            }
            QModelIndex index = itemmodel->index(row, col);
            selectionString.append(index.data().toString()).append("\t");
        }

        selectionString = selectionString.trimmed();
        selectionString.append("\n");
    }

    qDebug() << "selectionString:" << selectionString;
    qDebug() << "headerString:" << headerString;
    qDebug() << "return string:" << headerString.trimmed() + "\n" + selectionString.trimmed();

    return headerString.trimmed() + "\n" + selectionString.trimmed();
}


QString DataTableWidget::toHtml(const QString &plainText) const{
#if QT_VERSION >= 0x050000
    QString result = plainText.toHtmlEscaped();
#else
    QString result = Qt::escape(plainText);
#endif
    result.replace("\t", "<td>");
    result.replace("\n", "\n<tr><td>");
    result.prepend("<table>\n<tr><td>");
    result.append("\n</table>");
    return result;
}


QString DataTableWidget::toCsv(const QString &plainText) const
{
    QString result = plainText;
    result.replace("\\", "\\\\");
    result.replace("\"", "\\\"");
    result.replace("\t", "\", \"");
    result.replace("\n", "\"\n\"");
    result.prepend("\"");
    result.append("\"");
    return result;
}


void DataTableWidget::fromCsv(const QString &csvText)
{
    QStringList rows = csvText.split("\n");
    QStringList headers = rows.at(0).split(", ");

    qDebug() << "fromCsv rows:" << rows;
    qDebug() << "fromCsv headers:" << headers;

    for (int h = 0; h < headers.size(); ++h) {
        QString header = headers.at(h);
        headers.replace(h, header.replace('"', ""));
    }

    qDebug() << "fromCsv headers handle:" << headers;

    setHorizontalHeaderLabels(headers);
    for (int r = 1; r < rows.size(); ++r) {
        QStringList row = rows.at(r).split(", ");
        for(int c = 0; c < row.size(); c++){
            setItem(r - 1, c, new QTableWidgetItem(row.at(c).trimmed().replace('"', "")));
        }
    }
}
