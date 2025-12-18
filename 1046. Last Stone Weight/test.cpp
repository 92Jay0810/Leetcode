#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> max_heap;
        for (int &stone : stones)
        {
            max_heap.push(stone);
        }
        while (max_heap.size() > 1)
        {
            int first = max_heap.top();
            max_heap.pop();
            int second = max_heap.top();
            max_heap.pop();
            if (first > second)
            {
                max_heap.push(first - second);
            }
        }
        // 怕nullptr 做push 0
        max_heap.push(0);
        return max_heap.top();
    }
};
