#include "googletest/googlemock/include/gmock/gmock.h"
#include "googletest/googletest/include/gtest/gtest.h"
#include "solution.cpp"

using namespace std;

TEST(CheckReplace, Simple)
{
    string text = "ab ab";
    ASSERT_TRUE(Solution::replace(text, 2, 'b', 'c') == "ab ac");
}

TEST(CheckReplace, Backspaces)
{
    string text = "   ";
    ASSERT_TRUE(Solution::replace(text, 1, ' ', '.') == "...");
}

TEST(CheckReplace, N_0)
{
    string text = "abc";
    ASSERT_TRUE(Solution::replace(text, 0, 'a', 'b') == "abc");
}

TEST(CheckReplace, AbsentOldValue)
{
    string text = "abc";
    ASSERT_TRUE(Solution::replace(text, 2, 'd', 'e') == "abc");
}

TEST(CheckReplace, N_3)
{
    string text = "aaabbbccc";
    ASSERT_TRUE(Solution::replace(text, 3, 'a', 'x') == "aaxbbbccc");
}

TEST(CheckReplace, N_4)
{
    string text = "abcabcabcabc";
    ASSERT_TRUE(Solution::replace(text, 4, 'a', 'x') == "abcabcabcxbc");
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}