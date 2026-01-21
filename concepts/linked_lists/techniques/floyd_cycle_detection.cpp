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
        head->next = head;
        return;
    }
    Node *curr = head;
    while (curr->next != head)
    {
        curr = curr->next;
    }
    Node *newNode = new Node(val);
    curr->next = newNode;
    newNode->next = head;
}

bool hasCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr and fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Node *head = nullptr;
    for (int i = 1; i < 5; i++)
    {
        insert(i, head);
    }
    if (hasCycle(head))
    {
        cout << "cycle detected " << endl;
    }
    else
    {
        cout << "no cycle" << endl;
    }
}