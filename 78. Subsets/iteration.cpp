#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    // 特別聰明的做法
    // 一開始有空集合
    //  input nums:{a,b,c}
    // a: reuslt:{{},{a}}
    // b: reuslt:{{},{a},{b},{a,b}}
    // c: reuslt:{{},{a},{b},{a,b},{c},{a,c},{b,c},{a,b,c}}
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result = {{}};
        for (int &num : nums)
        {
            int size = result.size();
            for (int i = 0; i < size; i++)
            {
                vector<int> subnet = result[i];
                subnet.push_back(num);
                result.push_back(subnet);
            }
        }
        return result;
    }
};