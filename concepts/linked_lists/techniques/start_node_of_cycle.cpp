#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int val) : val(val), next(nullptr) {}
};

void insert(int val, Node *&head)
{
    if (head == nullptr)
    {
        head = new Node(val);
        return;
    }
    Node *curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = new Node(val);
}

Node *cycleStartNode(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != nullptr and fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            Node *entry = head;
            while (entry != slow)
            {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }
    return nullptr;
}

int main()
{
    Node *head = nullptr;
    for (int i = 1; i <= 5; i++)
    {
        insert(i, head);
    }

    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    Node *cycle_start = tail;
    for (int i = 6; i <= 10; i++)
    {
        insert(i, head);
    }

    tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    tail->next = cycle_start;

    if (cycleStartNode(head))
        cout << (cycleStartNode(head))->val << endl;

    else
    {
        cout << "no cycle" << endl;
    }
    return 0;
}