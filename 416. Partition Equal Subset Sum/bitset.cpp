/*
bitset<10001> dp;
這是一個長度 10001 的位元陣列，索引 i 表示「是否能湊出和 = i」。
為什麼要開到 10001？
因為題目裡 nums[i] 的最大值不會超過 100，陣列長度最多 200，所以總和最大可能是200 * 100 = 20000
這邊偷懶只開到一半 (可能測過測資)
dp[x] = 1 代表：可以用目前考慮的元素湊出總和 x。

一開始：
    dp[0] = 1;
    代表：不用任何數字就能湊出 0。


dp << num：把整個 dp 左移 num 位。 (以b定義來看相當於加法)
如果 dp[x] = 1，代表「能湊出 x」
左移後，dp[x + num] = 1，代表「能湊出 x + num」
|=：把「舊的狀態」跟「加上 num 之後的新狀態」合併

3. 小範例

假設 nums = [1, 5, 11, 5]
總和 = 22 → target = 11

初始：
dp = 000000000001   (只有 dp[0] = 1)
加入 1 (num = 1)：
dp << 1 = 000000000010
dp |= dp << 1 → 000000000011
(現在能湊出 0, 1)
加入 5 (num = 5)：
dp << 5 = 000000110000
dp |= dp << 5 → 000000110011
(現在能湊出 0, 1, 5, 6)
加入 11 (num = 11)：
dp << 11 → (會讓 11, 12, 16, 17 變成 1)
dp |= dp << 11
(現在能湊出 0, 1, 5, 6, 11, 12, 16, 17)
*/
#include <vector>
#include <bitset>
using namespace std;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
        }
        if (sum % 2 != 0)
        {
            return false;
        }
        bitset<10001> bit_dp;
        bit_dp[0] = 1;
        for (auto num : nums)
        {
            bit_dp = bit_dp | bit_dp << num;
        }
        return bit_dp[sum / 2];
    }
};
