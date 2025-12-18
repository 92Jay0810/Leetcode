#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    vector<vector<string>> result;
    // 解題思路，同樣是選或不選的backtrack問題，選擇回文就讓開始點和檢查點往後，不選就讓檢查點往後
    // 每次的開始點和檢查點這一段會去檢查是否為回文
public:
    vector<vector<string>> partition(string s)
    {
        vector<string> part;
        dfs(0, 0, s, part);
        return result;
    }
    void dfs(int partition_start, int check_position, string &s, vector<string> &part)
    {
        // 這裡一開始實作有發現錯 不小心拿partition_start>=s.size() 作條件
        // 簡單來說 若檢查到字串尾巴，就表示check_position 大於等於s.size()
        if (check_position >= s.size())
        {
            // 並且partition_start 到check_position 這一段剛好是回文 那就加入part
            if (partition_start == check_position)
            {
                result.push_back(part);
            }
            return;
        }
        if (isPailndrome(s, partition_start, check_position))
        {
            part.push_back(s.substr(partition_start, check_position - partition_start + 1));
            dfs(check_position + 1, check_position + 1, s, part);
            part.pop_back();
        }
        dfs(partition_start, check_position + 1, s, part);
    }
    bool isPailndrome(string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
