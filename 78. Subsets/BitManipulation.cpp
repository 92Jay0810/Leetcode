#include <iostream>
#include <vector>
using namespace std;
// 特別聰明的方式
class Solution
{
    // i	    二進位 (i 的表示)	對應子集
    // 0	    000	                {}
    // 1	    001	                {3}
    // 2	    010	                {2}
    // 3	    011	                {2,3}
    // 4	    100	                {1}
    // 5	    101	                {1,3}
    // 6	    110	                {1,2}
    // 7	    111	                {1,2,3}
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> subset;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j)) // 判斷第 j 位是否為 1
                {
                    subset.push_back(nums[j]);
                }
            }
            res.push_back(subset);
        }
        return res;
    }
};