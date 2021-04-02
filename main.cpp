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

    guy.removeAt(3);
    guy.insert(103,2);


    qDebug()<<guy[0];

    return 0;
}
