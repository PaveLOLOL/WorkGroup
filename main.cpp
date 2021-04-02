#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "mylist.h"

using namespace std;

int main()
{
    MyList<int> guy;
    guy.pushBack(3);
    guy.pushBack(7);
    guy.pushFront(10);
    guy.pushFront(15);

    guy.pushBack(-1);

//    guy.removeAt(4);
//    guy.insert(103,2);

//    qDebug()<<guy.at(2);

    return 0;
}
