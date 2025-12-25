class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hash_set;
        while(hash_set.find(n) == hash_set.end()){
            hash_set.insert(n);
            n = sumOfSqure(n);
            if(n == 1){
                return true;
            }
        }
        return false;
    }
    int sumOfSqure(int n){
        int output = 0;
        while(n > 0){
            int digit = n % 10;
            digit = digit * digit;
            output += digit;
            n /= 10;
        }
        return output;
    }
};
