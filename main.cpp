#include "bst.h"

bool helper(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;

    if (root1 == nullptr || root2 == nullptr)
        return false;

    return (root1 == root2 &&
            root1->leftChild == root2->leftChild &&
            root1->rightChild == root2->rightChild);
}

bool isIdentical(BST *t1, BST *t2)
{
    return helper(t1->rootNode(), t2->rootNode());
}

int main()
{
    BST obj;
    obj.insert(500);
    obj.insert(250);
    obj.insert(750);
    obj.insert(100);
    obj.insert(200);
    obj.insert(1000);
    obj.insert(800);
    obj.insert(600);

    BST obj1;
    obj1.insert(500);
    obj1.insert(250);
    obj1.insert(750);
    obj1.insert(100);
    obj1.insert(200);
    obj1.insert(1000);
    obj1.insert(800);
    obj1.insert(600);

    cout << isIdentical(&obj, &obj1) << endl;
}