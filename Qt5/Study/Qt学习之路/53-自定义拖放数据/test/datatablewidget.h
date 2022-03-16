#ifndef DATATABLEWIDGET_H
#define DATATABLEWIDGET_H

#include <QWidget>
#include <QTableWidget>

class DataTableWidget : public QTableWidget
{
    Q_OBJECT

public:
    DataTableWidget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);

private:
    void performDrag();
    QString selectionText() const;

    QString toHtml(const QString& plainText) const;
    QString toCsv(const QString& plainText) const;
    void fromCsv(const QString& plaintext);

    QPoint startPos;

};
#endif // DATATABLEWIDGET_H
