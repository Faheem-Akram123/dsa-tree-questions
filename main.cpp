#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> bst;

    cout << "Inserting values...\n";
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "\nInorder (should be sorted): ";
    bst.inorderDisplay();
    cout << endl;

    cout << "Preorder: ";
    bst.preorderDisplay();
    cout << endl;

    cout << "Postorder: ";
    bst.postorderDisplay();
    cout << endl;

    cout << "\nSearch tests:\n";
    cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (bst.search(100) ? "Found" : "Not Found") << endl;

    cout << "\nTree properties:\n";
    cout << "Height: " << bst.treeHeight() << endl;
    cout << "Total nodes: " << bst.treeNodeCount() << endl;
    cout << "Leaf nodes: " << bst.treeLeavesCount() << endl;

    cout << "\nRemoving 30...\n";
    bst.remove(30);

    cout << "Inorder after deletion: ";
    bst.inorderDisplay();
    cout << endl;

    cout << "\nRemoving 50 (root)...\n";
    bst.remove(50);

    cout << "Inorder after root deletion: ";
    bst.inorderDisplay();
    cout << endl;

    return 0;
}