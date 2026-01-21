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

int middle_element(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr and fast->next != nullptr and fast->next->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->val;
}

int main()
{
    Node *head = nullptr;
    for (int i = 0; i < 10; i++)
    {
        insert(i, head);
    }

    cout << middle_element(head) << endl;
}