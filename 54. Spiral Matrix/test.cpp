class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n =matrix[0].size();
        vector<int> result;
        dfs(m , n , 0 , -1 , 0 , 1 , matrix,result);
        return result;
    }
    // 一開始先增加column、接著增加row，減少column，減少row
    // r、c代表訪問matrix的index
    // dr dc 代表增減量
    // 利用col 作為增減量次數限制
    void dfs(int row , int col , int r , int c , int dr, int dc , vector<vector<int>>& matrix , vector<int>& result){
        if(row == 0 || col == 0){
            return;
        }
        for(int i = 0 ; i < col ; i++){
            r += dr;
            c += dc;
            result.push_back(matrix[r][c]);
        }
        dfs(col,row-1,r,c,dc,-dr,matrix,result);
    }
};
