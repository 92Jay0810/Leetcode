#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
    // 跟207很像
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        vector<int> result;
        for (vector<int> pre : prerequisites)
        {
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
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
            result.push_back(node);
            for (int precourse : adj[node])
            {
                indegree[precourse]--;
                if (indegree[precourse] == 0)
                {
                    q.push(precourse);
                }
            }
        }
        if (finish != numCourses)
        {
            return {};
        }
        return result;
    }
};
