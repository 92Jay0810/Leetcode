class Solution {
public:
    int getSum(int a, int b) {
        int result = 0;
        int carray = 0;
        for(int i = 0 ; i < 32 ; i++){
            int a_bit = (a >> i) & 1;
            int b_bit = (b >> i) & 1;
            int curr_bit = a_bit ^ b_bit ^ carray;
            carray = (a_bit + b_bit + carray) >= 2 ? 1 : 0 ;
            if(curr_bit){
                result |= curr_bit << i;
            } 
        }
        return result;
    }
};
