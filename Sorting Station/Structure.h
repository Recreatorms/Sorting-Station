#pragma once
#include <iostream>
class Structure
{
public:
	Structure();
	~Structure();
	
	int getValue();
	int value;	
};

class Node : public Structure {
public:
	Node();
	~Node();
	
	Node* next;
};
class BinaryTree : public Structure {
public:
	BinaryTree();
	~BinaryTree();

	void addNode(BinaryTree *bt, int value);
	BinaryTree* findNode(BinaryTree* bt, int value);
	void printTree(BinaryTree* bt);
	bool isNumber(BinaryTree * bt);

	BinaryTree *left;
	BinaryTree *right;
};

class Queue : public Structure {
public:
	Queue();
	~Queue();

	void enqueue(int value);
	void dequeue();
	int peek();
	unsigned currentSize();
	void printQueue();

	unsigned size;
	Node* first;
	Node* last;
};



class Stack : public Structure {
public:
	Stack();
	~Stack();

	void push(Stack* stack, int value);
	int pop(Stack* stack);
	int getTop(Stack* stack);
	void printStack();
	unsigned capacity;
	Node* top;
};
