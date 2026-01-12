class Solution {
public:
    int reverse(int x) {
        int result = 0 ;
        while(x != 0){
            int digit = x % 10;
            x /= 10;
            //因為等等要乘10 先檢查 *10 是否會overflow
            if(result > INT_MAX /10 || result < INT_MIN / 10){
                return 0;
            }
            // 確認 *10 加上digit 會不會爆 digit > 7 一定爆
            // INT_MAX = 2147483647
            if(result == INT_MAX /10 && digit > 7){
                return 0;
            }
            // INT_MIN = -2147483648
            if (result == INT_MIN / 10 && digit < -8){
                return 0;  
            }
            result = result * 10 + digit;
            
        }
        return result;
    }
};
