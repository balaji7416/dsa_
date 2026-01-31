#include <bits/stdc++.h>
using namespace std;

class Queue_With_Stack
{
    stack<int> in, out;

public:
    Queue_With_Stack() {}
    void push(int val)
    {
        in.push(val);
    }
    void pop()
    {
        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        if (out.empty())
        {
            cout << "queue is empty" << endl;
            return;
        }
        out.pop();
    }
    int front()
    {
        if (!out.empty())
        {
            return out.top();
        }
        while (!in.empty())
        {
            out.push(in.top());
            in.pop();
        }
        if (out.empty())
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        return out.top();
    }
};

int main()
{
    Queue_With_Stack q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
}