#include <QApplication>
#include <QObject>
#include <QLinkedList>
#include <QDebug>


#define JAVASTYLE 0
#define STLSTYLE  1


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if JAVASTYLE
    //Java风格遍历器
    //Qlist正序倒叙遍历
    QList<QString> list;
    list << "A" << "B" << "C" << "D";

    qDebug() << "list:";
    QListIterator<QString> it(list);
    while (it.hasNext()) {
        qDebug() << it.next();
    }

    while (it.hasPrevious()){
        qDebug() << it.previous();
    }


    //QList移除
    QList<int> list_2;
    for(int i=0; i<10; i++){
        list_2.append(i);
    }

    QMutableListIterator<int> it2(list_2);
    while (it2.hasNext()) {
        if(it2.next() % 2 != 0){
            it2.remove();
        }
    }

    it2.toFront(); //迭代器指回头部

    qDebug() << "list2:";
    while (it2.hasNext()){
        qDebug() << it2.next();
    }

    //QList修改
    it2.toFront();
    while (it2.hasNext()) {
        if(it2.next() < 128){
            it2.setValue(128);
        }
    }
    it2.toFront();
    qDebug() << "list2:";
    while (it2.hasNext()) {
        qDebug() << it2.next();
    }


    //QMap QHash
    QMap<int, QWidget*> map;
    QHash<int, QWidget*> hash;

    QMapIterator<int, QWidget*> i(map);
    while (i.hasNext()) {
        i.next();
        hash.insert(i.key(), i.value());
    }
#endif


#if STLSTYLE
    //STL风格遍历器
    //QList
    QList<QString> list;
    list << "A" << "B" << "C" << "D";

    QList<QString>::iterator i;
    for(i=list.begin(); i!=list.end(); ++i){
        *i = (*i).toLower();
    }

    qDebug() << "list:toLower";
    QList<QString>::const_iterator j;
    for(j=list.constBegin(); j!=list.constEnd(); ++j){
        qDebug() << (*j);
    }


    QVector<int> m, n;
    m.resize(100000); // 使用 0 填充一个非常大的 vector

    QVector<int>::iterator it = m.begin();
    // 使用遍历器 it 的错误方式（注意，此时，m 上面已经有一个正在遍历的遍历器）:
    n = m;
    /*
        现在，我们的万分小心遍历器 it。因为它指向了共享的数据。
        如果我们执行语句 *it = 4，我们就会改变了共享的数据实例（两个 vector 都会被改变）。
        这里的行为与 STL 容器不同，因此这种问题仅出现在 Qt 中；使用 STL 标准容器不存在这个问题。
    */

    m[0] = 5;
    /*
        现在，容器 m 被修改了，其实际数据已经与共享数据不同，
        即使 i 就是从容器 a 创建的遍历器，但是它指向的数据与 m 并不一致，其表现就像是 n 的遍历器。
        这里的情形是：(*i) == 0.
    */

    n.clear(); // 现在我们清空 b，此时，遍历器 i 已经不可用了。

    int it2 = *it; // 无定义行为！
    /*
        来自 b 的数据（也就是 i 指向的那些数据）已经被销毁了。
        这种行为在 STL 容器中是完全可行的（在 STL 容器中，(*i) == 5），
        但是使用 QVector 则很有可能出现崩溃。
    */



    //foreach关键字
    //Qt 会在foreach循环时自动拷贝容器。
    //在遍历时修改集合，对于正在进行的遍历是没有影响的
    QLinkedList<QString> list2;
    list2 << "A" << "B" << "C";
    QString str;
    foreach(str,list2){
        qDebug() << str;
        str = "D";
    }

    foreach(str,list2){
        qDebug() << str;
    }



#endif


    return a.exec();
}
