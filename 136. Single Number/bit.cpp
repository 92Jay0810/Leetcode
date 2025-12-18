#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // 所有數字會出現2遍 那xor完變成0 只有出現一次的會是結果
        int result = 0;
        for (int num : nums)
        {
            result = result ^ num;
        }
        return result;
    }
};
