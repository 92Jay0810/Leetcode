class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        // key是sum value是幾種方法
        unordered_map<int, int> dp;
        // 記得做初始化，不然後面沒數值
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> next;
            for (auto &[key, value] : dp)
            {

                next[key + nums[i]] += value;
                next[key - nums[i]] += value;
            }
            dp = move(next);
        }
        return dp[target];
    }
};
