#include <QApplication>
#include <QTableWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTableWidget tableWidget;
    tableWidget.setColumnCount(3);
    tableWidget.setRowCount(5);

    QStringList headers;
    headers << "ID" << "Names" << "Age" << "Sex";
    tableWidget.setHorizontalHeaderLabels(headers);

    tableWidget.setItem(0, 0, new QTableWidgetItem(QString("0001")));
    tableWidget.setItem(1, 0, new QTableWidgetItem(QString("0002")));
    tableWidget.setItem(2, 0, new QTableWidgetItem(QString("0003")));
    tableWidget.setItem(3, 0, new QTableWidgetItem(QString("0004")));
    tableWidget.setItem(4, 0, new QTableWidgetItem(QString("0005")));
    tableWidget.setItem(0, 1, new QTableWidgetItem(QString("20220301")));

    tableWidget.show();

    return a.exec();
}
