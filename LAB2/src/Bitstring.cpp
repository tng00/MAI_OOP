#include "../include/BitString.hpp"

BitString::BitString() : size(1)
{
    data = new unsigned char[size]();
}

BitString::BitString(const size_t &size)
{
    this->size = size;
    data = new unsigned char[size]();
}

BitString::BitString(const BitString &other)
{
    size = other.size;
    data = new unsigned char[size]();
    for (size_t i = 0; i < size; ++i)
    {
        data[i] = other.data[i];
    }
}

BitString::BitString(const std::initializer_list<unsigned char> &t)
{
    size = t.size();
    data = new unsigned char[size]();

    size_t i = 0;
    for (const unsigned char &value : t)
    {
        data[i++] = value;
    }
}

BitString::~BitString()
{
    delete[] data;
}

BitString &BitString::operator=(const BitString &other)
{
    if (this == &other)
    {
        return *this;
    }

    delete[] data;
    size = other.size;
    data = new unsigned char[size]();
    for (size_t i = 0; i < size; ++i)
    {
        data[i] = other.data[i];
    }
    return *this;
}

BitString BitString::operator&(const BitString &other) const
{
    if (size != other.size)
    {
        throw std::invalid_argument("Size of strings must be equal");
    }
    BitString result(size);
    for (size_t i = 0; i < size; ++i)
    {
        result.data[i] = data[i] & other.data[i];
    }
    return result;
}

BitString BitString::operator|(const BitString &other) const
{
    if (size != other.size)
    {
        throw std::invalid_argument("Size of strings must be equal");
    }
    BitString result(size);
    for (size_t i = 0; i < size; ++i)
    {
        result.data[i] = data[i] | other.data[i];
    }
    return result;
}

BitString BitString::operator^(const BitString &other) const
{
    if (size != other.size)
    {
        throw std::invalid_argument("Size of strings must be equal");
    }
    BitString result(size);
    for (size_t i = 0; i < size; ++i)
    {
        result.data[i] = data[i] ^ other.data[i];
    }
    return result;
}

BitString BitString::operator~() const
{
    BitString result(size);
    for (size_t i = 0; i < size; ++i)
    {
        result.data[i] = data[i] ^ 1;
    }
    return result;
}

bool BitString::operator==(const BitString &other) const
{
    if (size != other.size)
    {
        return false;
    }
    for (size_t i = 0; i < size; ++i)
    {
        if (data[i] != other.data[i])
        {
            return false;
        }
    }
    return true;
}

bool BitString::operator!=(const BitString &other) const
{
    return !(*this == other);
}

size_t BitString::getSize() const
{
    return size;
}

size_t BitString::operator[](size_t index) const
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

void BitString::setBit(size_t index, bool value)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    data[index] = value;
}

void BitString::print() const
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << (*this)[i];
    }
    std::cout << std::endl;
}
