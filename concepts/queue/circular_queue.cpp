#include <bits/stdc++.h>
using namespace std;

/*
    queue structure
    ---------------------
    f| --| --| --| --|------------- |r
    ---------------------
*/

class CircularQueue
{
    int size, front, rear;
    int max_size;
    int *arr;

public:
    CircularQueue() : size(0), front(0), rear(-1), arr(new int[1000]), max_size(1000) {}

    void push(int val)
    {
        if (size == max_size)
        {
            cout << "Queue is full" << endl;
            return;
        }
        size++;
        rear = (rear + 1) % max_size;
        arr[rear] = val;
    }

    void pop()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        size--;
        front = (front + 1) % max_size;
    }

    int front_element()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    void display()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        for (int i = front; i != rear; i = (i + 1) % max_size)
        {

            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }
};

int main()
{
    CircularQueue q;
    q.push(3);
    q.push(4);
    q.display();
    q.pop();
    q.display();

    return 0;
}