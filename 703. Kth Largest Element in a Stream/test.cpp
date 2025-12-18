#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> heap;
    int k = 0;
    // 第幾大 就在 min heap 放幾個就好 拿root
public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (int &num : nums)
        {
            heap.push(num);
            if (heap.size() > k)
            {
                heap.pop();
            }
        }
    }

    int add(int val)
    {
        heap.push(val);
        if (heap.size() > k)
        {
            heap.pop();
        }
        return heap.top();
    }
};
