#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // using Eating rate as search goal
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int result = right;
        while (left <= right)
        {
            int m = (left + right) / 2;
            // 不斷相加可能爆掉
            long totaltime = 0;
            for (int p : piles)
            {
                totaltime += ceil(static_cast<double>(p) / m);
            }
            if (totaltime <= h)
            {
                result = m;
                right = m - 1;
            }
            else
            {
                left = m + 1;
            }
        }
        return result;
    }
};
