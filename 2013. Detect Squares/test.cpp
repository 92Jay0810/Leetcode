class CountSquares {
public:
    // plane_count[x][y] = 這個 (x,y) 點出現了幾次
    unordered_map<int , unordered_map<int,int>> plane_count;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        plane_count[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int result = 0;
        int x1 = point[0];
        int y1 = point[1];
        // 找「同一條垂直線上的點」 x1,y1 和x1,y2
        for(auto &[y2,count] : plane_count[x1]){
            // 決定正方形邊長
            int side = y2 - y1;
            // 找到一樣的點
            if(y2 == y1){
                continue;
            }
            // 利用side 找到可能的其他水平點
            int x3 = x1 + side;
            int x4 = x1 - side;
            // count是x1,y2 出現的次數 再乘上其他點出現次數 x1,y1為查詢點不算
            result += count * plane_count[x3][y1] * plane_count[x3][y2];
            result += count * plane_count[x4][y1] * plane_count[x4][y2];
        }
        return result;
    }
};
