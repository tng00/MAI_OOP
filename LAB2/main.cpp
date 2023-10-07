#include <bits/stdc++.h>
#include "src/BitString.cpp"

int main()
{
    BitString bitString1(6);
    BitString bitString2(6);

    bitString1.setBit(1, true);
    bitString1.setBit(4, true);

    bitString2.setBit(2, true);
    bitString2.setBit(4, true);
    bitString2.setBit(5, true);

    std::cout << "bitString1: ";
    bitString1.print();

    std::cout << "bitString2: ";
    bitString2.print();

    BitString resultAnd = bitString1 & bitString2;
    BitString resultOr = bitString1 | bitString2;
    BitString resultXor = bitString1 ^ bitString2;
    BitString resultNot = ~bitString1;

    std::cout << "bitString1 & bitString2: ";
    resultAnd.print();

    std::cout << "bitString1 | bitString2: ";
    resultOr.print();

    std::cout << "bitString1 ^ bitString2: ";
    resultXor.print();

    std::cout << "~bitString1: ";
    resultNot.print();

    if (bitString1 == bitString2)
    {
        std::cout << "bitString1 equals bitString2" << '\n';
    }
    else
    {
        std::cout << "bitString1 not euqals bitString2" << '\n';
    }

    std::cout << "The value of bitString1[2]: " << bitString1[2] << '\n';

}
