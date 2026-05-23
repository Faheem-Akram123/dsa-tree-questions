#include "Node.h"
#include <iostream>
using namespace std;

class Tree
{
protected:
    Node *root;
public:
    Tree();
    virtual void insert(const int &value) = 0;
    virtual void inorder() = 0;
    virtual void preorder() = 0;
    virtual void postorder() = 0;
    virtual Node *deleteValue(const int &value) = 0;
};

Tree::Tree()
{
    root = nullptr;
}