#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *searchBST(Node *root, int value)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == value)
    {
        return root;
    }

    if(value < root->data)
    {
        return searchBST(root->left, value);
    }

    if(value > root->data)
    {
        return searchBST(root->right, value);
    }

}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    root->right = new Node(5);
    root->right->right = new Node(6);

    if(searchBST(root, 50) == NULL)
    {
        cout << "Value does not exist" << endl;
    }
    else
    {
        cout << "Value exists" << endl;
    }
}
