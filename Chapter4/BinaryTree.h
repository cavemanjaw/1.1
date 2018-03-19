#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>

template <typename T>
class Node
{
   public:
   Node();
   Node<T>* left;
   Node<T>* right;
   T value;
};

template <typename T>
Node<T>::Node():
   left(nullptr),
   right(nullptr)
{
}

template <typename T>
class BinaryTree
{
   public:
   BinaryTree();
   Node<T>* root;
   bool InsertUnique(T value);
   void TraversePreorder();
   void TraversePreorder(Node<T>* nodePtr);
   bool& TraversePreorderAndCheck(Node<T>* nodePtr, bool& isTrue, int& currentDepth, int& maxDepth);
   bool IsBalanced(Node<T>* nodePtr);
   bool IsBalanced();
};

template <typename T>
BinaryTree<T>::BinaryTree():
   root(nullptr)
{

}

template <typename T>
bool BinaryTree<T>::InsertUnique(T value)
{
   Node<T>** nodePtr = &root;

   while (*nodePtr != nullptr)
   {
      if ((*nodePtr)->value == value)
      {
         //The value is already in container
         return false;
      }
      if ((*nodePtr)->left != nullptr && ((*nodePtr)->left)->value < value )
      {
         //Value in left child is less than the value we want to put into container
         nodePtr = &((*nodePtr)->right);
      }
      else
      {
         //Value in right child is greater or equal to the parameter value
         nodePtr = &((*nodePtr)->left);
      }
   }
   //We have found nulltpr pointer, insert the value
   (*nodePtr) = new Node<T>;
   (*nodePtr)->value = value;
}

//template <typename T>
//bool IsBalanced()
//{
//   //Traverse the tree, keep track of max-depth and current depth-counter
//   size_t maxDepth = 0;
//   size_t currentDepth = 0;
//
//   Node<T>* nodePtr = root;
//
//   while (nodePtr)
//   {
//      //How to traverse the tree, chose an algorithm
//   }
//}
//
//


//Must have an overload to do that
template <typename T>
void BinaryTree<T>::TraversePreorder()
{
   TraversePreorder(root);
}


template <typename T>
void BinaryTree<T>::TraversePreorder(Node<T>* nodePtr)
{
  if (nodePtr == nullptr)
  {
     return;
  }

  std::cout << nodePtr->value << std::endl;

  TraversePreorder(nodePtr->left);

  TraversePreorder(nodePtr->right);
}


//In-out parameter of universal meaning for generic "check"
//Generic interface, but the implementation is not so generic xD
//So heavy increasyng the stack for recursing calls!!!
//
//How to make this unwind the stack at the earliest possible moment?
template <typename T>
bool& BinaryTree<T>::TraversePreorderAndCheck(Node<T>* nodePtr, bool& isTrue, int& currentDepth, int& maxDepth)
{

   //Just return, we already know that this tree is unbalanced, start inwinding the stack at the earliest possible moment
   if (isTrue == false)
   {
      return isTrue;
   }

   if (nodePtr == nullptr)
   {
      //Check if we have hit the nullptr for first time
      if (maxDepth == 0)
      {
         maxDepth = currentDepth;
      }

      //If the depth between branches differs by more than one count
      if (maxDepth - currentDepth > 1 || maxDepth - currentDepth < -1)
      {
        isTrue = false;
      }

      return isTrue;
   }

   //Do stuff
   ++currentDepth;

   TraversePreorderAndCheck(nodePtr->left, isTrue, currentDepth, maxDepth);

   TraversePreorderAndCheck(nodePtr->right, isTrue, currentDepth, maxDepth);

   //Here we just unwind the stack, as traversed left and right, go to the calee
   --currentDepth;
   return isTrue;
}

/*
 * General comment -  we can pass custom function to Traverse type of functions and modify their behaviour by that
 */

//How can we pass more work to this function, and try to eliminate arguments for the function TraversePreorderAndCheck?
template <typename T>
bool BinaryTree<T>::IsBalanced(Node<T>* nodePtr)
{
   int currentDepth = 0;
   int maxDepth = 0;

   bool isBalanced = true;

   TraversePreorderAndCheck(nodePtr, isBalanced, currentDepth, maxDepth);

   return isBalanced;
}

template <typename T>
bool BinaryTree<T>::IsBalanced()
{
   IsBalanced(root);
}

//Function must return immediately if tree is not balanced
//Function must return a value indicating if tree is balanced
//Minimize use of static functions
//If initializing this static variable to false, than there  future calling will be invalidated, value will be hold
//Best solution, I think is to traverse with separate function and have a pointer to bool, so it will return to calee
//WIll this work? We still might lose this, as the recursion goes deeper?

//Return values of function calls that will be on top of stack does not matter, only the last is being stored
//template <typename T>
//bool IsBalanced(Node<T>* nodePtr = root)
//{
//   //root, left, right order
//
//   Node<T>* nodePtr = root;
//
//   //Should be static, so we would refer to the same variable at every function call
//   //And this static is also initialized to zero, guaranteed by the standard
//   static unsigned depth;
//   static unsigned maxDepth;
//   static bool isBalanced = ;
//
//   if (nodePtr == nullptr)
//   {
//      
//      if (maxDepth == 0)
//      {
//         maxDepth == depth;
//      }
//
//      maxDepth = (depth > maxDepth) ? depth : maxDepth;
//
//      if (maxDepth - depth > 1)
//      {
//         isBalanced = false;
//      }
//      //Here store the depth as here it will be max value, we are on leaf now!
//      //Dumb solution, but one can store the value of depth for every time his place is visited and then see if the max-min > 1
//      return isBalanced;
//   }
//
//   ++depth;
//   //Take some action here!
//   
//   TraverseTreePreOrder(root->left);
//
//   TraverseTreePreOrder(root->right);
//
//   //If this function returnes normally we should substract one?
//   --depth;
//
//   return isBalanced;
//}

#endif // #ifndef BINARY_TREE_H
