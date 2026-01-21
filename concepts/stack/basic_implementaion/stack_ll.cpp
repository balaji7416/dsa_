#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *next;
    node(int val) : val(val), next(nullptr) {}
};

class Stack
{
private:
    node *topNode;

public:
    Stack() : topNode(nullptr) {}

    void push(int val)
    {
        node *newnode = new node(val);
        newnode->next = topNode;
        topNode = newnode;
    }

    void pop()
    {
        if (empty())
        {
            cout << "underflow" << endl;
            return;
        }
        node *temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    bool empty()
    {
        return topNode == nullptr;
    }

    int top()
    {
        if (empty())
        {
            cout << "stk empty" << endl;
            return -1;
        }
        return topNode->val;
    }

    void print()
    {
        if (topNode == nullptr)
        {
            cout << "stk empty" << endl;
            return;
        }
        node *temp = topNode;
        while (temp != nullptr)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
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