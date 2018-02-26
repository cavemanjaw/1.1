#ifndef 2_1_H
#define 2_1_h

#include <set>

template <typename T>
class Node
{
   public:
   T data;
   Node<T>* next;   
};

template <typename T>
class List
{
   Node<T>* head;

   public:
   void RemoveDuplicates()
   {
      std::set<T> seenValues;

      Node<T>** previousNode = nullptr;
      Node<T>** nodePtr = &head;
      while (nodePtr)
      {

         auto isInserted = seenValues.insert((*nodePtr)->data);

         if (!isInserted.second)
         {
            (*previousNode)->next = (*nodePtr)->next;
            Node<T>* nodeToRemove = *nodePtr;
            nodePtr = &(*nodePtr)->nextNode;
            delete *nodePtr
         }
         else
         {
            previouseNode = nodePtr;
            nodePtr = &(*nodePtr)->nextNode;
         }
      }
   }

};

#endif //ifndef 2_1_H
