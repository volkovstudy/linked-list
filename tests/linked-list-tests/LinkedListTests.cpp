#include <cassert>
#include <iostream>

#include <vector>
#include <list>

#include "linked-list/LinkedList.h"

void shouldReturnTrueWhenListIsEmpty();
void shouldReturnFalseWhenListIsNotEmpty();
void shouldReturnThreeWhenInListThreeItems();

void shouldReturnValueByIndex();

int main() {
    shouldReturnTrueWhenListIsEmpty();
    shouldReturnFalseWhenListIsNotEmpty();

    shouldReturnThreeWhenInListThreeItems();

    shouldReturnValueByIndex();

    return 0;
}

template<class T>
LinkedList<T>& givenListWithThreeItems(std::list<T> data) {
    LinkedList<T>* list = new LinkedList<T>;

    for (const T value: data) {
        list->pushBack(value);
    }

    return *list;
}

void shouldReturnTrueWhenListIsEmpty() {
    LinkedList<int> list;

    assert(list.isEmpty());
}

void shouldReturnFalseWhenListIsNotEmpty() {
    LinkedList<int> list;

    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    assert(list.isEmpty() == false);
}

void shouldReturnThreeWhenInListThreeItems() {
    LinkedList<int> list;

    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    assert(list.getSize() == 3);
}

void shouldReturnValueByIndex() {
    LinkedList<int> list = givenListWithThreeItems(std::list<int>{1, 2, 3});

    assert(list.at(0) == 1);
    assert(list.at(1) == 2);
    assert(list.at(2) == 3);
}
