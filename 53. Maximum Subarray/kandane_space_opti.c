int maxSubArray(int *nums, int numsSize)
{
    if (numsSize == 0)
    {
        return 0;
    }
    int currsum = 0;
    int max = nums[0];
    // 這邊要從0 開始 ，currsum 也要吃到 雖然你也可以另為currsum = nums[0] 這樣可以i=1
    for (int i = 0; i < numsSize; i++)
    {
        // 要嘛自己開始一段新的 subarray,要嘛繼續累加之前的 subarray
        currsum = currsum + nums[i] > nums[i] ? currsum + nums[i] : nums[i];
        max = currsum > max ? currsum : max;
    }
    return max;
}