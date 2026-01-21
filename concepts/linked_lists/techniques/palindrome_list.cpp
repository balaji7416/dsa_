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

Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *nextNode;

    while (curr != nullptr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
    return head;
}

bool isPalindromeList(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *first = head;
    Node *second = reverseList(slow);

    while (second)
    {
        if (first->val != second->val)
        {
            return false;
        }
        first = first->next;
        second = second->next;
    }
    return true;
}

main()
{
    Node *head = nullptr;
    for (int i = 1; i < 5; i++)
    {
        insert(i, head);
    }
    for (int i = 4; i >= 1; i--)
    {
        insert(i, head);
    }
    print(head);
    if (isPalindromeList(head))
    {
        cout << "palindrome" << endl;
    }
    else
    {
        cout << "not a palindrome" << endl;
    }
}