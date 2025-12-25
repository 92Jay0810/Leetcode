class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> row_zero(matrix.size(),false);
        vector<bool> col_zero(matrix[0].size(),false);
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    row_zero[i] = true;
                    col_zero[j] = true;
                }
            }
        }
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size(); j++){
                if(row_zero[i] || col_zero[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
