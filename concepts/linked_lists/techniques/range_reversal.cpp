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

void print(Node *head)
{
    if (head == nullptr)
    {
        cout << "list empty" << endl;
        return;
    }
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "nullptr" << endl;
}

void range_reverse(int m, int n, Node *&head)
{
    Node *dummy = new Node(-1);
    dummy->next = head;

    Node *prev = dummy;
    for (int i = 0; i < m - 1; i++)
    {
        prev = prev->next;
    }

    Node *curr = prev->next;
    Node *nextNode;
    for (int i = 0; i < n - m; i++)
    {
        nextNode = curr->next;
        curr->next = nextNode->next;
        nextNode->next = prev->next;
        prev->next = nextNode;
    }
}

int main()
{
    Node *head = nullptr;
    for (int i = 1; i < 11; i++)
    {
        insert(i, head);
    }

    int m, n;
    cin >> m >> n;
    range_reverse(m, n, head);
    print(head);
    return 0;
}