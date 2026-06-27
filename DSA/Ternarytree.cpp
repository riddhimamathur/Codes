#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    char data;
    Node *left;
    Node *middle;
    Node *right;
    Node(char value)
    {
        data = value;
        left = NULL;
        middle = NULL;
        right = NULL;
    }
};
void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->middle);
    preorder(root->right);
}

int main()
{
    Node *root = new Node('A');

    root->left = new Node('B');
    root->middle = new Node('C');
    root->right = new Node('D');

    root->left->left = new Node('E');
    root->left->middle = new Node('F');
    root->left->right = new Node('G');

    root->right->left = new Node('X');
    root->right->middle = new Node('Y');
    root->right->right = new Node('Z');

    cout << "Preorder Traversal: ";
    preorder(root);

    cout << endl;

    return 0;
}