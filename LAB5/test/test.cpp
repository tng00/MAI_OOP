#include "../googletest/googletest/include/gtest/gtest.h"
#include "../src/custom_list.cpp"

TEST(CustomListTest, DefaultConstructor) {
    CustomList<int> list;
    ASSERT_TRUE(list.empty());
    ASSERT_EQ(list.size(), 0);
}


TEST(CustomListTest, CopyConstructor) {
    CustomList<int> original;
    original.push_back(1);
    original.push_back(2);

    CustomList<int> copy(original);
    ASSERT_EQ(original, copy);
}

TEST(CustomListTest, CopyAssignment) {
    CustomList<int> original;
    original.push_back(1);
    original.push_back(2);

    CustomList<int> copy;
    copy = original;
    ASSERT_EQ(original, copy);
}

TEST(CustomListTest, MoveConstructor) {
    CustomList<int> original;
    original.push_back(1);
    original.push_back(2);

    CustomList<int> moved(std::move(original));
    ASSERT_TRUE(original.empty());
    ASSERT_EQ(moved.size(), 2);
}

TEST(CustomListTest, MoveAssignment) {
    CustomList<int> original;
    original.push_back(1);
    original.push_back(2);

    CustomList<int> moved;
    moved = std::move(original);
    ASSERT_TRUE(original.empty());
    ASSERT_EQ(moved.size(), 2);
}

TEST(CustomListTest, InitializerListConstructor) {
    CustomList<int> list = {1, 2, 3};
    ASSERT_EQ(list.size(), 3);
    ASSERT_EQ(list.front(), 1);
    ASSERT_EQ(list.back(), 3);
}

TEST(CustomListTest, FrontAndBack) {
    CustomList<int> list;
    list.push_back(1);
    list.push_back(2);

    ASSERT_EQ(list.front(), 1);
    ASSERT_EQ(list.back(), 2);

    const CustomList<int> constList = {3, 4};
    ASSERT_EQ(constList.front(), 3);
    ASSERT_EQ(constList.back(), 4);
}

TEST(CustomListTest, BeginEnd) {
    CustomList<int> list = {1, 2, 3};

    auto it = list.begin();
    ASSERT_EQ(*it, 1);

    ++it;
    ASSERT_EQ(*it, 2);

    ++it;
    ++it;
    ASSERT_EQ(it, list.end());

    const CustomList<int> constList = {4, 5, 6};
    auto constIt = constList.begin();
    ASSERT_EQ(*constIt, 4);

    constIt++;
    ASSERT_EQ(*constIt, 5);

    constIt++;
    constIt++;
    ASSERT_EQ(constIt, constList.end());
}

TEST(CustomListTest, EmptyAndSize) {
    CustomList<int> list;
    ASSERT_TRUE(list.empty());
    ASSERT_EQ(list.size(), 0);

    list.push_back(1);
    ASSERT_FALSE(list.empty());
    ASSERT_EQ(list.size(), 1);

    const CustomList<int> constList = {2, 3, 4};
    ASSERT_FALSE(constList.empty());
    ASSERT_EQ(constList.size(), 3);
}

TEST(CustomListTest, Clear) {
    CustomList<int> list = {1, 2, 3};
    ASSERT_FALSE(list.empty());

    list.clear();
    ASSERT_TRUE(list.empty());
    ASSERT_EQ(list.size(), 0);
}

TEST(CustomListTest, InsertAndErase) {
    CustomList<int> list = {1, 2, 3};
    auto i = list.begin();
    ++i;
    auto it = list.insert(i, 4);

    ASSERT_EQ(list.size(), 4);
    ASSERT_EQ(*it, 4);

    i = list.begin();
    ++i;
    ++i;
    it = list.erase(i);
    ASSERT_EQ(list.size(), 3);
    ASSERT_EQ(*it, 3);
}

TEST(CustomListTest, PushBackAndPopBack) {
    CustomList<int> list;
    list.push_back(1);
    list.push_back(2);

    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(list.back(), 2);

    list.pop_back();
    ASSERT_EQ(list.size(), 1);
    ASSERT_EQ(list.back(), 1);

    list.pop_back();
    ASSERT_TRUE(list.empty());
    ASSERT_EQ(list.size(), 0);
}

TEST(CustomListTest, PushFrontAndPopFront) {
    CustomList<int> list;
    list.push_front(1);
    list.push_front(2);

    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(list.front(), 2);

    list.pop_front();
    ASSERT_EQ(list.size(), 1);
    ASSERT_EQ(list.front(), 1);

    list.pop_front();
    ASSERT_TRUE(list.empty());
    ASSERT_EQ(list.size(), 0);
}

TEST(CustomListTest, Resize) {
    CustomList<int> list = {1, 2, 3};
    list.resize(5);

    ASSERT_EQ(list.size(), 5);
    ASSERT_EQ(list.back(), 0);

    list.resize(2);
    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(list.back(), 2);
}

TEST(CustomListTest, Equality) {
    CustomList<int> list1 = {1, 2, 3};
    CustomList<int> list2 = {1, 2, 3};
    CustomList<int> list3 = {4, 5, 6};

    ASSERT_TRUE(list1 == list2);
    ASSERT_FALSE(list1 == list3);
    ASSERT_TRUE(list1 != list3);
    ASSERT_FALSE(list1 != list2);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
