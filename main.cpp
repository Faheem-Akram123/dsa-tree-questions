#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> bst;

    cout << "Inserting values...\n";
    bst.insert(15);
    bst.insert(20);
    bst.insert(10);
    bst.insert(12);
    bst.insert(13);
    bst.insert(14);
    bst.insert(11);

    // cout << "\nInorder (should be sorted): ";
    // bst.inorderDisplay();
    // cout << endl;

    // cout << "Preorder: ";
    // bst.preorderDisplay();
    // cout << endl;

    // cout << "Postorder: ";
    // bst.postorderDisplay();
    // cout << endl;

    // cout << "\nSearch tests:\n";
    // cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    // cout << "Search 100: " << (bst.search(100) ? "Found" : "Not Found") << endl;

    // cout << "\nTree properties:\n";
    // cout << "Height: " << bst.treeHeight() << endl;
    // cout << "Total nodes: " << bst.treeNodeCount() << endl;
    // cout << "Leaf nodes: " << bst.treeLeavesCount() << endl;

    // cout << "\nRemoving 30...\n";
    // bst.remove(30);

    // cout << "Inorder after deletion: ";
    // bst.inorderDisplay();
    // cout << endl;

    // cout << "\nRemoving 50 (root)...\n";
    // bst.remove(50);

    // cout << "Inorder after root deletion: ";
    // bst.inorderDisplay();
    // cout << endl;

    // bst.inorderDisplay();
    // bst.swapSubTrees();
    // cout << endl;
    // bst.inorderDisplay();

    cout << "single parent nodes are : " << bst.singleParent() << endl;
    

    return 0;
}