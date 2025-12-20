class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        // 因為照順序給
        // 只要new interval開始點 大於interval結束點 就不用處理interval
        while(i < intervals.size() && newInterval[0] > intervals[i][1]){
            result.push_back(intervals[i]);
            i++;
        }
        // 在new interval 開始點小於 interval結束點之下
        // 只要new interval 結束點大於 interval開始點才重疊 做合併(小於 想像new interval放最左邊放)
        // 合併成new interval 跟下個繼續比
        while(i < intervals.size() && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            newInterval[1] = max(newInterval[1],intervals[i][1]);  
            i++;
        } 
        result.push_back(newInterval);
        //剩下的不重疊 直接放            
        while(i < intervals.size()){
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};
