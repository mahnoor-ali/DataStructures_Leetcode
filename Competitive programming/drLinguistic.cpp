#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

string is_perfect_word(string s)
{
    unordered_map<char, int> freq;
    for (char c : s)
    {
        freq[c]++;
    }

    vector<int> values;
    for (auto p : freq)
    {
        values.push_back(p.second);
    }

    vector<int> unique_values;
    for (int x : values)
    {
        if (unique_values.empty() || count(unique_values.begin(), unique_values.end(), x) == 0)
        {
            unique_values.push_back(x);
        }
    }

    if (unique_values.size() == 1)
    {
        return "YES";
    }
    else if (unique_values.size() == 2)
    {
        int count1 = unique_values[0];
        int count2 = unique_values[1];
        if ((count1 == count2 + 1 || count1 == count2 - 1))
        {
            return "YES";
        }
        else if ((count2 == count1 + 1 || count2 == count1 - 1))
        {
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    string s;
    cin >> s;
    cout << is_perfect_word(s) << endl;
    return 0;
}

// Solution credit: iqra sarwar  https://github.com/iqrasarwar