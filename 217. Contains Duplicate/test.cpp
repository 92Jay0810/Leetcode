#include <iostream>
#include <vector>
#include <set>
class Solution
{
public:
    bool hasDuplicate(std::vector<int> &nums)
    {
        std::set<int> hashset;
        for (auto &num : nums)
        {
            if (hashset.find(num) != hashset.end())
            {
                return true;
            }
            hashset.insert(num);
        }
        return false;
    }
};

int main()
{
    std::cout << "hello world" << std::endl;
    return 0;
}