#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_set<int> set;
        for (int num : nums)
        {
            if (set.count(num))
            {
                set.erase(num);
            }
            else
            {
                set.insert(num);
            }
        }
        return *set.begin();
    }
};
