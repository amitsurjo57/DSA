#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist
{
    Node *head;

public:
    Linkedlist() { head = NULL; }
    void add(int);
    void printList();
};

void Linkedlist::add(int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void Linkedlist::printList()
{
    Node *temp = head;

    if (head == NULL)
    {
        cout << "List empty" << endl;
        return;
    }

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Linkedlist list;
    list.add(12);
    list.add(13);
    list.add(14);
    list.add(15);
    list.add(16);

    list.printList();
}
