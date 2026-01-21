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

void delete_k_from_end(int k, Node *&head)
{
    Node *dummy = new Node(-1);
    dummy->next = head;

    Node *slow = dummy;
    Node *fast = dummy;

    // create k nodes gap between slow and fast ptrs
    for (int i = 0; i < k; i++)
    {
        if (fast->next == nullptr)
        {
            cout << "out of bounds " << endl;
            delete dummy;
            return;
        }
        fast = fast->next;
    }

    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node *temp = slow->next;
    slow->next = temp->next;
    delete temp;

    head = dummy->next;
    delete dummy;
}
int main()
{
    Node *head = nullptr;
    for (int i = 1; i < 11; i++)
    {
        insert(i, head);
    }
    print(head);
    int k;
    cin >> k;
    delete_k_from_end(k, head);
    print(head);
}