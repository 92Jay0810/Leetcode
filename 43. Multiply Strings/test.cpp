class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        vector<int> result (num1.length() + num2.length());
        //先做reverse , 從最後面開始乘
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i = 0 ; i < num1.length() ; i++){
            for(int j = 0 ; j < num2.length() ; j++){
                int digit = (num1[i] - '0') * (num2[j] - '0');
                result[i+j] += digit;
                result[i+j+1] += result[i+j] /10;
                result[i+j] %= 10; 
            }
        }
        //從最後面開始輸出
        stringstream res;
        int k =result.size()-1;
        while(k >=0 && result[k] == 0){
            k--;
        }
        while(k >=0){
            res << result[k];
            k--;
        }
        return res.str();
    }
};
