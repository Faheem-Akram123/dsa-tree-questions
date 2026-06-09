#include "Node.h"
#include "../DSA-headerFiles-using-Cpp/myLL.h"
#include <iostream>
#include<string>
#include<fstream>
using namespace std;

template <class T>
class BinaryTree
{
protected:
  Node<T> *root;
  void deleteTree();
  void copyTree(const BinaryTree *);
  Node<T> *copyNodes(Node<T> *root);
  void dt(Node<T> *root);
  int th(Node<T> *root) const;
  int tnc(Node<T> *root) const;
  int tlc(Node<T> *root) const;

public:
  BinaryTree() { root = nullptr; }
  BinaryTree(const BinaryTree &bt) { copyTree(bt); }
  const BinaryTree &operator=(const BinaryTree &);
  virtual ~BinaryTree() { deleteTree(); }
  virtual void insert(const T &value) = 0;
  virtual void remove(const T &value) = 0;
  virtual bool search(const T &value) const = 0;
  virtual bool isEmpty() const = 0;
  virtual void inorderDisplay() const = 0;
  virtual void preorderDisplay() const = 0;
  virtual void postorderDisplay() const = 0;
  int treeHeight() const;      // Returns the height of the binary tree.
  int treeNodeCount() const;   // Returns the number of nodes in the binary tree.
  int treeLeavesCount() const; // Returns the number of leaves in the binary tree
  virtual void swapSubTrees() = 0;
  virtual int singleParent() = 0;
  virtual void convert2List(myLL<T> &LL) = 0;
};

template <class T>
const BinaryTree<T> &BinaryTree<T>::operator=(const BinaryTree<T> &bt)
{
  if (this == &bt)
    return *this;

  deleteTree();
  copyTree(&bt);
  return *this;
}

template <class T>
int BinaryTree<T>::tlc(Node<T> *root) const
{
  if (root == nullptr)
    return 0;

  if (root->left == nullptr && root->right == nullptr)
  {
    return 1;
  }
  return tlc(root->left) + tlc(root->right);
}

template <class T>
int BinaryTree<T>::treeLeavesCount() const
{
  return tlc(root);
}

template <class T>
int BinaryTree<T>::tnc(Node<T> *root) const
{
  if (root == nullptr)
    return 0;

  return 1 + tnc(root->left) + tnc(root->right);
}

template <class T>
int BinaryTree<T>::treeNodeCount() const
{
  int count = 0;
  return tnc(root);
}

template <class T>
int BinaryTree<T>::th(Node<T> *root) const
{
  if (root == nullptr)
    return 0;

  return max(th(root->left), th(root->right)) + 1;
}

template <class T>
int BinaryTree<T>::treeHeight() const
{
  return th(root);
}

template <class T>
void BinaryTree<T>::dt(Node<T> *root)
{
  if (root == nullptr)
    return;

  dt(root->left);
  dt(root->right);

  delete root;
}

template <class T>
void BinaryTree<T>::deleteTree()
{
  dt(root);
  root = nullptr;
}

template <class T>
Node<T> *BinaryTree<T>::copyNodes(Node<T> *node)
{
  if (node == nullptr)
    return nullptr;

  Node<T> *nn = new Node<T>;
  nn->data = node->data;

  nn->left = copyNodes(node->left);
  nn->right = copyNodes(node->right);

  return nn;
}

template <class T>
void BinaryTree<T>::copyTree(const BinaryTree *bt)
{
  root = copyNodes(bt->root);
}