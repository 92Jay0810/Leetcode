#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        // 若right = middle 不能讓 left<= right 會卡住 因為middle可能算出來等於right
        while (left < right)
        {
            int middle = (left + right) / 2;
            if (nums[middle] > nums[right])
            {
                // middle 大於別人，肯定不是min 不用檢查
                left = middle + 1;
            }
            else
            {
                // middle 小於 right 需要再檢查 是否min
                right = middle;
            }
        }
        // 簡單來說就是用 153. Find Minimum in Rotated Sorted Array的解法
        // 找到pivot 等於min，接著左 右都找一遍
        int pivot = left;
        int result = binarysearch(nums, target, 0, pivot - 1);
        if (result != -1)
        {
            return result;
        }
        return binarysearch(nums, target, pivot, nums.size() - 1);
    }
    int binarysearch(vector<int> &nums, int target, int left, int right)
    {
        if (left > right)
        {
            return -1;
        }
        int middle = (left + right) / 2;
        if (nums[middle] > target)
        {
            return binarysearch(nums, target, left, middle - 1);
        }
        else if (nums[middle] < target)
        {
            return binarysearch(nums, target, middle + 1, right);
        }
        else
        {
            return middle;
        }
    }
};
