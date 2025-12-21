class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // 按照時間順序處理會議：先開始的會議先處理 當一個新會議要開始時，看看之前的會議有沒有已經結束
        sort(intervals.begin(),intervals.end(),[](auto& x , auto& y){
            return x.start < y.start;
        });
        // 用一個 min-heap 記錄「目前正在使用的會議室中，最早結束的會議時間」
        priority_queue<int,vector<int>,greater<int>> minHeap;
        //cminHeap 裡面存的是什麼？  每個正在進行的會議的 end time
        for(auto& interval : intervals){
            // top() = 最早結束的那個會議
            if(!minHeap.empty() && interval.start >= minHeap.top()){
                // 可以用舊的會議室
                minHeap.pop();
            }
            // 安排會議室
            minHeap.push(interval.end);
        }
        return minHeap.size();
    }
};