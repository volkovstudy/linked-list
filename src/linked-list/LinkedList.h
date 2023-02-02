#ifndef LINKED_LIST_LINKEDLIST_H
#define LINKED_LIST_LINKEDLIST_H

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

    void pushBack(T data);
};

template<typename T>
bool LinkedList<T>::isEmpty() {
    return _size == 0 && _head == nullptr;
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

#endif
