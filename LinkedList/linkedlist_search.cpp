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

    void add(int data);
    void printlist();
    void search(int);
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

void linkedlist::search(int data){
    Node *newNode = new Node(data);
    Node *currNode = head;
    int pos = 1;

    if(head == NULL){
        head = newNode;
        return;
    }

    while(currNode != NULL){
        if(currNode->data == data){
            cout << data << " is present in the list at position " << pos << endl;
            return;
        }

        currNode = currNode->next;
        pos++;
    }
    cout << data << " is not present in the list" << endl;
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
    c.printlist();

    c.search(16);
}
