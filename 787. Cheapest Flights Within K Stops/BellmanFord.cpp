#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // 為何需要暫存? 因為每一輪都會修改prices，不能讓同一輪的結果互相影響
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        // 最多轉機K個站，也就是k+1個edge
        for (int i = 0; i <= k; i++)
        {
            vector<int> tempprices = prices;
            for (vector<int> &flight : flights)
            {
                int s = flight[0];
                int d = flight[1];
                int p = flight[2];
                if (prices[s] == INT_MAX)
                {
                    continue;
                }
                // 只要比當下的結果價格低，就取代
                if (prices[s] + p < tempprices[d])
                {
                    tempprices[d] = prices[s] + p;
                }
            }
            prices = tempprices;
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
