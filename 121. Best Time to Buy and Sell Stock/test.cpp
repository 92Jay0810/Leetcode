#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int result = 0;
        int Minbuy = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            result = max(result, prices[i] - Minbuy);
            Minbuy = min(prices[i], Minbuy);
        }
        return result;
    }
};
