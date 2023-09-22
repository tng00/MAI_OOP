#include "solution.cpp"

int main()
{
    string text;
    int n;
    char old_value, new_value;
    getline(cin, text);
    cin >> n >> old_value >> new_value;
    cout << Solution::replace(text, n, old_value, new_value);
}