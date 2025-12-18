#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int leftmax = height[left];
        int rightmax = height[right];
        int result = 0;
        while (left < right)
        {
            // 一定要由比較小的一邊的Max過來，否則會多算
            if (leftmax < rightmax)
            {
                left++;
                leftmax = max(height[left], leftmax);
                result += leftmax - height[left];
            }
            else
            {
                right--;
                rightmax = max(height[right], rightmax);
                result += rightmax - height[right];
            }
        }
        return result;
    }
};
