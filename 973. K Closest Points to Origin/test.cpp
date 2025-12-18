#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    // 拿出來的時候 拿出最遠的，因此用max heap
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, pair<int, int>>> max_heap;
        for (vector<int> point : points)
        {
            int des = point[0] * point[0] + point[1] * point[1];
            max_heap.push({des, {point[0], point[1]}});
            if (max_heap.size() > k)
            {
                max_heap.pop();
            }
        }
        vector<vector<int>> result;
        while (!max_heap.empty())
        {
            result.push_back({max_heap.top().second.first, max_heap.top().second.second});
            max_heap.pop();
        }
        return result;
    }
};
