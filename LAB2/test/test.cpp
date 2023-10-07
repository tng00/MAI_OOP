#include "../googletest/googletest/include/gtest/gtest.h"
#include "../src/BitString.cpp"

TEST(BitStringTest, ConstructorsAndSize)
{
    BitString bitString1;
    EXPECT_EQ(bitString1.getSize(), 1);

    BitString bitString2(5);
    EXPECT_EQ(bitString2.getSize(), 5);
}

TEST(BitStringTest, BitwiseOperators)
{
    BitString bitString1(5);
    bitString1.setBit(0, true);
    bitString1.setBit(2, true);

    BitString bitString2(5);
    bitString2.setBit(1, true);
    bitString2.setBit(3, true);

    BitString resultAnd = bitString1 & bitString2;
    EXPECT_EQ(resultAnd[0], false);
    EXPECT_EQ(resultAnd[1], false);
    EXPECT_EQ(resultAnd[2], false);
    EXPECT_EQ(resultAnd[3], false);
    EXPECT_EQ(resultAnd[4], false);

    BitString resultOr = bitString1 | bitString2;
    EXPECT_EQ(resultOr[0], true);
    EXPECT_EQ(resultOr[1], true);
    EXPECT_EQ(resultOr[2], true);
    EXPECT_EQ(resultOr[3], true);
    EXPECT_EQ(resultOr[4], false);

    BitString resultXor = bitString1 ^ bitString2;
    EXPECT_EQ(resultXor[0], true);
    EXPECT_EQ(resultXor[1], true);
    EXPECT_EQ(resultXor[2], true);
    EXPECT_EQ(resultXor[3], true);
    EXPECT_EQ(resultXor[4], false);

    BitString resultNot = ~bitString1;
    EXPECT_EQ(resultNot[0], false);
    EXPECT_EQ(resultNot[1], true);
    EXPECT_EQ(resultNot[2], false);
    EXPECT_EQ(resultNot[3], true);
    EXPECT_EQ(resultNot[4], true);
}

TEST(BitStringTest, EqualityOperators)
{
    BitString bitString1(5);
    bitString1.setBit(0, true);
    bitString1.setBit(2, true);

    BitString bitString2(5);
    bitString2.setBit(0, true);
    bitString2.setBit(2, true);

    BitString bitString3(5);
    bitString3.setBit(1, true);
    bitString3.setBit(3, true);

    EXPECT_TRUE(bitString1 == bitString2);
    EXPECT_FALSE(bitString1 == bitString3);

    EXPECT_FALSE(bitString1 != bitString2);
    EXPECT_TRUE(bitString1 != bitString3);
}

TEST(BitStringTest, SetBitAndOperatorIndex)
{
    BitString bitString(5);
    bitString.setBit(0, true);
    bitString.setBit(2, true);

    EXPECT_EQ(bitString[0], true);
    EXPECT_EQ(bitString[1], false);
    EXPECT_EQ(bitString[2], true);
    EXPECT_EQ(bitString[3], false);
    EXPECT_EQ(bitString[4], false);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
