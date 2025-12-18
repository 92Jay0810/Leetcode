class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        vector<bool> target_check(target.size(), false);
        for (auto &triplet : triplets)
        {
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2])
            {
                continue;
            }
            for (int i = 0; i < triplet.size(); i++)
            {
                if (triplet[i] == target[i])
                {
                    target_check[i] = true;
                }
            }
        }
        bool result = true;
        for (int i = 0; i < triplets[0].size(); i++)
        {
            if (target_check[i] != true)
            {
                return false;
            }
        }
        return true;
    }
};
