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

void shouldDecrementSizeAndRemoveElementWhenPoppingItem();

void shouldEraseMiddleOfList();

int main() {
    shouldReturnTrueWhenListIsEmpty();
    shouldReturnFalseWhenListIsNotEmpty();

    shouldReturnThreeWhenInListThreeItems();

    shouldReturnValueByIndex();
    shouldThrowExceptionWhenGettingValueWithInvalidIndex();

    shouldDecrementSizeAndRemoveElementWhenPoppingItem();

    shouldEraseMiddleOfList();

    return 0;
}

template<class T>
LinkedList<T>& givenListWithItems(std::list<T> data) {
    LinkedList<T>* list = new LinkedList<T>{};

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

template<class T>
void checkWithList(LinkedList<T>& list) {
    int sizeBeforePopping = list.getSize();

    list.pop();

    assert(list.getSize() == sizeBeforePopping - 1);

    try {
        int indexOfDeletedItem = sizeBeforePopping - 1; // -1 because size's starting from 1, not 0
        list.at(indexOfDeletedItem);
        assert(true == false); // This line shouldn't be run
    } catch (std::invalid_argument& exception) {
        string message = exception.what();
        assert(message == "Index's out of the range");
    }
}

void shouldDecrementSizeAndRemoveElementWhenPoppingItem() {
    checkWithList(givenListWithItems(std::list<int>{1}));
    checkWithList(givenListWithItems(std::list<int>{1, 2}));
    checkWithList(givenListWithItems(std::list<int>{1, 2, 3}));
    checkWithList(givenListWithItems(std::list<int>{1, 2, 3, 4}));
}

void shouldEraseMiddleOfList() {
    LinkedList<int> list = givenListWithItems(std::list<int>{1, 2, 3, 4});

    list.erase(1, 3);

    assert(list.getSize() == 2);
    assert(list.at(0) == 1);
    assert(list.at(1 == 4));
}
