#include <iostream>
#include <vector>
using namespace std;
class treeNode
{
public:
    // 也可以像208題那樣 改成用map<char,nodeTree*>的方式去做trie
    vector<treeNode *> children;
    bool word;
    treeNode() : children(26, nullptr), word(false) {};
};
class WordDictionary
{
    treeNode *root;

public:
    WordDictionary()
    {
        root = new treeNode();
    }

    void addWord(string word)
    {
        treeNode *curr = root;
        for (char c : word)
        {
            if (curr->children[c - 'a'] == nullptr)
            {
                curr->children[c - 'a'] = new treeNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->word = true;
    }

    bool search(string word)
    {
        return dfs(word, 0, root);
    }
    bool dfs(string word, int index, treeNode *root)
    {
        treeNode *curr = root;
        for (int i = index; i < word.size(); i++)
        {
            // 遇到萬用字元，當層可以忽略，但還是要檢查存不存在，以後後面幾層的結果有沒有正確的
            if (word[i] == '.')
            {
                for (treeNode *child : curr->children)
                {
                    // 這裡一定要i+1 不是index加1
                    if (child != nullptr && dfs(word, i + 1, child))
                    {
                        return true;
                    }
                }
                return false;
            }
            else
            {
                if (curr->children[word[i] - 'a'] == nullptr)
                {
                    return false;
                }
                curr = curr->children[word[i] - 'a'];
            }
        }
        return curr->word;
    }
};
