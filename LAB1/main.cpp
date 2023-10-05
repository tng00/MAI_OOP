#include "solution.cpp"

using namespace std;

int main()
{
    string text;
    int n;
    char old_value, new_value;
    getline(cin, text);
    cin >> n >> old_value >> new_value;
    Solution solution;
    cout << solution.replace(text, n, old_value, new_value);
}