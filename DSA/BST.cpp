#include <iostream>
using namespace std;
struct node{
                int data;
                node *Left;
                node *Right;
                node(int value)
                {
                    data=value;
                    Left=NULL;
                    Right=NULL;
                }
            };
    // insert a node
    node* insert(node *root,int value)
    {
        if(root==NULL)
            return new node(value);
    if (value < root -> data)
        root -> Left = insert(root -> Left, value);
    else if (value > root -> data)
        root -> Right = insert(root -> Right, value);
    return root;
    }

    node* minValueNode(node* root)
    {
        node* current = root;
        while (current && current->Left != NULL)
            current = current->Left;
        return current;
    }

    // search a node
    bool search(node *root, int key)
    {
        if(root==NULL)
            return false;
        if(root->data==key)
            return true;
        if(key<root->data)
            return search(root->Left,key);
        else
            return search(root->Right,key);
    }

    //inorder traversal
    void inorder(node *root)
    {
        if(root==NULL)
            return;
        inorder(root->Left);
        cout<<root->data<<" ";
        inorder(root->Right);
    }

    //preorder traversal
    void preorder(node *root)   
    {
        if(root==NULL)
            return;
        cout<<root->data<<" ";
        preorder(root->Left);
        preorder(root->Right);
    }

    //postorder traversal
    void postorder(node *root)  
    {
        if(root==NULL)
            return;
        postorder(root->Left);
        postorder(root->Right);
        cout<<root->data<<" ";
    }
    
    //Minimum value node
    node* minValueNode(node* root)
    {
        node* current = root;
        while (current && current->Left != NULL)
            current = current->Left;
        return current;
    }

    //delete a node
    node* deleteNode(node *root,int value)
    {
        if(root==NULL)
            return root;
        if(value<root->data)
            root->Left=deleteNode(root->Left,value);
        else if(value>root->data)
            root->Right=deleteNode(root->Right,value);
        else
        {
            //NODE WITH ONLY ONE CHILD OR NO CHILD
            if(root->Left==NULL)
            {
                node *temp=root->Right;
                delete root;
                return temp;
            }
            else if(root->Right==NULL)
            {
                node *temp=root->Left;
                delete root;
                return temp;
            }
            //NODE WITH TWO CHILDREN
            node *temp=minValueNode(root->Right);
            root->data = temp->data;
            root->Right = deleteNode(root->Right,temp->data);
        }
        return root;
    }


int main()
{
    node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);           
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
     cout << "Inorder traversal: ";
    inorder(root);
    cout << "\nPreorder traversal: ";   
    preorder(root);
    cout << "\nPostorder traversal: ";
    postorder(root);
    cout << endl;
    
    int key = 40;
    if (search(root,key))
        cout << "Found " << key << " in the BST.\n";
    else
        cout << key << " not found in the BST.\n";
        root = deleteNode(root,50);
        cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;
    return 0;
}