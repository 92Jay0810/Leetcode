class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            // 兩個bit 為 1 就可以進位 然後left shfit
            int carry = (a & b) << 1;
            // a 為 curr bit 
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
