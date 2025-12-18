#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        // 一般的binary search是找到target
        // 這題是在roate過的 sorted array找min
        // 因為 旋轉的特性， 只要right 小於middle 就發現這一段有旋轉!
        // right > middle 這一段沒有旋轉，可以捨棄
        // 但middle可能是最小值，加入比較才去捨棄(習慣會捨去 right=middle-1,left=middle+1 left<=right)
        //  ex : 6 7 0 1 2 3  middle在0 right在3  判斷 right >middle 沒旋轉 捨棄1~3 和0
        // 加入0 比較 right=middle的index -1  剩下 6 7
        int left = 0;
        int right = nums.size() - 1;
        int result = nums[0];
        // 若right = middle 不能讓 left<= right 會卡住 因為middle可能算出來等於right
        // right=middle +1 就可以 left<= right
        while (left <= right)
        {
            if (nums[left] < nums[right])
            {
                result = min(result, nums[left]);
                break;
            }
            int m = (left + right) / 2;
            result = min(result, nums[m]);
            if (nums[m] <= nums[right])
            {
                right = m - 1;
            }
            else
            {
                left = m + 1;
            }
        }
        return result;
    }
};