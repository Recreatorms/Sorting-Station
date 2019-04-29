#include "Structure.h"


Token::Token()
{
}

Token::~Token()
{
}

int Token::getPriority()
{
	if (value == "^") {
		return 9;
	}
	if (value == "~") { // unary negation (right-associative)
		return 9;
	}
	if (value == "*") {
		return 8;
	}
	if (value == "/") {
		return 8;
	}
	if (value == "%") {
		return 8;
	}
	if (value == "+") {
		return 6;
	}
	if (value == "-") {
		return 6;
	}
	if (value == "(") {
		return -1;
	}
	if (value == ")") {
		return 10;
	}
	return 0;
}

/***********************************************************

************************************************************/

BinaryTree::BinaryTree()
{
	left = nullptr;
	right = nullptr;
}

BinaryTree::~BinaryTree()
{
	delete left;
	delete right;
}

void BinaryTree::addNode(BinaryTree * bt, QString value)
{
	if (this != nullptr) {
		if (this->value >= value) {
			if (right == nullptr) {
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
	else {
		bt = new BinaryTree;
		bt->value = value;
	}
}

BinaryTree* BinaryTree::findNode(BinaryTree * bt, QString value)
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
	first = nullptr;
	last = nullptr;
	size = 0;
}

Queue::~Queue()
{
	delete first;
	delete last;
}

void Queue::enqueue(Token token)
{
	if (first == nullptr) 
	{
		first = new NodeQueue;
		first->token = token;
		first->next = nullptr;
		last = first;
		++size;
	}
	else 
	{
		NodeQueue* newNode = new NodeQueue;
		newNode->next = last;
		newNode->token = token;
		last = newNode;
		++size;
	}
}

void Queue::dequeue()
{	
	--size;
	NodeQueue* node = last->next;
	while (node->next != first)
	{
		node = last->next;	
	}
		delete first;
		NodeQueue* newFirst;
		newFirst = node;		
		first = newFirst;		
}

QString Queue::peek()
{
	if (first != nullptr) {
		return first->token.value;
	}
}

unsigned Queue::currentSize()
{
	return size;
}

/***********************************************************

************************************************************/

Stack::Stack()
{
	top = nullptr;
	capacity = 0;
}

Stack::~Stack()
{
	delete top;
}

void Stack::push(Token value)
{
	if (top == nullptr) {
		top = new NodeStack;
		top->token = value;
		top->next = nullptr;
		++capacity;
	}
	else {
		NodeStack* newTop = new NodeStack;
		newTop->token = value;
		newTop->next = top;
		top = newTop;
		++capacity;
	}	
}

void Stack::pop()
{
	if (top != nullptr)
	{
		NodeStack* newTop = top->next;
		delete top;
		top = newTop;
		--capacity;
	}		
}

Token Stack::getTop()
{
	if (top != nullptr)
	{
		return operatorToken;
	}	
}

/***********************************************************

************************************************************/

NodeStack::NodeStack()
{
}

NodeStack::~NodeStack()
{
}

/***********************************************************

************************************************************/

NodeQueue::NodeQueue()
{
}

NodeQueue::~NodeQueue()
{
}
