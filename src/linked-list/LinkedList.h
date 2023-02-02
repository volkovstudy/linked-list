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
    void pop();

    void erase(int start, int end);
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

    _tail = beforeTail;
}

template<typename T>
void LinkedList<T>::erase(int start, int end) {
    /* end doesn't be erased */

    if (isEmpty()) return;

    if (start > end) return;

    Node<T>* beforeStartNode = _head;
    Node<T>* endNode = _head;
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
        return;
    }

    beforeStartNode->next = endNode;
    endNode->previous = beforeStartNode;
}

#endif
