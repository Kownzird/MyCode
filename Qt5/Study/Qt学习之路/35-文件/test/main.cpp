
#include <QApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << QDir::currentPath();

    QFile file("in.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug() << "Open file fail";
    } else {
        while (!file.atEnd()) {
            qDebug() << file.readLine().toStdString().c_str();
        }
    }

    QFileInfo info(file);
    qDebug() << info.isDir();
    qDebug() << info.isExecutable();
    qDebug() << info.baseName();
    qDebug() << info.completeBaseName();
    qDebug() << info.suffix();
    qDebug() << info.completeSuffix();

    return a.exec();
}
