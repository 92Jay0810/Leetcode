#include <iostream>
#include <string>
#include <map>
class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        std::map<char, int> Map;
        for (auto &s_member : s)
        {
            if (Map.find(s_member) != Map.end())
            {
                Map[s_member] = Map[s_member] + 1;
            }
            else
            {
                Map[s_member] = 1;
            }
        }
        std::map<char, int> Map2;
        for (auto &t_member : t)
        {
            if (Map2.find(t_member) != Map2.end())
            {
                Map2[t_member] = Map2[t_member] + 1;
            }
            else
            {
                Map2[t_member] = 1;
            }
        }
        for (auto &map_member : Map)
        {
            if (Map[map_member.first] != Map2[map_member.first])
            {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
