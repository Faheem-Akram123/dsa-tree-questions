#include "BinarySearch.h"

template <class T>
class BinarySearchTree : public BinaryTree<T>
{
    void INORDER(Node<T> *root) const;
    void PREORDER(Node<T> *root) const;
    void POSTORDER(Node<T> *root) const;
    void swapSubT(Node<T> *root);
    int sinParent(Node<T> *root);

    void C2L(Node<T> *root, myLL<T> &LL);
    void subTree(Node<T> *root, Node<T> *&Lroot, Node<T> *&Rnode);

public:
    BinarySearchTree() : BinaryTree<T>() {}
    BinarySearchTree(const BinarySearchTree &bt) : BinaryTree<T>(bt) {}
    const BinarySearchTree &operator=(const BinarySearchTree &);
    ~BinarySearchTree() {}
    void insert(const T &value);
    void remove(const T &value);
    bool search(const T &value) const;
    bool isEmpty() const;

    void inorderDisplay() const;
    void preorderDisplay() const;
    void postorderDisplay() const;

    void swapSubTrees();
    int singleParent();

    void convert2List(myLL<T> &LL);
    void split(BinarySearchTree<T> &lt, BinarySearchTree<T> &rt);
    void subTreeFromValue(BinarySearchTree<T> &sbT, const int &value);
};

template <class T>
void BinarySearchTree<T>::subTreeFromValue(BinarySearchTree<T> &sbT, const int &value)
{
    if (isEmpty())
    {
        cout << "Tree is empty " << endl;
        return;
    }

    Node<T> *p = this->root;
    while (p != nullptr)
    {
        if (p->data == value)
        {
            sbT.root = this->copyNodes(p);
            return;
        }
        else
        {
            if (value < p->data)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
    }
    return;
}

template <class T>
void BinarySearchTree<T>::subTree(Node<T> *root, Node<T> *&Lroot, Node<T> *&Rroot)
{
    if (root == nullptr)
    {
        Lroot = nullptr;
        Rroot = nullptr;
        return;
    }

    Lroot = root->left;
    Rroot = root->right;

    root->left = nullptr;
    root->right = nullptr;
}

template <class T>
void BinarySearchTree<T>::split(BinarySearchTree<T> &lt, BinarySearchTree<T> &rt)
{
    if (this->root == nullptr)
    {
        cout << "Tree is empty" << endl;
        return;
    }

    subTree(this->root, lt.root, rt.root);
}

template <class T>
void BinarySearchTree<T>::C2L(Node<T> *root, myLL<T> &LL)
{
    if (root == nullptr)
        return;

    C2L(root->left, LL);
    LL.insertAtTail(root->data);
    C2L(root->right, LL);
}

template <class T>
void BinarySearchTree<T>::convert2List(myLL<T> &LL)
{
    if (this->root == nullptr)
        return;

    C2L(this->root, LL);
}

template <class T>
int BinarySearchTree<T>::sinParent(Node<T> *root)
{
    if (root == nullptr)
        return 0;

    if (!root->left && root->right || root->left && !root->right)
    {
        return sinParent(root->left) + sinParent(root->right) + 1;
    }
    else
    {
        return sinParent(root->left) + sinParent(root->right);
    }
}

template <class T>
int BinarySearchTree<T>::singleParent()
{
    if (this->root == nullptr)
        return 0;

    return sinParent(this->root);
}

template <class T>
void BinarySearchTree<T>::swapSubT(Node<T> *root)
{
    if (root == nullptr)
        return;

    Node<T> *temp = root->left;
    root->left = root->right;
    root->right = temp;

    swapSubT(root->right);
    swapSubT(root->left);
}

template <class T>
void BinarySearchTree<T>::swapSubTrees()
{
    if (this->root == nullptr)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    swapSubT(this->root);
}

template <class T>
void BinarySearchTree<T>::INORDER(Node<T> *root) const
{
    if (root == nullptr)
        return;

    INORDER(root->left);
    cout << root->data << " ";
    INORDER(root->right);
}

template <class T>
void BinarySearchTree<T>::PREORDER(Node<T> *root) const
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    PREORDER(root->left);
    PREORDER(root->right);
}

template <class T>
void BinarySearchTree<T>::POSTORDER(Node<T> *root) const
{
    if (root == nullptr)
        return;

    POSTORDER(root->left);
    POSTORDER(root->right);
    cout << root->data << " ";
}

template <class T>
void BinarySearchTree<T>::inorderDisplay() const
{
    if (isEmpty())
    {
        cout << "Tree is Empty" << endl;
    }
    else
    {
        INORDER(this->root);
    }
}

template <class T>
void BinarySearchTree<T>::preorderDisplay() const
{
    if (isEmpty())
    {
        cout << "Tree is Empty" << endl;
    }
    else
    {
        PREORDER(this->root);
    }
}

template <class T>
void BinarySearchTree<T>::postorderDisplay() const
{
    if (isEmpty())
    {
        cout << "Tree is Empty" << endl;
    }
    else
    {
        POSTORDER(this->root);
    }
}

template <class T>
bool BinarySearchTree<T>::isEmpty() const
{
    return this->root == nullptr;
}

template <class T>
void BinarySearchTree<T>::insert(const T &value)
{
    Node<T> *nn = new Node<T>;
    nn->data = value;
    nn->left = nullptr;
    nn->right = nullptr;

    if (isEmpty())
    {
        this->root = nn;
        return;
    }

    Node<T> *p = this->root;
    while (true)
    {
        if (value < p->data)
        {
            if (p->left == nullptr)
            {
                p->left = nn;
                break;
            }
            p = p->left;
        }
        else
        {
            if (p->right == nullptr)
            {
                p->right = nn;
                break;
            }
            p = p->right;
        }
    }
}

template <class T>
bool BinarySearchTree<T>::search(const T &value) const
{
    if (isEmpty())
    {
        cout << "Tree is empty " << endl;
        return false;
    }

    Node<T> *p = this->root;
    while (p != nullptr)
    {
        if (p->data == value)
        {
            return true;
        }
        else
        {
            if (value < p->data)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
    }
    return false;
}

template <class T>
void BinarySearchTree<T>::remove(const T &value)
{
    if (isEmpty())
    {
        cout << "Tree is empty" << endl;
        return;
    }

    Node<T> *parent = nullptr;
    Node<T> *curr = this->root;

    while (curr != nullptr && curr->data != value)
    {
        parent = curr;

        if (value < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (curr == nullptr)
    {
        cout << "Value not found" << endl;
        return;
    }

    if (curr->left == nullptr || curr->right == nullptr)
    {
        Node<T> *child;

        if (curr->left != nullptr)
            child = curr->left;
        else
            child = curr->right;

        if (parent == nullptr)
        {
            this->root = child;
        }
        else if (parent->left == curr)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }

        delete curr;
    }

    else
    {
        Node<T> *succParent = curr;
        Node<T> *succ = curr->right;

        while (succ->left != nullptr)
        {
            succParent = succ;
            succ = succ->left;
        }

        curr->data = succ->data;

        if (succParent->left == succ)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        delete succ;
    }
}