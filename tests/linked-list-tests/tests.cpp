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

TEST(IsEmpty, HandlesEmptyList) {
    LinkedList<int> list = givenListWithItems(std::list<int>{});

    ASSERT_TRUE(list.isEmpty());
}

TEST(IsEmpty, HandlesNotEmptyList) {
    LinkedList<int> list = givenListWithItems(std::list<int>{1, 2, 3});

    ASSERT_FALSE(list.isEmpty());
}

TEST(GetSize, HandlesEmptyList) {
    LinkedList<int> list = givenListWithItems(std::list<int>{});

    ASSERT_EQ(list.getSize(), 0);
}
