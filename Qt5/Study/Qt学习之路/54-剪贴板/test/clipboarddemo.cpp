#include "clipboarddemo.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QClipboard>
#include <QApplication>

ClipboardDemo::ClipboardDemo(QWidget *parent)
    : QWidget(parent){
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *northLayout = new QHBoxLayout;
    QHBoxLayout *southLayout = new QHBoxLayout;

    QTextEdit *editor = new QTextEdit;
    QLabel *label = new QLabel;
    label->setText("Text Input:");
    label->setBuddy(editor);
    QPushButton *copyButton = new QPushButton;
    copyButton->setText("Set Clipboard");
    QPushButton *pasteButton = new QPushButton;
    pasteButton->setText("Get Clipboard");

    northLayout->addWidget(label);
    northLayout->addWidget(editor);
    southLayout->addWidget(copyButton);
    southLayout->addWidget(pasteButton);
    mainLayout->addLayout(northLayout);
    mainLayout->addLayout(southLayout);

    connect(copyButton, &QPushButton::clicked, this, &ClipboardDemo::setClipboardContent);
    connect(pasteButton, &QPushButton::clicked, this, &ClipboardDemo::getClipboardContent);

}


void ClipboardDemo::setClipboardContent(){
    QClipboard *board = QApplication::clipboard();
    board->setText("Text from Qt Application");
}


void ClipboardDemo::getClipboardContent(){

}


