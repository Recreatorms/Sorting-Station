#pragma once
#include <iostream>
#include <QString>

class Token
{
public:
	Token();
	~Token();

	int getPriority();

	QString value;

private:
	int priority;
};

class NodeQueue {
public:
	NodeQueue();
	~NodeQueue();

	NodeQueue* next;
	Token token;
};

class NodeStack {
public:
	NodeStack();
	~NodeStack();

	NodeStack* next;
	Token token;
};

class BinaryTree {
public:
	BinaryTree();
	~BinaryTree();

	void addNode(BinaryTree *bt, QString value);
	BinaryTree* findNode(BinaryTree* bt, QString value);

	bool isNumber(BinaryTree * bt);

	QString value;
	BinaryTree* left;
	BinaryTree* right;
};

class Queue {
public:
	Queue();
	~Queue();

	void enqueue(Token token);
	void dequeue();
	QString peek();
	unsigned int currentSize();

	unsigned int size;
	NodeQueue* first;
	NodeQueue* last;
};



class Stack {
public:
	Stack();
	~Stack();

	void push(Token value);
	void pop();
	Token getTop();

	Token operatorToken;
	unsigned int capacity;
	NodeStack* top;
};

