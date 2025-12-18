class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }
        int jump_count = 0;
        int max_distance = 0;
        int current_jump_end = 0;
        for (int i = 0; i < n - 1; i++)
        {
            // 每一次都更新最大可跳的距離
            if (i + nums[i] > max_distance)
            {
                max_distance = i + nums[i];
            }
            // 如果已經到達上一次跳的最大距離，就跳
            // 並更新這次的最大距離
            if (i == current_jump_end)
            {
                jump_count++;
                current_jump_end = max_distance;
                if (current_jump_end >= n - 1)
                {
                    return jump_count;
                }
            }
        }
        return jump_count;
    }
};
