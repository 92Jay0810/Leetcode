#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
        {
            return false;
        }
        vector<int> s1_count(26, 0);
        vector<int> s2_count(26, 0);
        // 先算windows內的數量 s1.size() 為windwos大小
        for (int i = 0; i < s1.size(); i++)
        {
            s1_count[s1[i] - 'a']++;
            s2_count[s2[i] - 'a']++;
        }
        int match = 0;
        for (int i = 0; i < 26; i++)
        {
            if (s1_count[i] == s2_count[i])
            {
                match++;
            }
        }
        int left = 0;
        // scan s2 using sliding winodws pointer left and right, windows size s1.size()
        for (int right = s1.size(); right < s2.size(); right++)
        {
            if (match == 26)
            {
                return true;
            }
            // right pointer ，加入進來，一樣就match++ 若s2的數量大於s1 就match--
            int right_index = s2[right] - 'a';
            s2_count[right_index]++;
            if (s1_count[right_index] == s2_count[right_index])
            {
                match++;
            }
            else if (s1_count[right_index] + 1 == s2_count[right_index])
            {
                match--;
            }
            // left pointer，移出winodws，一樣就match，若s2少於s1就match--
            int left_index = s2[left] - 'a';
            s2_count[left_index]--;
            if (s1_count[left_index] == s2_count[left_index])
            {
                match++;
            }
            else if (s1_count[left_index] - 1 == s2_count[left_index])
            {
                match--;
            }
            left++;
        }
        return match == 26;
    }
};
