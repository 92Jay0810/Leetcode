#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> leftmax(n);
        vector<int> rightmax(n);
        leftmax[0] = nums[0];
        rightmax[n - 1] = nums[n - 1];
        for (int i = 1; i < nums.size(); i++)
        {
            // left 以k為區塊的開始 其他的k+1... 作為填充
            if (i % k == 0)
            {
                leftmax[i] = nums[i];
            }
            else
            {
                leftmax[i] = max(leftmax[i - 1], nums[i]);
            }
            if ((n - 1 - i) % k == 0)
            {
                rightmax[n - 1 - i] = nums[n - 1 - i];
            }
            else
            {
                // i一定從1開始，不然這裡error
                // right max 是和後一個比 n-1-i +1 =>n-i
                rightmax[n - 1 - i] = max(rightmax[n - i], nums[n - 1 - i]);
            }
        }
        vector<int> output;
        for (int i = 0; i < n - k + 1; i++)
        {
            // 以k=3,n=10為例 用index來講解
            // index為4時,要找 456看max
            // leftmax會給我 4+3-1=6 因此 num[6]
            // rightmax給我 6 因此 num[4、5、6]
            // index為5時 要看567
            // leftmax 5+3-1=7 => num[6、7]
            // rightmax 5 => num[6、5]
            output.push_back(max(leftmax[i + k - 1], rightmax[i]));
        }
        return output;
    }
};
