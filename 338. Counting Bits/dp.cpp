class Solution {
public:
    // 同樣可以用之前的 1 << i & num num為(1~n) i為0~31 不過需要nlogn
    // num & num-1 同樣nlogn
    // 這邊使用dp 只需要 n
    vector<int> countBits(int n) {
        // 輸入 n=4 要check 0~4
        vector<int> dp(n + 1);
        // offset 作為最高2進制位元 i = 8 offset為8 i=7 offset為4
        int offset = 1 ;
        for(int i = 1 ; i <= n ; i++){
            if(offset * 2 == i){
                offset = i ;
            }
            // offset的bit算進來後 再拿前面算過的 7拿掉4之後 再拿3的結果
            dp[i] = 1 + dp[i - offset];
        }
        return dp;
    }
};
