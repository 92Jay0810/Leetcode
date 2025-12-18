#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int result = 0;
        int n = heights.size();
        // vector存放 比自己還小柱子的index 因此從 -1 ~ n
        vector<int> left_most(n, -1);
        vector<int> right_most(n, n);
        stack<int> scan_stack;
        // scan left_most
        for (int i = 0; i < n; i++)
        {
            while (!scan_stack.empty() && heights[scan_stack.top()] >= heights[i])
            {
                // 若比自己大 就pop
                scan_stack.pop();
            }
            // stack 非空，表示有比自己小的，更新stack
            if (!scan_stack.empty())
            {
                left_most[i] = scan_stack.top();
            }
            scan_stack.push(i);
        }
        // 清空
        while (!scan_stack.empty())
        {
            scan_stack.pop();
        }
        // scan right most
        for (int i = n - 1; i >= 0; i--)
        {
            while (!scan_stack.empty() && heights[scan_stack.top()] >= heights[i])
            {
                scan_stack.pop();
            }
            if (!scan_stack.empty())
            {
                right_most[i] = scan_stack.top();
            }
            scan_stack.push(i);
        }
        // 算面積 因為most紀錄比自己矮的柱子 不能算 要位移回來
        for (int i = 0; i < n; i++)
        {
            left_most[i] += 1;
            right_most[i] -= 1;
            result = max(result, heights[i] * (right_most[i] - left_most[i] + 1));
        }
        return result;
    }
};
