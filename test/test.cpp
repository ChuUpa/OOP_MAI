#include <gtest/gtest.h>
#include "../include/fixed_block_mem_resource.h"
#include "../include/twoway_linked_list.h"
#include <string>

struct ComplexType {
    int id;
    double value;
    std::string name;

    ComplexType(int id, double value, const std::string& name)
        : id(id), value(value), name(name) {}
};


TEST(PmrDoublyLinkedListTest, IntPushBack) {
    FixedBlockMemoryResource mr(1024, sizeof(int) * 4);
    PmrDoublyLinkedList<int> list(&mr);

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    auto it = list.begin();
    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(*it, 20);
    ++it;
    EXPECT_EQ(*it, 30);
    ++it;
    EXPECT_EQ(it, list.end());
}

TEST(PmrDoublyLinkedListTest, IteratorTraversal) {
    FixedBlockMemoryResource mr(1024, sizeof(int) * 4);
    PmrDoublyLinkedList<int> list(&mr);

    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }

    int expected = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        EXPECT_EQ(*it, expected);
        ++expected;
    }
}

TEST(PmrDoublyLinkedListTest, Clear) {
    FixedBlockMemoryResource mr(1024, sizeof(int) * 4);
    PmrDoublyLinkedList<int> list(&mr);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.clear();
    EXPECT_EQ(list.get_size(), 0);
    EXPECT_EQ(list.begin(), list.end());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
