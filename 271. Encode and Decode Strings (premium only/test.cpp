#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string encode(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        vector<int> size;
        string result;
        for (string &eachString : strs)
        {
            size.push_back(eachString.size());
        }

        for (int eachSize : size)
        {
            result += to_string(eachSize);
            result += ',';
        }
        result += '#';
        // make key  to "14,23,45,23#realstring...."
        for (string &eachString : strs)
        {
            result += eachString;
        }
        return result;
    }

    vector<string> decode(string s)
    {
        if (s.empty())
            return {};
        int i = 0;
        vector<int> size;
        while (s[i] != '#')
        {
            string tempSize;
            while (s[i] != ',')
            {
                tempSize += s[i];
                i++;
            }
            size.push_back(stoi(tempSize));
            i++;
        }
        i++;
        vector<string> result;
        for (int eachSize : size)
        {
            result.push_back(s.substr(i, eachSize));
            i += eachSize;
        }
        return result;
    }
};
