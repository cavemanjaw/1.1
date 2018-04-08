#include "BinaryTree.h"
#include <cassert>

int main()
{

   //Used because assert() is a macro?
   bool result;

   //Create a instantiation of class template and an object of created type
   BinaryTree<int> binaryTree;
   binaryTree.InsertUnique(5);
   binaryTree.InsertUnique(56);
   binaryTree.InsertUnique(4);
   binaryTree.InsertUnique(3);
   binaryTree.InsertUnique(2);
   //Dynamic assert that the node is unbalanced
   result = binaryTree.IsBalanced();
   assert(result == false);

   BinaryTree<int> secondBinaryTree;
   secondBinaryTree.InsertUnique(30);
   secondBinaryTree.InsertUnique(17);
   secondBinaryTree.InsertUnique(15);
   secondBinaryTree.InsertUnique(18);
   secondBinaryTree.InsertUnique(58);
   //Dynamic assert that the node is balanced
   result = secondBinaryTree.IsBalanced()
   assert(result == true);

}
