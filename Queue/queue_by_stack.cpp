#include <iostream>
#include <stack>
using namespace std;

class Queue
{
public:
    stack<int> s1;
    stack<int> s2;

    void add(int);
    void remove();
    int peek();
    void print();
};

void Queue::add(int data)
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    s1.push(data);

    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

void Queue::remove()
{
    if (s1.empty())
    {
        cout << "Queue is empty" << endl;
        return;
    }

    s1.pop();
}

int Queue::peek()
{
    if (s1.empty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }

    return s1.top();
}

void Queue::print()
{
    while (!s1.empty())
    {
        cout << peek() << endl;
        remove();
    }
}

int main()
{
    Queue queue;
    queue.add(1);
    queue.add(2);
    queue.add(3);
    queue.add(4);
    queue.add(5);
    queue.print();
}
