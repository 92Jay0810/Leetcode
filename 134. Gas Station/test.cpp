class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int gas_sum = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            gas_sum += gas[i];
        }
        int cost_sum = 0;
        for (int i = 0; i < cost.size(); i++)
        {
            cost_sum += cost[i];
        }
        // 走整條路 花費大於補給一定不能走
        if (gas_sum < cost_sum)
        {
            return -1;
        }
        // 經典的 Greedy 解法（一趟掃描找起點）
        // 從當前起點去累積，若變為負數就捨棄累積，重新歸零，起點訂為i+1
        // 為何正確?  我們保證整個路總油量夠，所以一定存在某個起點能走完全程。
        // 假設目前候選起點是 s，當模擬到站 i 時 current_gas < 0，代表從 s 出發走到 i 時油不夠（局部和從 s 到 i 為負）。
        // 對於任何 k，有 s <= k <= i，若從 k 出發走到 i，你會比從 s 出發到 i 的累積更少或相等（因為從 k 少了 s 到 k-1 的正補償，不然沒辦法走到k），因此也會失敗。
        // 所以所有在 [s, i] 的點都不可能是合法起點，安全地把候選起點移到 i+1。這保證我們不會漏掉可能的起點。
        int current_gas = 0;
        int result = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            current_gas += gas[i] - cost[i];
            if (current_gas < 0)
            {
                current_gas = 0;
                result = i + 1;
            }
        }
        return result % gas.size();
    }
};
