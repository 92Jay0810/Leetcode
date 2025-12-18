#include <stack>
using namespace std;
class MinStack
{
private:
    stack<long> minstack;
    long min;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (minstack.empty())
        {
            min = val;
            // 最特別的地方
            minstack.push(0);
        }
        else
        {
            // 若為負的 代表他是min
            minstack.push(val - min);
            if (min > val)
            {
                min = val;
            }
        }
    }

    void pop()
    {
        if (minstack.empty())
        {
            return;
        }
        if (minstack.top() < 0)
        {
            min = min - minstack.top();
            minstack.pop();
        }
        else
        {
            minstack.pop();
        }
    }

    int top()
    {
        return minstack.top() > 0 ? minstack.top() + min : (int)min;
    }

    int getMin()
    {
        return (int)min;
    }
};
