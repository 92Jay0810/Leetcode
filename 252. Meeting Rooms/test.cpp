class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(), [](auto& x , auto& y){
            return x.start < y.start;
        });
        if(intervals.empty()) return true;
        int prev_end = intervals[0].end;
        for(int i = 1 ; i < intervals.size() ; i++){
            if(intervals[i].start < prev_end){
                return false;
            }
            prev_end = intervals[i].end;
            /*i 和i-1去比也可以*/
        }
        return true;
    }
};