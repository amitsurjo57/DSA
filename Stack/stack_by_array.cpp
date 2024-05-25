#include <iostream>
using namespace std;

#define MAX 1000

class Stack
{
public:
    int top;
    int a[MAX];

    Stack()
    {
        top = -1;
    }

    void push(int);
    void pop();
    int peek();
    bool isEmpty();
};

bool Stack::isEmpty()
{
    return (top < 0);
}

void Stack::push(int x)
{
    if (top >= MAX - 1)
    {
        cout << "The stack overflowed" << endl;
        return;
    }
    else
    {
        top++;
        a[top] = x;
    }
}

void Stack::pop()
{
    if (isEmpty())
    {
        cout << "The stack is underflowed" << endl;
        return;
    }
    else
    {
        top--;
    }
}

int Stack::peek()
{
    if (isEmpty())
    {
        cout << "The stack is underflowed" << endl;
        return 0;
    }
    else
    {
        return a[top];
    }
}

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "The top element is: " << s.peek() << endl;

    s.pop();
    cout << "The top element is: " << s.peek() << endl;

    while (!s.isEmpty())
    {
        cout << s.peek() << endl;
        s.pop();
    }
}
