#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> output;
        int n = nums.size();
        for (int i = 0; i < n - k + 1; i++)
        {
            int maxNum = nums[i];
            for (int j = i; j < i + k; j++)
            {
                maxNum = max(maxNum, nums[j]);
            }
            output.push_back(maxNum);
        }
        return output;
    }
};
