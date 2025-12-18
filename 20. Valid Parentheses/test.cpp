#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> check;
        // 後面才判斷，map來配合stack   ,也可以寫成左符號在key的版本 沒問題 把右符號放key會更直覺
        unordered_map<char, char> dict{
            {']', '['}, {'}', '{'}, {')', '('}};
        for (char c : s)
        {
            if (dict.find(c) != dict.end())
            {
                if (!check.empty() && (dict[c] == check.top()))
                {
                    check.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                check.push(c);
            }
        }
        return check.empty();
    }
};
