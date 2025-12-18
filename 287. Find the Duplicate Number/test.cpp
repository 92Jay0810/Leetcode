#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    // 這題很多解法 hashset、array 和以下的Negative Marking(不使用額外空間) 最有趣的在Bit Manipulation
    int findDuplicate(vector<int> &nums)
    {
        for (int num : nums)
        {
            // n個數字 但空間只有0~n-1 因此index要減1
            int idx = abs(num) - 1;
            if (nums[idx] < 0)
            {
                // 若為負數，則此數出現過  不能回傳nums[idx] 這個位置的值不關我們事，只是借用sign bit和index
                return abs(num);
            }
            // 此位置標記用負數標記出現過
            nums[idx] *= -1;
        }
        return -1;
    }
};
