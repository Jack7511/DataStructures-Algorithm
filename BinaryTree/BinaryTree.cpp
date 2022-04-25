#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *root = NULL;

struct Info
{
    int Height;
    int Depth;
};

Node *GetnewNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node *Insert(Node *root, int data)
{
    if (root == NULL)
        root = GetnewNode(data);

    else if (data <= root->data)
        root->left = Insert(root->left, data);

    else
        root->right = Insert(root->right, data);

    return root;
}

void LevelOrder()
{
    if (root == NULL)
        return;
    
    queue<Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        Node *current = Q.front();
        cout << current->data << " ";

        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);

        Q.pop();
    }
}

void Preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Postorder(Node *root)
{
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

void Print(Node *root, int space)
{
    if (root == NULL)
        return;
    
    space++;
    Print(root->right, space);
    
    for (int i = 0; i < space; i++)
        cout << "\t";
    
    cout << root->data << endl;
    Print(root->left, space);
}

int LeafCount(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return LeafCount(root->left) + LeafCount(root->right);
}

int NodeCount(Node *root)
{
    if (root == NULL)
        return 0;
    return NodeCount(root->left) + NodeCount(root->right) + 1;
}

int FindHeight(Node *root)
{
    if (root == NULL)
        return -1;
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

Node *FindMax(Node *root)
{
    if (root == NULL)
        return root;
    if (root->right == NULL)
        return root;
    return FindMax(root->right);
}

Node *FindMin(Node *root)
{
    if (root == NULL)
        return root;
    if (root->left == NULL)
        return root;
    return FindMin(root->left);
}

Node *Search(Node *root, int data)
{
    if (root == NULL)
        return NULL;
    
    else if (root->data == data)
        return root;

    else if (data < root->data)
        return Search(root->left, data);

    return Search(root->right, data);
}

Info HeightandDepth(Node *root, int data)
{
    Info node_info;
    node_info.Depth = -1;
    node_info.Height = -1;

    while (true)
    {
        if (root == NULL)
        {
            node_info.Depth = -1;
            node_info.Height = -1;
            break;
        }

        else if (root->data == data)
        {
            node_info.Depth += 1;
            node_info.Height = FindHeight(root);
            break;
        }

        else if (data < root->data)
        {
            node_info.Depth += 1;
            root = root->left;
        }

        else
        {
            node_info.Depth += 1;
            root = root->right;
        }
    }
    return node_info;
}

Node *InOrderSuccessor(Node *root, int data)
{
    Node *current = Search(root, data);
    
    if (current == NULL)
        return NULL;

    if (current->right != NULL)
        return FindMin(current->right);
    
    else
    {
        Node *successor = NULL;
        Node *ancestor = root;
        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}

Node *InOrderPredecessor(Node *root, int data)
{
    Node *current = Search(root, data);
    
    if (current == NULL)
        return NULL;

    if (current->left != NULL)
        return FindMax(current->left);
    
    else
    {
        Node *successor = NULL;
        Node *ancestor = root;
        while (ancestor != current)
        {
            if (current->data > ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->right;
            }
            else
                ancestor = ancestor->left;
        }
        return successor;
    }
}

Node *Delete(Node *root, int data)
{
    if (root == NULL)
        return root;

    else if (root->data > data)
        root->left = Delete(root->left, data);

    else if (root->data < data)
        root->right = Delete(root->right, data);

    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

bool isCompleteBinaryTree(Node *root)
{
    if ((root->left == NULL && root->right == NULL) || (root->left != NULL && root->right == NULL))
        return true;
    
    if (root->left == NULL && root->right != NULL)
        return false;
    
    return isCompleteBinaryTree(root->left) && isCompleteBinaryTree(root->right) && FindHeight(root->left) >= FindHeight(root->right);
}

bool isPerfectBinaryTree(Node *root)
{
    if (root->left == NULL && root->right == NULL)
        return true;
    
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
        return false;
    
    return isPerfectBinaryTree(root->left) && isPerfectBinaryTree(root->right) && FindHeight(root->left) == FindHeight(root->right);
}

bool isStrictBinaryTree(Node *root)
{
    if (root->left == NULL && root->right == NULL)
        return true;
    
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
        return false;
    
    return isStrictBinaryTree(root->left) && isStrictBinaryTree(root->right);
}

bool isBinarySearchTree(Node *root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;

    if (root->data > minValue && root->data < maxValue && isBinarySearchTree(root->left, minValue, root->data) && isBinarySearchTree(root->right, root->data, maxValue))
        return true;

    return false;
}

int main()
{
    root = Insert(root, 50);
    Insert(root, 30);
    Insert(root, 20);
    Insert(root, 70);
    Insert(root, 60);
    Insert(root, 80);
    Insert(root, 40);
    Insert(root, 0);

    int choice, element;

    while (true)
    {
        cout << "\n------------------------------------------------------" << endl;
        cout << "          1-> Insert Node                             " << endl;
        cout << "          2-> Traverse BinaryTree                     " << endl;
        cout << "          3-> Extra Information about BinaryTree      " << endl;
        cout << "          4-> Search Node                             " << endl;
        cout << "          5-> InOrder Successor and Predecessor       " << endl;
        cout << "          6-> Delete Node                             " << endl;
        cout << "------------------------------------------------------" << endl;
        cout << ">> ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\nEnter the Node: ";
            cin >> element;
            root = Insert(root, element);
        }
        else if (choice == 2)
        {
            Print(root, 0);
            cout << "\nLevel Order: ";
            LevelOrder();
            cout << endl;
            cout << "PreOrder: ";
            Preorder(root);
            cout << endl;
            cout << "InOrder: ";
            Inorder(root);
            cout << endl;
            cout << "PostOrder: ";
            Postorder(root);
            cout << endl;
        }
        else if (choice == 3)
        {
            cout << "\nHeight: " << FindHeight(root) << endl;
            cout << "NodeCount: " << NodeCount(root) << endl;
            cout << "LeafCount: " << LeafCount(root) << endl;
            cout << "Complete BinaryTree: ";
            isCompleteBinaryTree(root) ? cout << "True" : cout << "False";
            cout << "\nPerfect BinaryTree: ";
            isPerfectBinaryTree(root) ? cout << "True" : cout << "False";
            cout << "\nStrict BinaryTree: ";
            isStrictBinaryTree(root) ? cout << "True" : cout << "False";
            cout << "\nBinarySearchTree: ";
            isBinarySearchTree(root, INT_MIN, INT_MAX) ? cout << "True" : cout << "False";
            cout << "\nMaximum Value: " << FindMax(root)->data << endl;
            cout << "Minimum Value: " << FindMin(root)->data;
        }
        else if (choice == 4)
        {
            cout << "\nEnter the Node to be Searched: ";
            cin >> element;
            
            Info node = HeightandDepth(root, element);
            
            if (node.Depth != -1)
                cout << "\nNode Found with Depth " << node.Depth << " and Height " << node.Height;
            else
                cout << "\nNode Not Found";
        }
        else if (choice == 5)
        {
            cout << "\nEnter the Node: ";
            cin >> element;
            cout << "\nInOrderSuccessor: " << InOrderSuccessor(root, element)->data << endl;
            cout << "InOrderPredecessor: " << InOrderPredecessor(root, element)->data;
        }
        else if (choice == 6)
        {
            cout << "\nEnter the Node to be Deleted: ";
            cin >> element;
            root = Delete(root, element);
        }
        else
        {
            exit(0);
        }
    }
}
