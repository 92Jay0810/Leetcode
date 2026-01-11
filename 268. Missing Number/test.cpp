class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 用xor 重複兩次的為0 
        // 先初始化result為 n  因為for loop 只能看 0 ~ n-1
        int n = nums.size();
        int result = n;
        for(int i = 0 ; i < n ; i++){
            result ^= i ^ nums[i];
        }
        return result;
    }
};
