class Solution
{
public:
    unordered_map<int, bool> word_map;
    bool wordBreak(string s, vector<string> &wordDict)
    {
        return dfs(s, wordDict, 0);
    }
    bool dfs(string s, vector<string> &wordDict, int i)
    {
        if (i == s.length())
        {
            return true;
        }
        if (word_map.find(i) != word_map.end())
        {
            return word_map[i];
        }
        for (string word : wordDict)
        {
            if (i + word.length() <= s.length() && (s.substr(i, word.length()) == word))
            {
                if (dfs(s, wordDict, i + word.length()))
                {
                    word_map[i] = true;
                    return true;
                }
            }
        }
        word_map[i] = false;
        return false;
    }
};
