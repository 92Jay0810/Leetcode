class Solution {
public:
    int hammingWeight(int n) {
        //把可能是 signed 的 int，轉成 unsigned 32-bit
        uint32_t num = static_cast<uint32_t>(n);
        int count = 0;
        for(int i = 0 ; i < 32 ; i++){
            if((1 << i) & num){
                count++;
            }
        }
        return count;
    }
};