#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> result;
        for (string c : tokens)
        {

            if (c == "+")
            {
                int a = result.top();
                result.pop();
                int b = result.top();
                result.pop();
                result.push(a + b);
            }
            else if (c == "-")
            {
                int a = result.top();
                result.pop();
                int b = result.top();
                result.pop();
                result.push(b - a);
            }
            else if (c == "*")
            {
                int a = result.top();
                result.pop();
                int b = result.top();
                result.pop();
                result.push(a * b);
            }
            else if (c == "/")
            {
                int a = result.top();
                result.pop();
                int b = result.top();
                result.pop();
                result.push(b / a);
            }
            else
            {
                result.push(stoi(c));
            }
        }
        return result.top();
    }
};
