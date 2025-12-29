class Solution {
public:
    int hammingWeight(int n) {
        uint32_t num = static_cast<uint32_t>(n);
        int count = 0;
        for(int i = 0 ; i < 32 ; i++){
            if((1 << i) & n){
                count++;
            }
        }
        return count;
    }
};