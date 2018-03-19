#include "BinaryTree.h"

#include <iostream>

int main()
{
   BinaryTree<int> binaryTree;

   binaryTree.InsertUnique(5);

   binaryTree.InsertUnique(4);

   binaryTree.InsertUnique(3);

   binaryTree.InsertUnique(112);

   binaryTree.InsertUnique(7);

   //binaryTree.InsertUnique(1);

   binaryTree.InsertUnique(2);

   binaryTree.TraversePreorder();

   std::cout << binaryTree.IsBalanced();

   return 0;
}
