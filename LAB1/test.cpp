#include "googletest/googlemock/include/gmock/gmock.h"
#include "googletest/googletest/include/gtest/gtest.h"
#include "solution.hpp"

using namespace std;

TEST(CheckReplace, Simple)
{
    string text = "ab ab";
    Solution solution;
    ASSERT_TRUE(solution.replace(text, 2, 'b', 'c') == "ab ac");
}

TEST(CheckReplace, Blankspaces)
{
    string text = "   ";
    Solution solution;
    ASSERT_TRUE(solution.replace(text, 1, ' ', '.') == "...");
}

TEST(CheckReplace, N_0)
{
    string text = "abc";
    Solution solution;
    ASSERT_TRUE(solution.replace(text, 0, 'a', 'b') == "abc");
}

TEST(CheckReplace, AbsentOldValue)
{
    string text = "abc";
    Solution solution;
    ASSERT_TRUE(solution.replace(text, 2, 'd', 'e') == "abc");
}

TEST(CheckReplace, N_3)
{
    string text = "aaabbbccc";
    Solution solution;
    ASSERT_TRUE(solution.replace(text, 3, 'a', 'x') == "aaxbbbccc");
}

TEST(CheckReplace, N_4)
{
    string text = "abcabcabcabc";
    Solution solution;
    ASSERT_TRUE(solution.replace(text, 4, 'a', 'x') == "abcabcabcxbc");
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}