#include <cassert>
#include <iostream>

#include "linked-list/LinkedList.h"

void shouldReturnFalseWhenListIsNotEmpty();

int main() {
    shouldReturnFalseWhenListIsNotEmpty();

    return 0;
}

void shouldReturnFalseWhenListIsNotEmpty() {
    LinkedList<int> list;

    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    assert(list.isEmpty() == false);
}
