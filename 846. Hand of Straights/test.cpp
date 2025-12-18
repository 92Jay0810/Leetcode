class Solution
{
public:
    // 就只是sort完 若hash看數量 > 0 就抓連續的數值出來檢查
    // 其他方法有 heap ordermap 也都O(nlogn) 、 hashmap會更快O(n)
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
        {
            return false;
        }
        unordered_map<int, int> hashmap;
        for (auto &single_hand : hand)
        {
            hashmap[single_hand]++;
        }
        sort(hand.begin(), hand.end());
        for (auto &single_hand : hand)
        {
            if (hashmap[single_hand] > 0)
            {
                for (int i = 0; i < groupSize; i++)
                {
                    if (hashmap[single_hand + i] == 0)
                    {
                        return false;
                    }
                    hashmap[single_hand + i]--;
                }
            }
        }
        return true;
    }
};
