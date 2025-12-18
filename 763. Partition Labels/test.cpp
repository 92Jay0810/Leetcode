class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i++)
        {
            // 算每個char最後出現位置
            map[s[i]] = i;
        }
        vector<int> result;
        int size = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            size++;
            // end 代表這段要切開的最後位置
            end = max(end, map[s[i]]);
            // 到達了就切開
            if (i == end)
            {
                result.push_back(size);
                end = 0;
                size = 0;
            }
        }
        return result;
    }
};
