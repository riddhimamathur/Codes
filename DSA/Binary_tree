#include <iostream>
using namespace std;

//==================== NODE ====================

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

//==================== SIMPLE QUEUE ====================

class Queue
{
private:
    Node *arr[100];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1 || front > rear);
    }

    void enqueue(Node *temp)
    {
        if (rear == 99)
        {
            cout << "Queue Full\n";
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = temp;
    }

    Node *dequeue()
    {
        if (isEmpty())
            return NULL;

        return arr[front++];
    }
};

//==================== BINARY TREE ====================

class BinaryTree
{
private:

    // Height
    int height(Node *root)
    {
        if (root == NULL)
            return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return (leftHeight > rightHeight ?
                leftHeight : rightHeight) + 1;
    }

    // Total Nodes
    int countNodes(Node *root)
    {
        if (root == NULL)
            return 0;

        return 1 +
               countNodes(root->left) +
               countNodes(root->right);
    }

    // Leaf Nodes
    int countLeaf(Node *root)
    {
        if (root == NULL)
            return 0;

        if (root->left == NULL &&
            root->right == NULL)
            return 1;

        return countLeaf(root->left) +
               countLeaf(root->right);
    }

    // Internal Nodes
    int countInternal(Node *root)
    {
        if (root == NULL)
            return 0;

        if (root->left == NULL &&
            root->right == NULL)
            return 0;

        return 1 +
               countInternal(root->left) +
               countInternal(root->right);
    }

    // Search
    bool search(Node *root, int value)
    {
        if (root == NULL)
            return false;

        if (root->data == value)
            return true;

        return search(root->left, value) ||
               search(root->right, value);
    }

    // Min
    int minValue(Node *root)
    {
        if (root == NULL)
            return 99999;

        int leftMin = minValue(root->left);
        int rightMin = minValue(root->right);

        int min = root->data;

        if (leftMin < min)
            min = leftMin;

        if (rightMin < min)
            min = rightMin;

        return min;
    }

    // Max
    int maxValue(Node *root)
    {
        if (root == NULL)
            return -99999;

        int leftMax = maxValue(root->left);
        int rightMax = maxValue(root->right);

        int max = root->data;

        if (leftMax > max)
            max = leftMax;

        if (rightMax > max)
            max = rightMax;

        return max;
    }

public:
    Node *root;

    BinaryTree()
    {
        root = NULL;
    }

    //================ INSERT ==================

    void insert(int value)
    {
        Node *newNode = new Node(value);

        if (root == NULL)
        {
            root = newNode;
            return;
        }

        Queue q;
        q.enqueue(root);

        while (!q.isEmpty())
        {
            Node *temp = q.dequeue();

            if (temp->left == NULL)
            {
                temp->left = newNode;
                return;
            }
            else
                q.enqueue(temp->left);

            if (temp->right == NULL)
            {
                temp->right = newNode;
                return;
            }
            else
                q.enqueue(temp->right);
        }
    }

    //================ PREORDER =================

    void preorder(Node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    //================ INORDER =================

    void inorder(Node *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    //================ POSTORDER =================

    void postorder(Node *root)
    {
        if (root == NULL)
            return;

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    //================ LEVEL ORDER =================

    void levelOrder()
    {
        if (root == NULL)
            return;

        Queue q;
        q.enqueue(root);

        while (!q.isEmpty())
        {
            Node *temp = q.dequeue();

            cout << temp->data << " ";

            if (temp->left)
                q.enqueue(temp->left);

            if (temp->right)
                q.enqueue(temp->right);
        }
    }

    //================ SEARCH =================

    bool searchValue(int value)
    {
        return search(root, value);
    }

    //================ HEIGHT =================

    int getHeight()
    {
        return height(root);
    }

    //================ COUNTS =================

    int getTotalNodes()
    {
        return countNodes(root);
    }

    int getLeafNodes()
    {
        return countLeaf(root);
    }

    int getInternalNodes()
    {
        return countInternal(root);
    }

    //================ MIN/MAX =================

    int getMin()
    {
        return minValue(root);
    }

    int getMax()
    {
        return maxValue(root);
    }

    //================ DELETE DEEPEST =================

    void deleteDeepest(Node *deepest)
    {
        Queue q;
        q.enqueue(root);

        while (!q.isEmpty())
        {
            Node *temp = q.dequeue();

            if (temp->left)
            {
                if (temp->left == deepest)
                {
                    delete temp->left;
                    temp->left = NULL;
                    return;
                }
                q.enqueue(temp->left);
            }

            if (temp->right)
            {
                if (temp->right == deepest)
                {
                    delete temp->right;
                    temp->right = NULL;
                    return;
                }
                q.enqueue(temp->right);
            }
        }
    }

    //================ DELETE NODE =================

    void deleteNode(int value)
    {
        if (root == NULL)
            return;

        Queue q;
        q.enqueue(root);

        Node *target = NULL;
        Node *deepest = NULL;

        while (!q.isEmpty())
        {
            deepest = q.dequeue();

            if (deepest->data == value)
                target = deepest;

            if (deepest->left)
                q.enqueue(deepest->left);

            if (deepest->right)
                q.enqueue(deepest->right);
        }

        if (target)
        {
            target->data = deepest->data;
            deleteDeepest(deepest);
        }
    }
};

//==================== MAIN ====================

int main()
{
    BinaryTree bt;

    bt.insert(10);
    bt.insert(20);
    bt.insert(30);
    bt.insert(40);
    bt.insert(50);
    bt.insert(60);
    bt.insert(70);

    cout << "Preorder: ";
    bt.preorder(bt.root);

    cout << "\n\nInorder: ";
    bt.inorder(bt.root);

    cout << "\n\nPostorder: ";
    bt.postorder(bt.root);

    cout << "\n\nLevel Order: ";
    bt.levelOrder();

    cout << "\n\nTotal Nodes: "
         << bt.getTotalNodes();

    cout << "\nLeaf Nodes: "
         << bt.getLeafNodes();

    cout << "\nInternal Nodes: "
         << bt.getInternalNodes();

    cout << "\nHeight: "
         << bt.getHeight();

    cout << "\nMinimum Value: "
         << bt.getMin();

    cout << "\nMaximum Value: "
         << bt.getMax();

    cout << "\nSearch 50: ";

    if (bt.searchValue(50))
        cout << "Found";
    else
        cout << "Not Found";

    bt.deleteNode(30);

    cout << "\n\nAfter Deleting 30:\n";

    cout << "Level Order: ";
    bt.levelOrder();

    return 0;
}