class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // 給0 回傳1
        // 也避免後面recursive 遇到empty +1的runtime error
        if(digits.empty()){
            return {1};
        }
        //面試常見題，別轉整數+1 會爆炸
        if(digits.back() != 9){
            digits.back() += 1;
            return digits;
        }else{
            digits.pop_back();
            vector<int> result = plusOne(digits);
            result.push_back(0);
            return result;
        }
    }
};
