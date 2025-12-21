class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int result = 0;
        int prev_end = intervals[0][1];
        for(int i = 1 ; i < intervals.size(); i++){
            if(prev_end <= intervals[i][0]){
                prev_end = intervals[i][1];
            }else{
                result++;
                prev_end = min(intervals[i][1],prev_end);
            }
        }
        return result;
    }
};
