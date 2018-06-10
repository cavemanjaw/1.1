#ifndef STACK_LINKED_LIST
#define STACK_LINKED_LIST

template<typename T>
class StackNode
{
   T data;
   T* prevNode;
}

template<typename T>
class Stack
{
   public:
   T Pop();
   void Push(T elem);

   protected:

   private:
   StackNode<T>* top;
}

template<typename T>
T Stack::Pop()
{
   StackNode temp = *top;
   delete top;
   top = temp.prevNode;
   return temp.data;
}

template<typename T>
void Stack::Push(T elem)
{
   StackNode<T>* temp = new StackNode<T>;
   temp->data = elem;
   temp->prevNode = top;
   top = temp;
}

#endif
