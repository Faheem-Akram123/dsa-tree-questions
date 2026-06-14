#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> bst;
    // BinarySearchTree<int> subTree;

    // BinarySearchTree<int> leftTree;
    // BinarySearchTree<int> rightTree;
    // myLL<int> LL;

    cout << "Inserting values...\n";
    bst.insert(15);
    bst.insert(20);
    bst.insert(10);
    bst.insert(12);
    bst.insert(13);
    bst.insert(14);
    bst.insert(19);
    bst.insert(25);

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

    // cout << "single parent nodes are : " << bst.singleParent() << endl;
    // bst.convert2List(LL);
    // LL.display();

    // bst.split(leftTree, rightTree);

    // leftTree.inorderDisplay();
    // cout << endl;
    // rightTree.inorderDisplay();

    // bst.subTreeFromValue(subTree,15);
    // subTree.inorderDisplay();

    // ofstream out("text.txt");
    // ifstream read("words.txt");
    // if (read.is_open())
    // {
    //     string word;
    //     while (!read.eof())
    //     {
    //         read >> word;
    //         bst.insert(word);
    //     }
    // }
    // else
    // {
    //     cout << "file not open" << endl;
    // }

    // if (out.is_open())
    // {
    //     bst.writeToFile(out);
    // }
    // else
    // {
    //     cout << "output file not open" << endl;
    // }

    // if (bst.search("programmings"))
    // {
    //     cout << "value found" << endl;
    // }
    // else
    // {
    //     cout << "not in file or tree" << endl;
    // }

    // bst.remove("programming");
    // bst.insert("Faheem");
    // bst.inorderDisplay();

    int esum = 0, osum = 0, ocount = 0, ecount = 0;
    bst.sumAndCountEOVs(esum, osum, ecount, ocount);
    cout << ecount << " --> " << esum << endl;
    cout << ocount << " --> " << osum << endl;
    return 0;
}

// template <class T>
// void morrisInorder(Node<T>* root)
// {
//     Node<T>* curr = root;

//     while (curr != nullptr)
//     {
//         if (curr->left == nullptr)
//         {
//             cout << curr->data << " ";
//             curr = curr->right;
//         }
//         else
//         {
//             Node<T>* pred = curr->left;

//             while (pred->right != nullptr && pred->right != curr)
//                 pred = pred->right;

//             if (pred->right == nullptr)
//             {
//                 pred->right = curr;   // create thread
//                 curr = curr->left;
//             }
//             else
//             {
//                 pred->right = nullptr; // remove thread
//                 cout << curr->data << " ";
//                 curr = curr->right;
//             }
//         }
//     }
// }

// template <class T>
// void morrisPreorder(Node<T>* root)
// {
//     Node<T>* curr = root;

//     while (curr != nullptr)
//     {
//         if (curr->left == nullptr)
//         {
//             cout << curr->data << " ";
//             curr = curr->right;
//         }
//         else
//         {
//             Node<T>* pred = curr->left;

//             while (pred->right != nullptr && pred->right != curr)
//                 pred = pred->right;

//             if (pred->right == nullptr)
//             {
//                 cout << curr->data << " ";
//                 pred->right = curr;
//                 curr = curr->left;
//             }
//             else
//             {
//                 pred->right = nullptr;
//                 curr = curr->right;
//             }
//         }
//     }
// }