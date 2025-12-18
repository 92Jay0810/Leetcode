#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        vector<pair<int, int>> car_info;
        vector<double> result;
        for (int i = 0; i < position.size(); i++)
        {
            car_info.push_back({position[i], speed[i]});
        }
        // 把最靠近target的放第一個
        sort(car_info.rbegin(), car_info.rend());
        for (pair<int, int> car : car_info)
        {
            double arrive_time = (double)(target - car.first) / car.second;
            result.push_back(arrive_time);
            // 若後面的車 追得上去前車，則合併為一個車隊 數量減一
            if (result.size() >= 2 && result[result.size() - 2] >= result.back())
            {
                result.pop_back();
            }
        }
        return result.size();
    }
};
