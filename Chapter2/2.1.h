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
      while (*nodePtr)
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
            nodePtr = &(*nodePtr)->next;
         }
      }
   }
   void RemoveDuplicatesWithoutBuffer()
   {
      Node<T>** outerLoopNodePtr = &head;
      Node<T>** innerLoopNodePtr = &(*head)->next;
      Node<T>** innerLoopNodePtrPrev = &head;

      while (*outerLoopPtr)
      {
         while (*innerLoopNodePtr)
         {
            if ((*outerLoopPtr)->data == (*innerLoopPtr)->data)
            {
               Node<T>* nodeToRemove = *innerLoopPtr;
               (*innerLoopNodePtrPrev)->next = (*innerLoopPtr)->next;
               innerLoopPtr = &(*innerLoopPtr)->next;
               delete nodeToRemove;
            }
            else
            {
               innerLoopNodePtrPrev = innerLoopNodePtr;
               innerLoopNodePtr = &(*innerLoopNodePtr)->next;
            }
         }
         
         outerLoopNodePtr = &(*outerLoopNodePtr)->next;
      }
   }

   void Insert()
   {
      Node<T>** nodePtr = &head;

      while (true)
      {
         if (*nodePtr == nullptr)
         {
            *nodePtr = new Node<T>;
            break;
         }
      }
   }

};

#endif //ifndef 2_1_H
