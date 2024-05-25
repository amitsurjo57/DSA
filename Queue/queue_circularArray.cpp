#include <iostream>
using namespace std;

class Queue
{
public:
    int *queue;
    int size;
    int rear = -1;
    int front = -1;

    Queue(int size)
    {
        queue = new int[size];
        this->size = size;
    }

    bool isEmpty();
    bool isFull();
    void add(int);
    void remove();
    int peek();
    void print();
};

bool Queue::isEmpty()
{
    return rear == -1 && front == -1;
}

bool Queue::isFull()
{
    return (rear + 1) % size == front;
}

void Queue::add(int data)
{
    if (isFull())
    {
        cout << "Queue filled" << endl;
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear = (rear + 1) % size;
    queue[rear] = data;
}

void Queue::remove()
{
    if (isEmpty())
    {
        cout << "Queue empty" << endl;
        return;
    }

    if (rear == front)
    {
        rear = front = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
}

int Queue::peek()
{
    if (isEmpty())
    {
        cout << "Queue empty" << endl;
        return -1;
    }

    return queue[front];
}

void Queue::print()
{
    while (!isEmpty())
    {
        cout << peek() << endl;
        remove();
    }
}

int main()
{
    Queue queue(5);
    queue.add(1);
    queue.add(2);
    queue.add(3);
    queue.add(4);
    queue.add(5);
    queue.remove();
    queue.add(6);
    queue.remove();
    queue.add(7);
    queue.print();
}
