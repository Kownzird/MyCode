#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置单选按钮  男默认选中
    ui->rBtnMan->setChecked(true);

    //选中女后 打印信息
    connect(ui->rBtnWoman,&QRadioButton::clicked,[=](){
        qDebug() << "选中女单选按钮";
    });

    //多选按钮  2选中  1半选  0未选
    connect(ui->cBox4,&QCheckBox::stateChanged,[=](int state){
        qDebug() << state;
    });


    //利用listWidget写诗
//    QListWidgetItem* item = new QListWidgetItem("锄禾日当午");
//    //将一行诗放入listWidget控件当中
//    ui->listWidget->addItem(item);
//    item->setTextAlignment(Qt::AlignHCenter);

    //QStringList  QList<QString>
    QStringList list;
    list << "锄禾日当午" << "汗滴禾下土" << "谁知盘中餐" << "粒粒皆辛苦";
    ui->listWidget->addItems(list);


}

Widget::~Widget()
{
    delete ui;
}

