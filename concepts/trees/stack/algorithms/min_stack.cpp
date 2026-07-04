#include <bits/stdc++.h>
using namespace std;

class MinStack
{
    stack<int> s;
    stack<int> mins;

public:
    MinStack() {}
    void push(int el)
    {
        if (mins.empty() || el <= mins.top())
        {
            mins.push(el);
        }
        s.push(el);
    }

    void pop()
    {
        if (s.top() == mins.top())
        {
            mins.pop();
        }
        s.pop();
    }

    int top()
    {
        if (!s.empty())
            return s.top();
        return -1;
    }

    int minm()
    {
        if (!mins.empty())
            return mins.top();

        return -1;
    }
};

int main()
{
    MinStack stk;
    stk.push(4);
    stk.push(0);
    stk.push(-1);
    stk.push(-2);
    stk.pop();
    cout << stk.minm();
    cout << stk.minm() << endl;
    return 0;
}