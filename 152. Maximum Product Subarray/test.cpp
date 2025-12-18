class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int result = nums[0];
        int prefix = 0;
        int suffix = 0;
        for (int i = 0; i < n; i++)
        {
            // 從左到右的乘積，遇到0就重新設為乘1
            prefix = nums[i] * (prefix == 0 ? 1 : prefix);
            // 從右到左的乘積，同上
            // 但prefix和suffix不能設為nums[0] 因n-1-i這項有機會變成num[0] when n=2 i從1開始
            suffix = nums[n - 1 - i] * (suffix == 0 ? 1 : suffix);
            result = max(result, max(prefix, suffix));
        }
        return result;
    }
};