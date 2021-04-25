#include <iostream>
#include "binarySearchTree.cpp"

using namespace std;

int main()
{
    BinarySearchTree binarySearchTree1;
    BinarySearchTree binarySearchTree2;

    binarySearchTree1.insert(50);
    binarySearchTree1.insert(20);
    binarySearchTree1.insert(60);
    binarySearchTree1.insert(10);
    binarySearchTree1.insert(25);
    binarySearchTree1.insert(15);
    binarySearchTree1.insert(5);
    binarySearchTree1.insert(70);
    binarySearchTree1.insert(65);
    binarySearchTree1.insert(80);

    binarySearchTree2.insert(70);
    binarySearchTree2.insert(65);
    binarySearchTree2.insert(80);

    int result = binarySearchTree1.isSubtree(binarySearchTree2.getRoot());

    if (result == -1)
    {
        cout << "Not a subtree";
    }
    else
    {
        cout << "Is a subtree";
    }

    return 0;
}