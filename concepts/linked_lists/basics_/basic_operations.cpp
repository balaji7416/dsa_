#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    struct Node *next;

    Node(int val) : val(val), next(nullptr) {}
};

class List
{
private:
    Node *head;

public:
    List() : head(nullptr) {}

    void insert(int val)
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

    void remove(int val)
    {
        if (head == nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }

        if (head->val == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *curr = head;
        while (curr->next != nullptr && curr->next->val != val)
        {
            curr = curr->next;
        }

        if (curr->next == nullptr)
        {
            cout << "val not found in list" << endl;
            return;
        }
        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }

    void insert_k(int val, int k)
    {
        Node *dummy = new Node(-1);
        dummy->next = head;

        Node *curr = dummy;

        // move curr to k-1 th node

        for (int i = 1; i < k; i++)
        {
            if (curr->next == nullptr)
            {
                delete dummy;
                cout << "invalid position" << endl;
                return;
            }
            curr = curr->next;
        }

        Node *newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void print()
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
};

int main()
{
    List l;
    l.print();
    for (int i = 0; i < 10; i++)
    {
        l.insert(i);
    }
    l.print();
    l.insert_k(50, 5);
    l.insert_k(3, 123);
    l.print();
    return 0;
}