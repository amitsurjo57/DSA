#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
public:
    Node *head = NULL;

    bool isEmpty()
    {
        return head == NULL;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void pop()
    {
        if (isEmpty())
        {
            return;
        }

        int top = head->data;
        head = head->next;
    }

    int top()
    {
        if (isEmpty())
        {
            return -1;
        }

        return head->data;
    }
};

int main()
{
    Stack stack;
    stack.push(5);
    stack.push(6);
    stack.push(2);
    stack.push(4);
    stack.push(3);
    stack.push(1);
    stack.push(7);
    stack.push(9);

    while(!stack.isEmpty()){
        cout << stack.top() << endl;
        stack.pop();
    }
}
