#include <vector>
#include <queue>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Topological Sort
        vector<int> indegree(numCourses, 0);
        // 紀錄連線關係，當選定完點，要將該點的indegree刪掉
        vector<vector<int>> precourse(numCourses);
        for (vector<int> pre : prerequisites)
        {
            indegree[pre[1]]++;
            precourse[pre[0]].push_back(pre[1]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int finish = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            finish++;
            for (int course : precourse[node])
            {
                indegree[course]--;
                if (indegree[course] == 0)
                {
                    q.push(course);
                }
            }
        }
        return finish == numCourses;
    }
};
