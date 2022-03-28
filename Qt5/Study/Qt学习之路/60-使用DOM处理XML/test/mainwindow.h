#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QDomElement;
class QTreeWidgetItem;
class QTreeWidget;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool readFile(const QString &fileName);

private:
    void parseBookindexElement(const QDomElement &element);
    void parseEntryElement(const QDomElement &element, QTreeWidgetItem *parent);
    void parsePageElement(const QDomElement &element, QTreeWidgetItem *parent);
    QTreeWidget *treeWidget;
};
#endif // MAINWINDOW_H
