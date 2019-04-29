#pragma once

#include "Structure.h"
#include <QStringList>
#include <String>

class Calculator
{
public:
	Calculator();
	~Calculator();

	Token Tokenize(QString expr);
	void getRPN(Token* inputToken);
	//BinaryTree* Calculator::RPNtoBT(QString* RPN)
private:
	Stack* operatorStack;
	Queue* RPN;
	BinaryTree* bt;
};

