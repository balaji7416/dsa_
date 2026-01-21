#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int arr[1000];
    int topIdx;

public:
    Stack() : topIdx(-1) {}

    void push(int value)
    {
        if (topIdx == 999)
        {
            cout << "overflow" << endl;
            return;
        }
        arr[++topIdx] = value;
    }

    void pop()
    {
        if (topIdx == -1)
        {
            cout << "underflow" << endl;
            return;
        }
        topIdx--;
    }

    bool empty()
    {
        return topIdx == -1;
    }

    int top()
    {
        if (topIdx == -1)
        {
            cout << "stk empty" << endl;
            return -1;
        }
        return arr[topIdx];
    }
    void print()
    {
        for (int i = 0; i <= topIdx; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Stack stk;
    for (int i = 0; i < 10; i++)
    {
        stk.push(i + 1);
    }
    stk.print();
    stk.pop();
    stk.push(99);
    stk.print();
    return 0;
}