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

TEST(GetSize, HandlesListWithThreeItems) {
    LinkedList<int> list = givenListWithItems(std::list<int>{1, 2, 3});

    ASSERT_EQ(list.getSize(), 3);
}

TEST(At, HandlesEmptyList) {
    LinkedList<int> list = givenListWithItems(std::list<int>{});

    try {
        list.at(0);
        FAIL() << "Expected std::invalid_argument but wasn't thrown";
    } catch (invalid_argument& exception) {
        string message = exception.what();
        ASSERT_EQ(message, "Index's out of the range");
    } catch (...) {
        FAIL() << "Expected std::invalid_argument but was thrown other";
    }
}

TEST(At, HandlesListWithItems) {
    LinkedList<int> list = givenListWithItems(std::list<int>{1, 2, 3});

    ASSERT_EQ(list.at(0), 1);
    ASSERT_EQ(list.at(1), 2);
    ASSERT_EQ(list.at(2), 3);
}
