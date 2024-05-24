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

    void add(int data)
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

    void printlist()
    {
        Node *currNode = head;
        while (currNode != NULL)
        {
            cout << currNode->data << " ";
            currNode = currNode->next;
        }
        cout << endl;
    }
};

int main()
{
    linkedlist c;
    c.add(12);
    c.add(13);
    c.add(14);
    c.add(15);
    c.printlist();
}
