#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 這個是模擬執行法
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> count(26, 0);
        for (char &task : tasks)
        {
            count[task - 'A']++;
        }
        priority_queue<int> max_heap;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] > 0)
            {
                max_heap.push(count[i]);
            }
        }
        queue<pair<int, int>> waiting_queue;
        int time = 0;
        while (!max_heap.empty() || !waiting_queue.empty())
        {
            time++;
            if (max_heap.empty())
            {
                // 若max_heap為空，加速到冷卻結束
                time = waiting_queue.front().second;
            }
            else
            {
                // max_heap不為空，就拿出來執行，放入冷卻
                int count_task = max_heap.top() - 1;
                max_heap.pop();
                if (count_task > 0)
                {
                    waiting_queue.push({count_task, time + n});
                }
            }
            // 冷卻結束，放入max_heap;
            if (!waiting_queue.empty() && time == waiting_queue.front().second)
            {
                int count_task = waiting_queue.front().first;
                waiting_queue.pop();
                max_heap.push(count_task);
            }
        }
        return time;
    }
};
