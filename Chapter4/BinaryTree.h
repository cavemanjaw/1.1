#ifndef BINARY_TREE_H
#define BINARY_TREE_H

template <typename T>
class Node
{
   Node<T>* left;
   Node<T>* right;
   T value;
};

template <typename T>
class BinaryTree
{
   Node<T>* root;
};

template <typename T>
bool InsertUnique(T data)
{
   Node<T>* nodePtr = head;

   while (nodePtr != nullptr)
   {
      if (*nodePtr.data == data)
      {
         //The value is already in container
         return false;
      }
      if ((*nodePtr).left)->data < data)
      {
         //Value in left child is less than the value we want to put into container
         nodePtr = nodePtr->right;
      }
      else
      {
         //Value in right child is greater or equal to the parameter value
         nodePtr = nodePtr->left;
      }
   }
   //We have found nulltpr pointer, insert the value
   nodePtr = new Node<T>;
   nodePtr->data = data;
}

template <typename T>
bool IsBalanced()
{
   //Traverse the tree, keep track of max-depth and current depth-counter
   size_t maxDepth = 0;
   size_t currentDepth = 0;

   Node<T>* nodePtr = head;

   while (nodePtr)
   {
      //How to traverse the tree, chose an algorithm
   }
}

#endif // #ifndef BINARY_TREE_H
