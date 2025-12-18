int dfs(int *nums, int numsSize, int *memo, int i)
{
    if (memo[i] != -1)
    {
        return memo[i];
    }
    int LIS = 1;
    for (int j = i + 1; j < numsSize; j++)
    {
        if (nums[i] < nums[j])
        {
            int temp_LIS = 1 + dfs(nums, numsSize, memo, j);
            LIS = LIS < temp_LIS ? temp_LIS : LIS;
        }
    }
    memo[i] = LIS;
    return LIS;
}
int lengthOfLIS(int *nums, int numsSize)
{
    int memo[numsSize];
    for (int i = 0; i < numsSize; i++)
    {
        memo[i] = -1;
    }
    int LIS = 1;
    for (int i = 0; i < numsSize; i++)
    {
        int temp_LIS = dfs(nums, numsSize, memo, i);
        LIS = LIS < temp_LIS ? temp_LIS : LIS;
    }
    return LIS;
}
