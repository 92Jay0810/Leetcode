#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> subnet;
        dfs(result, 0, subnet, nums);
        return result;
    }
    void dfs(vector<vector<int>> &result, int i, vector<int> &subnet, vector<int> &nums)
    {
        // nums:[a,b,c] , i=0 push{a}的 會產生 {a,b,c}、{a,b} (ab都放，c有放和不放)、 {a,c}、{a} (a放，b不放,c放不放)
        //                i=0 不push{a} 會產生 {b,c}、{b} (放b)  ... {c}、{} (不放b)
        // 每個元素有 放自己、不放自己的結果 各自讓過程i遞增，當i都走過就push結果!
        if (i >= nums.size())
        {
            result.push_back(subnet);
            return;
        }
        subnet.push_back(nums[i]);
        dfs(result, i + 1, subnet, nums);
        subnet.pop_back();
        dfs(result, i + 1, subnet, nums);
    }
};
