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
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new Node(val);
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

Node *range_revere(int l, int r, Node *dummy, Node *prev)
{
    Node *curr = prev->next;
    Node *next;
    for (int i = 0; i < r - l; i++)
    {
        next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }
    return curr;
}

int main()
{
    Node *head = nullptr;
    for (int i = 1; i < 11; i++)
    {
        insert(i, head);
    }

    int k;
    cin >> k;

    Node *dummy = new Node(-1);
    dummy->next = head;

    int n = 0;
    Node *curr = head;
    while (curr != nullptr)
    {
        n++;
        curr = curr->next;
    }
    Node *prev = dummy;
    for (int r = k; r <= n; r += k)
    {
        prev = range_revere(r - k + 1, r, dummy, prev);
    }

    print(dummy->next);
    return 0;
}