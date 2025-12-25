class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // reverse : firest row -> last row 、last row -> first row 
        reverse(matrix.begin(),matrix.end());
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = i + 1 ; j < matrix[0].size() ; j++){
                // swap row and column
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};
