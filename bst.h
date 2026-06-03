#include "Tree.h"

class BST : public Tree
{
    void INORDER(Node *);
    void PREORDER(Node *);
    void POSTORDER(Node *);
    int ht(Node *root);

public:
    void insert(const int &value);
    void inorder();
    void preorder();
    void postorder();
    Node *deleteValue(const int &value);
    int heightofTree();
    Node *rootNode();
};

Node *BST::rootNode()
{
    return root;
}

int BST::ht(Node *root)
{
    if (root == nullptr)
        return 0;

    return max(ht(root->leftChild), ht(root->rightChild)) + 1;
}

int BST::heightofTree()
{
    return ht(root);
}

// Delete function without recursion
Node *BST::deleteValue(const int &key)
{
    Node *parent = NULL;
    Node *curr = root;

    // Find the node to delete
    while (curr != NULL && curr->data != key)
    {
        parent = curr;

        if (key < curr->data)
            curr = curr->leftChild;
        else
            curr = curr->rightChild;
    }

    // Node not found
    if (curr == NULL)
        return root;

    // Case 1 & 2: Node has 0 or 1 child
    if (curr->leftChild == NULL || curr->rightChild == NULL)
    {

        Node *newChild;

        if (curr->leftChild == NULL)
            newChild = curr->rightChild;
        else
            newChild = curr->leftChild;

        // If deleting root node
        if (parent == NULL)
        {
            delete curr;
            return newChild;
        }

        // Connect parent with child
        if (parent->leftChild == curr)
            parent->leftChild = newChild;
        else
            parent->rightChild = newChild;

        delete curr;
    }

    // Case 3: Node has 2 children
    else
    {

        Node *successorParent = curr;
        Node *successor = curr->rightChild;

        // Find inorder successor
        while (successor->leftChild != NULL)
        {
            successorParent = successor;
            successor = successor->leftChild;
        }

        // Copy successor value
        curr->data = successor->data;

        // Delete successor node
        if (successorParent->leftChild == successor)
            successorParent->leftChild = successor->rightChild;
        else
            successorParent->rightChild = successor->rightChild;

        delete successor;
    }
    return root;
}

void BST::POSTORDER(Node *p)
{
    if (p != nullptr)
    {
        POSTORDER(p->leftChild);
        POSTORDER(p->rightChild);
        cout << p->data << endl;
    }
}

void BST::postorder()
{
    if (root == nullptr)
        cout << "Tree is Empty" << endl;
    else
        POSTORDER(root);
}

void BST::PREORDER(Node *p)
{
    if (p != nullptr)
    {
        cout << p->data << endl;
        INORDER(p->leftChild);
        INORDER(p->rightChild);
    }
}

void BST::preorder()
{
    if (root == nullptr)
        cout << "Tree is Empty" << endl;
    else
        PREORDER(root);
}

void BST::INORDER(Node *p)
{
    if (p != nullptr)
    {
        INORDER(p->leftChild);
        cout << p->data << endl;
        INORDER(p->rightChild);
    }
}

void BST::inorder()
{
    if (root == nullptr)
        cout << "Tree is Empty" << endl;
    else
        INORDER(root);
}

void BST::insert(const int &value)
{
    Node *nn = new Node;
    nn->data = value;
    nn->leftChild = nullptr;
    nn->rightChild = nullptr;

    if (root == nullptr)
        root = nn;
    else
    {
        Node *p = root;
        while (true)
        {
            if (p->data < value)
            {
                if (p->rightChild == nullptr)
                {
                    p->rightChild = nn;
                    break;
                }
                p = p->rightChild;
            }
            else
            {
                if (p->leftChild == nullptr)
                {
                    p->leftChild = nn;
                    break;
                }
                p = p->leftChild;
            }
        }
    }
}