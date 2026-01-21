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
    delete curr;
}

void reverse_list(Node *&head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main()
{
    Node *head = nullptr;
    for (int i = 1; i < 11; i++)
    {
        insert(i, head);
    }

    print(head);
    reverse_list(head);
    print(head);
}