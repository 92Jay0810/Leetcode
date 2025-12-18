#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class TimeMap
{
public:
    unordered_map<string, vector<pair<int, string>>> m;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        m[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        // 過Time Limit Exceeded
        if (m.find(key) == m.end())
            return "";

        // 在key之下，value和timestamp作為pair 用一維array方式來搜尋，預期按照timestamp順序input
        // 以timestamp 為 target 去binary search
        int left = 0;
        int right = m[key].size() - 1;
        // &data 減少資料搬移 過Time Limit Exceeded
        vector<pair<int, string>> &data = m[key];
        string result = "";
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (data[middle].first <= timestamp)
            {
                result = data[middle].second;
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        return result;
    }
};
