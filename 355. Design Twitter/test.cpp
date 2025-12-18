#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;
class Twitter
{
    int count;
    unordered_map<int, set<int>> followmap;
    unordered_map<int, vector<vector<int>>> twittemap;

public:
    Twitter()
    {
        count = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        twittemap[userId].push_back({count, tweetId});
        count++;
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> result;
        auto compare = [](const vector<int> &a, const vector<int> &b)
        {
            return a[0] < b[0];
        };
        // 單條twitte是vector<int>、整個queue用的結構是vector<vector<int>> 、比較function用compare
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> min_heap(compare);
        // 把自己加進來，別錯過
        followmap[userId].insert(userId);
        // set存的是const 不能int& 不能獲得可修改的int 怕破壞set
        // 訪問每個followee
        for (int followee : followmap[userId])
        {
            if (twittemap.count(followee))
            {
                vector<vector<int>> &twitte = twittemap[followee];
                // 最新的貼文
                int index = twitte.size() - 1;
                // 做成一個vector<int> push進去
                // 先拿最新貼文  0是count 1是id      2、3方便拿出來之後用
                min_heap.push({twitte[index][0], twitte[index][1], followee, index});
            }
        }
        while (!min_heap.empty() && result.size() < 10)
        {
            vector<int> curr = min_heap.top();
            min_heap.pop();
            result.push_back(curr[1]);
            int index = curr[3];
            // 該followee還有貼文，就再放
            if (index > 0)
            {
                const vector<int> &tweet = twittemap[curr[2]][index - 1];
                min_heap.push({tweet[0], tweet[1], curr[2], index - 1});
            }
        }
        return result;
    }

    void follow(int followerId, int followeeId)
    {
        followmap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        followmap[followerId].erase(followeeId);
    }
};
