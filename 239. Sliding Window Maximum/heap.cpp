#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> output;
        priority_queue<pair<int, int>> heap;
        // 全部丟到heap，在檢查top的index就好!
        for (int i = 0; i < nums.size(); i++)
        {
            heap.push({nums[i], i});
            // 代表windows形成，因為i從0開始算
            if (i >= k - 1)
            {
                // 若heap的上層元素的index 小於這個windows的開頭，表示不重要
                while (heap.top().second <= i - k)
                {
                    heap.pop();
                }
                output.push_back(heap.top().first);
            }
        }
        return output;
    }
};
