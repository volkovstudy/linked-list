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
    bool isEmpty();
    int getSize();

    T at(unsigned int index);

    void pushBack(T data);
    void pop();

    void erase(int start, int end);
};

template<typename T>
int LinkedList<T>::getSize() {
    return _size;
}

template<typename T>
bool LinkedList<T>::isEmpty() {
    return _size == 0 && _head == nullptr;
}

template<typename T>
T LinkedList<T>::at(unsigned int index) {
    if (index >= _size)
        throw std::invalid_argument("Index's out of the range");

    Node<T>* currentNode = _head;

    for (int i = 0; i < _size; ++i) {
        if (i == index) {
            return currentNode->value;
        }
        currentNode = currentNode->next;
    }

    throw std::invalid_argument("Index isn't valid");
}

template<class T>
void LinkedList<T>::pushBack(T data) {
    bool isEmpty = _head == nullptr;
    if (isEmpty) {
        Node<T>* node = new Node<T>;
        node->value = data;

        _head = node;
        _tail = _head;

        _size = 1;

        return;
    }

    bool hasOnlyOneElement = _head == _tail;
    if (hasOnlyOneElement) {
        Node<T>* node = new Node<T>;
        node->value = data;
        node->previous = _head;

        _head->next = node;
        _tail = node;

        _size++;

        return;
    }

    Node<T>* node = new Node<T>;
    node->value = data;
    node->previous = _tail;

    _tail->next = node;

    _tail = node;

    _size++;
}

template<typename T>
void LinkedList<T>::pop() {
    if (isEmpty()) return;

    if (_size == 1) {
        _head = nullptr;
        _tail = nullptr;

        _size = 0;

        return;
    }

    Node<T>* beforeTail = _tail->previous;
    beforeTail->next = nullptr;

    delete _tail;
    _size--;

    if (_size == 1) {
        _tail = nullptr;
    } else if (_size == 0) {
        _head = nullptr;
        _tail = nullptr;
    } else {
        _tail = beforeTail;
    }
}

template<typename T>
void LinkedList<T>::erase(int start, int end) {
    /* end doesn't be erased */

    if (isEmpty()) return;

    if (start > end) return;

    Node<T>* beforeStartNode = _head;
    Node<T>* endNode = nullptr;
    Node<T>* currentNode = _head;

    int sizeBeforeErasing = _size;
    for (int i = 0; i < sizeBeforeErasing; ++i) {
        if (start == i) {
            beforeStartNode = currentNode->previous;
        }
        if (end == i) {
            endNode = currentNode;
            break;
        }

        if (i >= start) {
            Node<T>* tempNode = currentNode->next;
            delete currentNode;
            _size--;
            currentNode = tempNode;
        } else {
            currentNode = currentNode->next;
        }
    }

    if (beforeStartNode == nullptr) {
        _head = endNode;
        _head->previous = nullptr;
        return;
    }

    beforeStartNode->next = endNode;

    if (endNode != nullptr)
        endNode->previous = beforeStartNode;
    else
        _tail = beforeStartNode;
}

#endif
