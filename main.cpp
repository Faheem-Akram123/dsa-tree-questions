#include "bst.h"

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

    obj.deleteValue(750);
    obj.deleteValue(200);
    obj.deleteValue(600);
    obj.deleteValue(500);
    obj.postorder();
}