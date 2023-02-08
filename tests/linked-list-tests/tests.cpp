#include "gtest/gtest.h"

#include <list>

#include "linked-list/LinkedList.h"

using namespace std;

template<class T>
LinkedList<T>& givenListWithItems(list<T> data) {
    LinkedList<T>* list = new LinkedList<T>{};

    for (const T value: data) {
        list->pushBack(value);
    }

    return *list;
}
