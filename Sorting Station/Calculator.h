#pragma once

#include "Structure.h"
#include <QStringList>
#include <String>
#include <vector>

#define isOperator(ch) (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^')
#define isDigit(ch) ((c >= '0') && (ch <= '9'))

class Calculator
{
public:
	Calculator();
	~Calculator();

	std::vector<Token> Tokenize(QString expr);
	void getRPN(std::vector <Token>& tokens);
	//BinaryTree* Calculator::RPNtoBT(QString* RPN)
private:
	Stack* operatorStack;
	Queue* RPN;
	BinaryTree* bt;
};

