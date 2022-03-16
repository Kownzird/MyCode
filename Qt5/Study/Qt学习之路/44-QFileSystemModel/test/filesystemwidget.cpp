#include "filesystemwidget.h"
#include <QFileSystemModel>
#include <QTreeView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QMessageBox>
#include <QHeaderView>
#include <QDebug>

FileSystemWidget::FileSystemWidget(QWidget *parent)
    : QWidget(parent)
{
    model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());

    treeView = new QTreeView(this);
    treeView->setModel(model);
    treeView->setRootIndex(model->index(QDir::currentPath())); //去掉这一句的话，我们的程序会显示整个文件系统的目录

    treeView->header()->setStretchLastSection(true); //自适应宽度
    treeView->header()->setSortIndicator(0, Qt::AscendingOrder);
    treeView->header()->setSortIndicatorShown(true);
    #if QT_VERSION >= 0x050000
        treeView->header()->setSectionsClickable(true);
    #else
        treeView->header()->setClickable(true);
    #endif

    QPushButton *mkdirBtn = new QPushButton(tr("Make Directory..."), this);
    QPushButton *rmBtn = new QPushButton(tr("Remove"), this);
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(mkdirBtn);
    buttonLayout->addWidget(rmBtn);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(treeView);
    layout->addLayout(buttonLayout);

    setLayout(layout);
    setWindowTitle("File System Model");

    connect(mkdirBtn, &QPushButton::clicked, this, &FileSystemWidget::mkdir);
    connect(rmBtn, &QPushButton::clicked, this, &FileSystemWidget::remove);

}


void FileSystemWidget::mkdir()
{
    QModelIndex index = treeView->currentIndex();
    if(!index.isValid()){
        return;
    }

    QString dirName = QInputDialog::getText(this, tr("Create Directory"), tr("Directory Name"));

    if(!dirName.isEmpty()){
        if(!model->mkdir(index, dirName).isValid()){
            QMessageBox::information(this, tr("Create Directory"), tr("Fail to create directory"));
        }
    }
}

void FileSystemWidget::remove()
{
    QModelIndex index = treeView->currentIndex();
    if(!index.isValid()){
        return;
    }

    bool ok;
    if(model->fileInfo(index).isDir()){
        ok = model->rmdir(index);
    }else{
        ok = model->remove(index);
    }

    if(!ok){
        QMessageBox::information(this, tr("Remove"), tr("Fail to remove %1").arg(model->fileName(index)));
    }
}

FileSystemWidget::~FileSystemWidget()
{
}


