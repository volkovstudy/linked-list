#ifndef LINKED_LIST_LINKEDLIST_H
#define LINKED_LIST_LINKEDLIST_H

#include <iostream>

template<typename T>
struct Node {
    T value;
    Node* next;
    Node* previous;
};

template<typename T>
class LinkedList {
private:
    Node<T>* _head;
    Node<T>* _tail;

    int _size = 0;
public:
    LinkedList();

    bool isEmpty();
    int getSize();

    T at(unsigned int index);

    void pushBack(T data);
    void pop();

    void erase(int start, int end);
};

#include "LinkedList.tpp"

#endif
