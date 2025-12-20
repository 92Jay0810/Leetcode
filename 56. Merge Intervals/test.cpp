class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return{{}};
        }
        // 按起點順序去排序
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(int i = 1 ; i < intervals.size() ; i++){
            //用& 可以修改
            vector<int>& last = result.back();
            // 若起始點小於 上個結束點 表示有overlap
            if(intervals[i][0] <= last[1]){
                // 只修改結束點
                last[1] = max(last[1],intervals[i][1]);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};