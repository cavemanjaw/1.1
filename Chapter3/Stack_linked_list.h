#ifndef STACK_LINKED_LIST
#define STACK_LINKED_LIST

template<typename T>
class StackNode
{
   //Correct that by befriending class or nesting it
   public:
   T data;
   StackNode<T>* prevNode;

   StackNode();
};

template<typename T>
StackNode<T>::StackNode() : prevNode(nullptr)
{
}

template<typename T>
class Stack
{
   public:
   Stack()
   T Pop();
   void Push(T elem);

   protected:

   private:
   StackNode<T>* top;
};

template<typename T>
Stack<T>::Stack() : top(nullptr)
{
}

template<typename T>
T Stack<T>::Pop()
{
   //You have to be careful with empty stack, what to do if you called Pop() on empty stack?
   StackNode<T> temp = *top;
   delete top;
   top = temp.prevNode;
   return temp.data;
}

template<typename T>
void Stack<T>::Push(T elem)
{
   StackNode<T>* temp = new StackNode<T>;
   temp->data = elem;
   temp->prevNode = top;
   top = temp;
}

#endif
