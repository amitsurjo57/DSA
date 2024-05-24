#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class linkedlist
{
public:
    Node *head = NULL;

    void add(int);
    void add(int, int);
    void printlist();
};

void linkedlist ::add(int data)
{
    Node *newNode = new Node(data);
    Node *currNode = head;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    while (currNode->next != NULL)
    {
        currNode = currNode->next;
    }

    currNode->next = newNode;
}

void linkedlist::add(int index, int data)
{
    Node *newNode = new Node(data);
    Node *currNode = head;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = newNode;
        return;
    }
    else
    {
        if (index == 1)
        {
            head = newNode;
            newNode->next = currNode;
            return;
        }

        int count = 1;
        while (count < index - 1)
        {
            currNode = currNode->next;
            count++;
        }

        Node *temp = currNode->next;
        currNode->next = newNode;
        newNode->next = temp;
    }
}

void linkedlist::printlist()
{
    Node *currNode = head;
    while (currNode != NULL)
    {
        cout << currNode->data << " -> ";
        currNode = currNode->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    linkedlist c;

    c.add(12);
    c.add(13);
    c.add(14);
    c.add(15);

    cout << "List before insert element: " << endl;
    c.printlist();

    c.add(1, 100);
    cout << "List after insert element at First Position: " << endl;
    c.printlist();

    c.add(6, 200);
    cout << "List after insert element at Last Position: " << endl;
    c.printlist();

    c.add(4, 300);
    cout << "List after insert element at Middle Position: " << endl;
    c.printlist();
}
