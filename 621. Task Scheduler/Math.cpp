#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 這個是數學法 (另個算法 最大task m次，預設大家至少要等(m-1)*(n+1)+1 加上 和最大task相同次數的task)
// 另個算法：(maxf - 1) * (n + 1) + maxCount; ex： xxxxyy n=2;  x _ _ x _ _ x _ _ x 至少x要等10次
// 怎麼看? =>間隔就m-1 *n 再加m =>m可變成m-1+1 於是 (m-1)*(n+1)+1
class Solution
{
public:
    // 此方法填補法，先執行最大task m次，再看中間idle情況
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> count(26, 0);
        for (char &task : tasks)
        {
            count[task - 'A']++;
        }
        sort(count.begin(), count.end());
        // 最大的那個先執行全部m次
        int maxf = count[25];
        // 中間間隔 m-1個
        int idle = (maxf - 1) * n;
        // 去填補idle，其他字元至少填補m-1次， 不然會idle
        for (int i = 24; i >= 0; i--)
        {
            idle -= min(maxf - 1, count[i]);
        }
        // task的數量加上idle回傳
        return max(0, idle) + tasks.size();
    }
};
