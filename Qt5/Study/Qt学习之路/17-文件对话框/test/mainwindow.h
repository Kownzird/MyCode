#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QTextEdit;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void openFile();
    void saveFile();

private:
    Ui::MainWindow *ui;
    QAction* openAction;
    QAction* saveAction;
    QTextEdit* textEdit;

};
#endif // MAINWINDOW_H
