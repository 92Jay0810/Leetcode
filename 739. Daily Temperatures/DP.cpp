#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> result(n, 0);
        for (int i = n - 2; i >= 0; i--)
        {
            // 以i為主，往後看
            int j = i + 1;
            // 若j溫度比i小，往下走
            while (j < n && temperatures[j] <= temperatures[i])
            {
                // i溫度比j大, j後面沒有更大的，直接結束
                if (result[j] == 0)
                {
                    j = n;
                    break;
                }
                // 後面有比j大的，可以比比看，跳過去
                j += result[j];
            }
            if (j < n)
            {
                result[i] = j - i;
            }
        }
        return result;
    }
};
