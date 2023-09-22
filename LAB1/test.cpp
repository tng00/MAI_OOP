#include "googletest/googlemock/include/gmock/gmock.h"
#include "googletest/googletest/include/gtest/gtest.h"
#include "solution.hpp"

using namespace std;

TEST(CheckReplace, Subtest_1)
{
    string text = "ab ab";
    ASSERT_TRUE(Solution::replace(text, 2, 'b', 'c') == "ab ac");
}

TEST(CheckReplace, Subtest_2)
{
    string text = "";
    ASSERT_TRUE(Solution::replace(text, 2, 'a', 'b') == "");
}

TEST(CheckReplace, Subtest_3)
{
    string text = "abc";
    ASSERT_TRUE(Solution::replace(text, 0, 'a', 'b') == "abc");
}

TEST(CheckReplace, Subtest_4)
{
    string text = "abc";
    ASSERT_TRUE(Solution::replace(text, 2, 'd', 'e') == "abc");
}

TEST(CheckReplace, Subtest_5)
{
    string text = "abc";
    ASSERT_TRUE(Solution::replace(text, 1, 'a', 'd') == "dbc");
}

TEST(CheckReplace, Subtest_6)
{
    string text = "abcdef";
    ASSERT_FALSE(Solution::replace(text, 2, 'c', 'z') == "abzdef");
}

TEST(CheckReplace, Subtest_7)
{
    string text = "aaabbbccc";
    ASSERT_TRUE(Solution::replace(text, 3, 'a', 'x') == "aaxbbbccc");
}

TEST(CheckReplace, Subtest_8)
{
    string text = "abcabcabcabc";
    ASSERT_TRUE(Solution::replace(text, 4, 'a', 'x') == "abcabcabcxbc");
}

TEST(CheckReplace, Subtest_9)
{
    string text = "abcabcabc";
    ASSERT_TRUE(Solution::replace(text, 5, 'a', 'x') == "abcabcabc");
}

TEST(CheckReplace, Subtest_10)
{
    string text = "abcd";
    ASSERT_TRUE(Solution::replace(text, 2, 'a', 'a') == "abcd");
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}