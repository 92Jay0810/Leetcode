int maxSubArray(int *nums, int numsSize)
{
    if (numsSize == 0)
    {
        return 0;
    }
    int *dp = (int *)calloc(numsSize, sizeof(int));
    dp[0] = nums[0];
    int max = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        dp[i] = nums[i] > nums[i] + dp[i - 1] ? nums[i] : nums[i] + dp[i - 1];
        max = dp[i] > max ? dp[i] : max;
    }
    return max;
}