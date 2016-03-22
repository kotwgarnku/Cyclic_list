/**
* @author Filip Konieczny
*/

#include "gtest/gtest.h"

#include "Cyclic_list.h"

class ListFixture : public ::testing::Test {

public:
    ListFixture() : Test() {
        list = new Cyclic_list();
    }

    virtual ~ListFixture() {
        delete list;
    }

    Cyclic_list *list;
};

TEST_F(ListFixture, push_check) {
    list->push(3);
    EXPECT_EQ(1, list->getLength());
    list->push(2);
    EXPECT_EQ(2, list->getLength());
    list->push(1);
    EXPECT_EQ(3, list->getLength());

    EXPECT_EQ(3, list->get(0));
    EXPECT_EQ(2, list->get(1));
    EXPECT_EQ(1, list->get(2));
}

TEST_F(ListFixture, push_2arg_check) {
    list->push(3, 0);
    EXPECT_EQ(1, list->getLength());
    list->push(2, 0);
    EXPECT_EQ(2, list->getLength());
    list->push(1, 1);
    EXPECT_EQ(3, list->getLength());
    list->push(4, 3);
    EXPECT_EQ(4, list->getLength());

    EXPECT_EQ(3, list->get(2));
    EXPECT_EQ(2, list->get(0));
    EXPECT_EQ(1, list->get(1));
    EXPECT_EQ(4, list->get(3));
}

TEST_F(ListFixture, pushAfter_check) {
    list->push(3);
    list->push(2);
    list->push(1);
    list->pushAfter(7, 2);
    EXPECT_EQ(4, list->getLength());
    list->pushAfter(5, 7);
    EXPECT_EQ(5, list->getLength());

    EXPECT_EQ(7, list->get(2));
    EXPECT_EQ(5, list->get(3));
}

TEST_F(ListFixture, find_check) {
    int arr[] = {1, 5, 9, 7, 4, 1, 3, 4, 2};
    for(auto const item : arr)
        list->push(item);

    EXPECT_EQ(0, list->find(1));
    EXPECT_EQ(8, list->find(2));
    EXPECT_EQ(1, list->find(5));
    EXPECT_EQ(-1, list->find(10));
    EXPECT_EQ(-1, list->find(6));
    EXPECT_EQ(-1, list->find(-1));
}

TEST_F(ListFixture, get_check) {
    int arr[] = {1, 5, 9, 7, 4, 1, 3, 4, 2};
    for(auto const item : arr)
        list->push(item);

    EXPECT_EQ(5, list->get(1));
    EXPECT_EQ(1, list->get(0));
    EXPECT_EQ(2, list->get(8));
}

TEST_F(ListFixture, remove_check) {
    int arr[] = {1, 5, 9, 7, 4, 1, 3, 4, 2};
    for(auto const item : arr)
        list->push(item);

    EXPECT_EQ(9, list->getLength());
    list->remove(5);
    EXPECT_EQ(8, list->getLength());
    list->remove(1);
    EXPECT_EQ(6, list->getLength());
    list->remove(2);
    EXPECT_EQ(5, list->getLength());
}

TEST_F(ListFixture, removeRange_check) {
    int arr[] = {1, 5, 9, 7, 4, 1, 3, 4, 2};
    for(auto const item : arr)
        list->push(item);

    EXPECT_EQ(9, list->getLength());
    list->remove(5, 9);
    EXPECT_EQ(-1, list->find(5));
    EXPECT_EQ(-1, list->find(7));
    EXPECT_EQ(-1, list->find(9));
    EXPECT_EQ(6, list->getLength());
    list->remove(1, 3);
    EXPECT_EQ(2, list->getLength());
    EXPECT_EQ(-1, list->find(1));
    EXPECT_EQ(-1, list->find(2));
    EXPECT_EQ(-1, list->find(3));
    list->remove(4, 4);
    EXPECT_EQ(0, list->getLength());
    EXPECT_EQ(-1, list->find(4));
}

TEST_F(ListFixture, removeIndex_check) {
    int arr[] = {1, 5, 9, 7, 4, 1, 3, 4, 2};
    for(auto const item : arr)
        list->push(item);

    EXPECT_EQ(9, list->getLength());
    list->removeIndex(0);
    EXPECT_EQ(8, list->getLength());
    list->removeIndex(7);
    EXPECT_EQ(7, list->getLength());
    EXPECT_EQ(-1, list->find(2));
    list->removeIndex(2);
    EXPECT_EQ(6, list->getLength());
    EXPECT_EQ(-1, list->find(7));
    list->removeIndex(0);
    list->removeIndex(3);
    list->removeIndex(0);
    list->removeIndex(1);
    list->removeIndex(0);
    list->removeIndex(0);
    EXPECT_EQ(0, list->getLength());
}

TEST_F(ListFixture, empty_check) {
    int arr[] = {1, 5, 9, 7, 4, 1, 3, 4, 2};
    for(auto const item : arr)
        list->push(item);
    EXPECT_EQ(9, list->getLength());
    list->empty();
    EXPECT_EQ(0, list->getLength());
    EXPECT_EQ(-1, list->find(1));
    EXPECT_EQ(-1, list->find(2));
    EXPECT_EQ(-1, list->find(4));
}

TEST_F(ListFixture, uniquify_check) {
    int arr[] = {1, 2, 1, 1, 1, 2};
    for(auto const item : arr)
        list->push(item);
    EXPECT_EQ(6, list->getLength());
    list->uniquify();
    EXPECT_EQ(2, list->getLength());
    EXPECT_EQ(1, list->get(0));
    EXPECT_EQ(2, list->get(1));
    list->empty();
    list->push(1);
    list->push(1);
    list->uniquify();
    EXPECT_EQ(1, list->getLength());
}

TEST_F(ListFixture, adding_lists_check) {
    int arr[] = {1, 2, 3, 4, 1, 2};
    for(auto const item : arr)
        list->push(item);
    EXPECT_EQ(6, list->getLength());
    Cyclic_list sList = {5, 6, 7, 8};
    Cyclic_list sum;
    EXPECT_EQ(4, sList.getLength());
    sum = (*list) + sList;
    EXPECT_EQ(10, sum.getLength());
    EXPECT_EQ(1, sum[0]);
    EXPECT_EQ(2, sum[1]);
    EXPECT_EQ(5, sum[6]);
    EXPECT_EQ(8, sum[9]);
}

TEST_F(ListFixture, comparing_lists_check) {
    int arr[] = {1, 2, 3, 4,};
    for(auto const item : arr)
        list->push(item);
    Cyclic_list sList = {1, 2, 3, 4, 5};
    EXPECT_EQ(false, *list == sList);
    sList.remove(5);
    EXPECT_EQ(true, *list == sList);
}
