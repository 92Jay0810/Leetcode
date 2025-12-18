#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> result(temperatures.size(), 0);
        stack<pair<int, int>> compare_stack;
        for (int i = 0; i < temperatures.size(); i++)
        {
            int temp = temperatures[i];
            // 若現在的這個值比前面的大，把前面的pop出來修改，丟進去result
            while (!compare_stack.empty() && temp > compare_stack.top().first)
            {
                pair<int, int> previous_pair = compare_stack.top();
                compare_stack.pop();
                result[previous_pair.second] = i - previous_pair.second;
            }
            compare_stack.push({temp, i});
        }
        return result;
    }
};
