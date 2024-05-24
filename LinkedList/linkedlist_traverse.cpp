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

void linkedlist::printlist()
{
    int c = 1;
    Node *currNode = head;
    cout << "All elements of the list are: " << endl;
    while (currNode != NULL)
    {
        cout << "Element no. " << c++ << " = " << currNode->data << endl;
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
    c.printlist();
}
