#include <cassert>
#include <iostream>

#include <list>

#include "linked-list/LinkedList.h"

using namespace std;

void shouldReturnTrueWhenListIsEmpty();
void shouldReturnFalseWhenListIsNotEmpty();
void shouldReturnThreeWhenInListThreeItems();

void shouldReturnValueByIndex();
void shouldThrowExceptionWhenGettingValueWithInvalidIndex();

int main() {
    shouldReturnTrueWhenListIsEmpty();
    shouldReturnFalseWhenListIsNotEmpty();

    shouldReturnThreeWhenInListThreeItems();

    shouldReturnValueByIndex();
    shouldThrowExceptionWhenGettingValueWithInvalidIndex();

    return 0;
}

template<class T>
LinkedList<T>& givenListWithItems(std::list<T> data) {
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
    LinkedList<int> list = givenListWithItems(std::list<int>{1, 2, 3});

    assert(list.isEmpty() == false);
}

void shouldReturnThreeWhenInListThreeItems() {
    LinkedList<int> list = givenListWithItems(std::list<int>{1, 2, 3});

    assert(list.getSize() == 3);
}

void shouldReturnValueByIndex() {
    LinkedList<int> list = givenListWithItems(std::list<int>{1, 2, 3});

    assert(list.at(0) == 1);
    assert(list.at(1) == 2);
    assert(list.at(2) == 3);
}

void shouldThrowExceptionWhenGettingValueWithInvalidIndex() {
    LinkedList<int> list = givenListWithItems(std::list<int>{1, 2, 3});

    try {
        list.at(5);
        assert(true == false); // This line shouldn't be run
    } catch (std::exception& exception) {
        string message = exception.what();
        assert(message == "Index's out of the range");
    }
}
