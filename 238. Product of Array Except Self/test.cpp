#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int zeroCount = 0;
        int product = 1;
        for (int &num : nums)
        {
            num != 0 ? product *num : zeroCount++;
        }
        // 若zero 超過2個，必定全部為0
        if (zeroCount > 1)
        {
            return vector<int>(nums.size(), 0);
        }
        vector<int> result;
        for (int &num : nums)
        {
            if (num == 0)
            {
                result.push_back(product);
            }
            else
            {
                if (zeroCount > 0)
                {
                    // 非0，但其他數字有0
                    result.push_back(0);
                }
                else
                {
                    // 非0，其他數字也非0
                    result.push_back(product / num);
                }
            }
        }
        return result;
    }
};
