#include <cassert>
#include <iostream>

#include "linked-list/LinkedList.h"

void shouldReturnTrueWhenListIsEmpty();
void shouldReturnFalseWhenListIsNotEmpty();
void shouldReturnThreeWhenInListThreeItems();

int main() {
    shouldReturnTrueWhenListIsEmpty();
    shouldReturnFalseWhenListIsNotEmpty();

    shouldReturnThreeWhenInListThreeItems();

    return 0;
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
