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
    void deletion(int);
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
    Node *currNode = head;
    while (currNode != NULL)
    {
        cout << currNode->data << " -> ";
        currNode = currNode->next;
    }
    cout << "NULL" << endl;
}

void linkedlist::deletion(int index)
{
    Node *currNode = head;
    Node *secNode = head;

    if (index == 1)
    {
        head = currNode->next;
        return;
    }
    else
    {
        int count = 1;
        while (currNode->next != NULL)
        {
            if (count == index - 1)
            {
                secNode = secNode->next->next;
                currNode->next = secNode;
                return;
            }

            currNode = currNode->next;
            secNode = secNode->next;
            count++;
        }
    }
}

int main()
{
    linkedlist c;
    c.add(12);
    c.add(13);
    c.add(14);
    c.add(15);
    c.add(16);
    c.add(17);
    c.add(18);
    c.add(19);
    c.add(20);

    cout << endl
         << "List defore delete elements: " << endl;
    c.printlist();
    cout << endl;

    cout << endl
         << "List after delete elements from First Position: " << endl;
    c.deletion(1);
    c.printlist();
    cout << endl;

    cout << endl
         << "List after delete elements from Last Position: " << endl;
    c.deletion(8);
    c.printlist();
    cout << endl;

    cout << endl
         << "List after delete elements from Middle Position: " << endl;
    c.deletion(4);
    c.printlist();
    cout << endl;
}
