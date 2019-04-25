#include "Structure.h"



Structure::Structure()
{
}

Structure::~Structure()
{
}

int Structure::getValue()
{
	return value;
}

/***********************************************************

************************************************************/

BinaryTree::BinaryTree()
{
}

BinaryTree::~BinaryTree()
{
}

void BinaryTree::addNode(BinaryTree * bt, int value)
{
	if (this != nullptr) {
		if (this->value > value) {
			if (this->right == nullptr) {
				right = new BinaryTree;
				right->value = value;
				right->left = nullptr;
				right->right = nullptr;
			}
			else {
				addNode(right, value);
			}
		}
		else {
			if (left == nullptr) {
				left = new BinaryTree;
				left->value = value;
				left->left = nullptr;
				left->right = nullptr;
			}
			else {
				addNode(left, value);
			}
		}
	}
}

BinaryTree* BinaryTree::findNode(BinaryTree * bt, int value)
{
	if (this == nullptr)
		return nullptr;
	if (this->value == value)
		return this;
	else if (this->value > value)
		return findNode(right, value);
	else
		return findNode(left, value);
}
void BinaryTree::printTree(BinaryTree * bt)
{
	std::cout << "Current BinaryTree:\n";
	if (this != nullptr)
	{
		if (left != nullptr)
			printTree(left);
		std::cout << value;
		if (right != nullptr)
			printTree(right);
	}
}

bool BinaryTree::isNumber(BinaryTree* bt)
{
	if (left == nullptr && right == nullptr)
		return true;
	else
		return false;
}



/***********************************************************

************************************************************/

Queue::Queue()
{
}

Queue::~Queue()
{
}

void Queue::enqueue(int value)
{
	Node* node = new Node;
	node->next = last;
	node->value = value;
	last = node;
}

void Queue::dequeue()
{	
	--size;
	delete first;
}

int Queue::peek()
{
	return first->value;
}

unsigned Queue::currentSize()
{
	return size;
}

void Queue::printQueue()
{
	std::cout << "Current Queue = ";
	if (last == nullptr && first == nullptr)
		std::cout << "\0\n";
	else
	{
		while (last->next != first)
			std::cout << value << " ";
		std::cout << std::endl;
	}
}

/***********************************************************

************************************************************/

Stack::Stack()
{
}

Stack::~Stack()
{
}

void Stack::push(Stack * stack, int value)
{
	if (top == nullptr) {
		top = new Node;
		top->value = value;
		top->next = nullptr;
		++capacity;
	}
	else {
		Node* newTop = new Node;
		newTop->value = value;
		newTop->next = top;
		top = newTop;
		++capacity;
	}	
}

int Stack::pop(Stack * stack)
{
	if (top != nullptr) 
	{
		Node * newTop = top->next;
		int result = top->value;
		delete top;
		top = newTop;
		--capacity;
		return result;
	}
	else
		return 0;
}

int Stack::getTop(Stack * stack)
{
	if (top != nullptr)
	{
		return top->value;
	}
	else	
		return 0;
	
}

void Stack::printStack()
{
	std::cout << "Current Stack:\n";
	if (top == nullptr)
		std::cout << "\0\n";
	else
	{
		unsigned buf = capacity;
		while (buf != 0)
		{
			std::cout << value << "\n";
			top->next;
		}
	}
}

/***********************************************************

************************************************************/

Node::Node()
{
}

Node::~Node()
{
}

/***********************************************************

************************************************************/