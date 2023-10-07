#pragma once
#include <iostream>
#include <stdexcept>

class BitString
{
private:
    unsigned char *data;
    size_t size;

public:
    BitString();
    BitString(size_t size);
    BitString(const BitString &other);
    ~BitString();

    BitString &operator=(const BitString &other);
    BitString operator&(const BitString &other) const;
    BitString operator|(const BitString &other) const;
    BitString operator^(const BitString &other) const;
    BitString operator~() const;

    bool operator==(const BitString &other) const;
    bool operator!=(const BitString &other) const;
    
    size_t getSize() const;
    size_t operator[](size_t index) const;
    void setBit(size_t index, bool value);
    void print() const;
};
