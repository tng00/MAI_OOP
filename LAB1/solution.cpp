#include "solution.hpp"

string Solution::replace(string &text, const int &n, const char &old_value, const char &new_value)
{
    if (n <= 0)
    {
        return text;
    }
    int old_value_cnt = 0;
    for (size_t i = 0; i < text.size(); ++i)
    {
        if (text[i] == old_value)
        {
            ++old_value_cnt;
            if (old_value_cnt % n == 0)
            {
                text[i] = new_value;
            }
        }
    }
    return text;
}