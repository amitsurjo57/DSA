#include <iostream>
using namespace std;

class Queue
{
public:
    int size;
    int *queue;
    int rear = -1;

    Queue(int size)
    {
        queue = new int[size];
        this->size = size;
    }

    bool isEmpty();
    bool isFull();
    void add(int);
    void removeFirst();
    int peek();
    void print();
};

bool Queue::isEmpty()
{
    return rear == -1;
}

bool Queue::isFull()
{
    return rear == size - 1;
}

void Queue::add(int data)
{
    if (isFull())
    {
        cout << "Queue Filled" << endl;
        return;
    }

    rear++;
    queue[rear] = data;
}

void Queue::removeFirst()
{
    if (isEmpty())
    {
        cout << "Queue Empty" << endl;
        return;
    }

    for (int i = 0; i < rear; i++)
    {
        queue[i] = queue[i + 1];
    }

    rear--;
}

int Queue::peek()
{
    if (isEmpty())
    {
        cout << "Queue empty" << endl;
        return -1;
    }

    return queue[0];
}

void Queue::print()
{
    while (!isEmpty())
    {
        cout << peek() << endl;
        removeFirst();
    }
}

int main()
{
    Queue q(10);
    q.add(1);
    q.add(2);
    q.add(3);
    q.add(4);
    q.add(5);
    q.print();
}
