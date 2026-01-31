#include <bits/stdc++.h>
using namespace std;

class Stack_With_Queue
{
    queue<int> q;

public:
    Stack_With_Queue() {}

    void push(int val)
    {
        q.push(val);
        for (int i = 0; i < q.size() - 1; i++)
        {
            int u = q.front();
            q.pop();
            q.push(u);
        }
    }
    void pop()
    {
        if (q.empty())
        {
            cout << "stack empty " << endl;
            return;
        }
        q.pop();
    }
    int top()
    {
        if (q.empty())
        {
            cout << "stack empty " << endl;
            return -1;
        }
        return q.front();
    }
};

int main()
{
    Stack_With_Queue s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    return 0;
}