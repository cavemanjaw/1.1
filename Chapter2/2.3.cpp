//Assuminng there is a 

template <typename T>
class List
{
	Node<T>* head;
};

template <typename T>
class Node
{
	T data;
	Node<T>* nextNode;
};

template <typename T>
void RemoveNode(Node<T>& nodeToRemove)
{
	if (nodeToRemove.nextNode != nullptr)
	{
		//Save the pointer to next node temporairly
		Node<T*> nodeToBeDeleted = nodeToRemove->nextNode;
		nodeToRemove.data = nodeToRemove->nextNode.data;
		nodeToRemove.nextNode = nodeToRemove->nextNode.nextNode;

		//delete the node after nodeToRemove
		delete nodeToBeDeleted;
		
	}
}
