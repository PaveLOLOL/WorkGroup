#ifndef MYLIST_H
#define MYLIST_H
#include <cstddef>
#include <QDebug>
#include <stdexcept>

template<typename T>
class MyList {
public:
    MyList() {}

    void pushBack(T value);
    void pushFront(T value);
    T getFront();
    T popFront();
    T getBack();
    T popBack();
    T at(int index);
    T removeAt(int index);
    void insert(T value, int index); // Реализовать
    T operator[](int index);

    class Node {
    public:
        Node(T value) {
            this->value = value;
        }

        T value;
        Node* nextNode = nullptr;
    };

    int count = 0;
    Node* firstNode = nullptr;
    Node* getLastNode();
};

template<class T>
void MyList<T>::pushBack(T value) {

    if (value <0) {
        throw std::invalid_argument("Введено неверное значение индекса");
    }

    Node* node = new Node(value);
    if (this->firstNode == nullptr) {
        this->firstNode = node;
    } else {
        Node* cur = this->getLastNode();
        cur->nextNode = node;
    }
    this->count++;
}

template<class T>
void MyList<T>::pushFront(T value) {

    if (value <0) {
        throw std::out_of_range("Введено неверное значение индекса");
    }

    Node* node = new Node(value);
    Node* tmp = this->firstNode;
    this->firstNode = node;
    this->firstNode->nextNode = tmp;
    count++;
}

template<class T>
T MyList<T>::getFront() {
    if (this->firstNode) {
        return firstNode->value;
    } else {
        throw std::out_of_range("Отсутствуют элементы в списке");
    }
}

template<class T>
T MyList<T>::popFront(){
    int value = this->getFront();
    if (value) {
        Node* tmp = this->firstNode;
        this->firstNode = this->firstNode->nextNode;
        delete tmp;
        count--;
        return value;
    } else {
        throw std::out_of_range("Удаляемый элемент по заданному значению отсутствует");
    }
}

template<typename T>
T MyList<T>::getBack() {
    return this->firstNode ? this->getLastNode()->value : throw std::out_of_range("Отсутствуют элементы в списке");
}

template<typename T>
T MyList<T>::popBack() {
    Node* lastNode = this->getLastNode();
    if (lastNode) {
        int tmpValue = lastNode->value;
        delete lastNode;
        count--;
        return tmpValue;
    } else {
        throw std::out_of_range("Удаляемый элемент по заданному значению отсутствует");
    }
}

template<typename T>
T MyList<T>::at(int index) {
    if (!this->firstNode) {
        throw std::invalid_argument("Введено неверное значение индекса");
    }
    if (index > count - 1) {
        throw std::out_of_range("Индекс первысил допустимое значение");
    }
    int counter = 0;
    Node* cur = this->firstNode;
    while (cur != nullptr) {
        if (counter == index) {
            return cur->value;
        }
        cur = cur->nextNode;
        counter++;
    }
    throw std::out_of_range("Введено неверное значение индекса");
}

template<typename T>
T MyList<T>::operator[](int index){
    return this->at(index);
}

template<class T>
T MyList<T>::removeAt(int index){
    if (!this->firstNode || index > count - 1) {
        throw std::out_of_range("Введено неверное значение индекса");
    }
//    if (index > count-1) {
//        qDebug() <<"Ошибка";
//            return;
//    }

    if (index == 0) {
//        this->firstNode = this->firstNode->nextNode;
//        int tmpValue = cur->value;
//        delete cur;
//        return tmpValue;
        return this->popFront();
    }

    int curIndex = 0;
    Node* cur = this->firstNode;
    Node* prev = this->firstNode;
    while (curIndex != index) {
        prev = cur;
        cur = cur->nextNode;
        curIndex++;
        }
    prev->nextNode =cur->nextNode;
    int tmpValue = cur->value;
    delete cur;
    return tmpValue;
}

template<class T>
void MyList<T>::insert(T value, int index){
    if (!this->firstNode || index > this->count + 1) {
        return;
    }

    if (index == 0) {
//        Node* insertNode = new Node(value);
//        Node* tmp = this->firstNode;
//        this->firstNode = insertNode;
//        this->firstNode->nextNode = tmp;
//        this->count++;
//        return;
        this->pushFront(value);
        return;
    } else if (index == this->count) {
        this->pushBack(value);
        return;
    }

    int curIndex = 0;
    Node* cur = this->firstNode;
    while (curIndex != index-1) {
        cur = cur->nextNode;
        curIndex++;
    }
    Node* newNode = new Node(value);
    newNode->nextNode = cur->nextNode;
    cur->nextNode = newNode;
    this->count++;
    return;
}

template<class T>
typename MyList<T>::Node* MyList<T>::getLastNode() {
    Node* cur = this->firstNode;
    while (cur->nextNode != nullptr) {
        cur = cur->nextNode;
    }
    return cur;
}


#endif // MYLIST_H
